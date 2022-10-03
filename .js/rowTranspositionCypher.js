function newPlainAndRow(plain, key) {
    let lp = plain.length, lk = key.length;
    if( !(lp%lk  == 0) ) {
        let ch = 90 - (lk-(lp%lk)-1)
        for(let i = 0; i< lk-(lp%lk); i++) {
            plain += chr(ch)
            ch+=1
        }
    }

    row = plain.length/key.length
    
    return [plain, row]
}

function mat(key, row, plain) {
    let res = []
    let ch = 0
    for(let i = 0; i < row; i++) {
        temp = []
        for(let j = 0; j < key.length; j++) {
            temp.push( plain[ch] )
            ch+=1
        }
        res.push(temp)
    }
    return res

}

function encrypt(msg, key) {

    m = {}
    for i,el in enumerate(key):
    m[el] = i
    
    res = ""
    
    for i in range(1, len(key)+1):
    for j in range(0, len(msg)):
    res += msg[j][m[i]]
    return res
}
    
function decrypt(cypher, key, row) {

    m = {}
    for i,el in enumerate(key):
    m[el] = i
    ch = 0 
    ori = [[0]*len(key) for i in range(row)]
    
    for(let i = 1; i < key.length+1; i++) {
        for(let j = 0; j < row; j++) {
            ori[j][m[i]] = cypher[ch];
            ch+=1;
        }
    }
            
    let res = "";
    
    for(let i = 0; i < ori.length; i++) {
        for(let j = 0; j < ori[0].length; j++) res += ori[i][j]
    }
    return res
}
        
    
    
   
key = [3, 4, 2, 1, 5, 6, 7]
plain = "ATTACKPOSTPONEDUNTILTWOAM"
plain = newPlainAndRow(plain, key)[0]
row = newPlainAndRow(plain, key)[1]
m = mat(key, row, plain)

cypher = encrypt(m,key)
originalMsg = decrypt(cypher, key, row)
print("CYPHER TEXT -> ",cypher,"\n","ORIGINAL TEXT -> ", originalMsg, sep="")






        