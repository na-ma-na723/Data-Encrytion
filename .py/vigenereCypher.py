# VIGENERE CYPHER
def keyLength(key, msg):
    keyLength = len(key)
    for i in range(len(msg) - keyLength):
        key += key[i%keyLength]
    return key

def encrypt(msg, key):
    table = "abcdefghijklmnopqrstuvwxyz"
    res = "";
    for i in range( len(key)):
        a = ord(msg[i])
        b = ord(key[i])
        res += table[ ((a-97)+(b-97)) %26]
    return res;
    
def decrypt(cypher, key):
    table = "abcdefghijklmnopqrstuvwxyz"
    res = ""
    for i in range( len(key)):
        a = ord(cypher[i])
        b = ord(key[i])
        temp = a-b
        
        if( temp < 0):
            temp = 26 + temp
        res += (table[temp])
    return res

msg = input("Enter your message : ")
msg = msg.lower()
key = input("Enter your key : ")
key = keyLength(key, msg)
cyphertext = encrypt(msg, key)
ori = decrypt(cyphertext, key)

print("Cypher text : ", cyphertext)
print("origial message : ", ori)