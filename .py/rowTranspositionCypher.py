def newPlainAndRow(plain, key):
    lp = len(plain)
    lk = len(key)
    if not(lp%lk  == 0):
        ch = 90 - (lk-(lp%lk)-1)
        for i in range(lk-(lp%lk)):
            plain += chr(ch)
            ch+=1

    row = len(plain)//len(key)
    
    return [plain, row]

def mat(key, row, plain):
    res = []
    ch = 0
    for i in range(row):
        temp = []
        for j in range(len(key)):
            temp.append( plain[ch] )
            ch+=1
        res.append(temp)
    return res

def encrypt(msg, key):
    m = {}
    for i,el in enumerate(key):
        m[el] = i
        
    res = ""
    
    for i in range(1, len(key)+1):
        for j in range(0, len(msg)):
            res += msg[j][m[i]]
    return res
    
def decrypt(cypher, key, row):
    m = {}
    for i,el in enumerate(key):
        m[el] = i
    ch = 0 
    ori = [[0]*len(key) for i in range(row)]
    
    for i in range(1, len(key)+1):
        
        for j in range(0, row):
            ori[j][m[i]] = cypher[ch]
            ch+=1
            
    res = ""
    
    for i in range(len(ori)):
        for j in range(len(ori[0])):
            res += ori[i][j]
    return res
            
    
    

if __name__ == '__main__':    
    key = [3, 4, 2, 1, 5, 6, 7]
    plain = "ATTACKPOSTPONEDUNTILTWOAM"
    plain = newPlainAndRow(plain, key)[0]
    row = newPlainAndRow(plain, key)[1]
    m = mat(key, row, plain)

    cypher = encrypt(m,key)
    originalMsg = decrypt(cypher, key, row)
    print("CYPHER TEXT -> ",cypher,"\n","ORIGINAL TEXT -> ", originalMsg, sep="")






        