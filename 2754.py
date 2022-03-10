s = input()
g = 0.0

if s[0] =='A':
    g += 4
elif s[0] =='B':
    g += 3
elif s[0] =='C':
    g += 2
elif s[0] =='D':
    g += 1

if s =='F':
    g = 0
elif s[1] =='+':
    g += 0.3
elif s[1] =='-':
    g -= 0.3

print(float(g))