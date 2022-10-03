def arrToString(cypher):
    s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    res= ""
    for i in cypher:
        res += s[i]
    
    return res
    
def keyMatrix(key, n):
    res = [[0]*n for i in range(n)]
    ch = 0
    for i in range(n):
        for j in range(n):
            res[i][j] = (ord(key[ch]) - 65)
            ch += 1
    return res
 
def plainArr(plain):
    res = []
    for i in plain:
        res.append(ord(i)-65)
    return res

def encrypt(key, plain, n):
    res = []
    for i in range(0,n):
        temp = 0
        for j in range(0,n):
            temp += plain[j]*key[j][i]
        res.append(temp)  
    for i in range(n):
        res[i] %= 26
        
    res = arrToString(res)
    return res
    
def encrypt2(key, plain, n):
    res = []
    
    for i in range(n):
        temp = 0
        for j in range(n):
            temp += key[i][j] * plain[j]
        res.append(temp)
    
    for i in range(n):
        res[i] %= 26
        
    res = arrToString(res)
    return res





key = "GYBNQKURP"
plain = "ACT"

keyMat = keyMatrix(key, 3)
plainA = plainArr(plain)

cypher1 = encrypt(keyMat, plainA, len(plain))
cypher2 = encrypt2(keyMat, plainA, len(plain))
print("CYPHER TEXT 1 -> ",cypher1)
print("CYPHER TEXT 2 -> ",cypher2)













