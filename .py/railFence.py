s = "CHAOTICMAP"
n = 2
res = ""
for i in range(0,n):
    for j in range(i, len(s), n):
        res += s[j]
        
print(len(s))
print(res)
m = res
print(m)


