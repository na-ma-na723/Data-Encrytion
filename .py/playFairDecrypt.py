def mat(s):
    m = {}
    for i in s:
        if i not in m:
            if chr(105) in m or chr(106) in m:
                continue
            m[i] = 1

    for i in range(97, 123):
        if chr(i) not in m:
            if ((chr(105) in m) and (i == 106)) or ((chr(106) in m) and (i==105)):
                continue
            m[chr(i)] = 1
            
    k = list(m.keys())
    
    res = []
    index = 0
    
    for i in range(5):
        temp = []
        for j in range(5):
            if ord(k[index]) == 105 or ord(k[index]) == 106:
                temp.append("ij")
                index+=1
            else:    
                temp.append(k[index])
                index+=1
        print(temp)
        res.append(temp)
        
    return res
            
            
def encrypt(key, plain):
    m = {}
    for i in range(5):
        for j in range(5):
            m[key[i][j]] = [i,j]
            
    cypher = ""
    
    for i in range(0,len(plain), 2):
        if ord(plain[i]) == 105 or ord(plain[i]) == 106:
            frow = m[ "ij" ][0] 
            fcol = m[ "ij" ][1]
            srow = m[ plain[i+1] ][0] 
            scol = m[ plain[i+1] ][1]
        elif ord(plain[i+1]) == 105 or ord(plain[i+1]) == 106:
            frow = m[ plain[i] ][0] 
            fcol = m[ plain[i] ][1]
            srow = m[ "ij" ][0] 
            scol = m[ "ij" ][1]
        else:
            frow = m[ plain[i] ][0] 
            fcol = m[ plain[i] ][1]
            srow = m[ plain[i+1] ][0] 
            scol = m[ plain[i+1] ][1]
        
        if frow == srow:
            cypher += ( key[frow][(fcol+1)%5][0] + key[srow][(scol+1)%5][0]  )
            # print( key[frow][(fcol+1)%5][0] + key[srow][(scol+1)%5][0]  )
        elif fcol == scol:
            cypher += ( key[(frow+1)%5][fcol][0] + key[(srow+1)%5][scol][0]  )
            # print( key[(frow+1)%5][fcol][0] + key[(srow+1)%5][scol][0]  )
        else:
            cypher += ( key[frow][scol][0] + key[srow][fcol][0]  )
            # print( key[frow][scol][0] + key[srow][fcol][0]  )
        
        # print(plain[i],"->",frow,",", fcol,",",plain[i+1],"->", srow,",", scol)
        
    return cypher

def decrypt(key, cypher):
    m = {}
    for i in range(5):
        for j in range(5):
            m[key[i][j]] = [i,j]
            
    plain = ""
    
    for i in range(0,len(cypher), 2):
        if ord(cypher[i]) == 105 or ord(cypher[i]) == 106:
            frow = m[ "ij" ][0] 
            fcol = m[ "ij" ][1]
            srow = m[ cypher[i+1] ][0] 
            scol = m[ cypher[i+1] ][1]
        elif ord(cypher[i+1]) == 105 or ord(cypher[i+1]) == 106:
            frow = m[ cypher[i] ][0] 
            fcol = m[ cypher[i] ][1]
            srow = m[ "ij" ][0] 
            scol = m[ "ij" ][1]
        else:
            frow = m[ cypher[i] ][0] 
            fcol = m[ cypher[i] ][1]
            srow = m[ cypher[i+1] ][0] 
            scol = m[ cypher[i+1] ][1]
        
        if frow == srow:
            plain += ( key[frow][(fcol-1)][0] + key[srow][(scol-1)][0]  )
            # print( key[frow][(fcol-1)][0] + key[srow][(scol-1)][0]  )
        elif fcol == scol:
            plain += ( key[(frow-1)][fcol][0] + key[(srow-1)][scol][0]  )
            # print( key[(frow-1)][fcol][0] + key[(srow-1)][scol][0]  )
        else:
            plain += ( key[frow][scol][0] + key[srow][fcol][0]  )
            # print( key[frow][scol][0] + key[srow][fcol][0]  )
        
        # print(cypher[i],"->",frow,",", fcol,",",cypher[i+1],"->", srow,",", scol)
        
    return plain


plain = "abhaykalez"
key = "monarchy"

m = mat(key)
# print(m)
cypher = encrypt(m, plain)
print("Cypher text after conversion -> ",cypher)

msg = decrypt(m, cypher)
print("Original text(converted from cypher text -> ",msg)





