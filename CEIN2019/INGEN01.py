T = int(input())
for t in range (T):
    k = int(input())
    s = input()
    s = s.replace (' ', '')
    k = k % 26
    for i in range (len (s)):
        d = 
        d = (d - k + 26) % 26
        s[i] = d + 'A'
    print (s)
