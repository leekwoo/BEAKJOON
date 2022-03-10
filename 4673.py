def selfNumber(num):
    selfNum = num
    while num != 0:
        selfNum += num%10
        num //= 10
    return selfNum
        
result = []

for i in list(range(1,10001)):
    result.append(selfNumber(i))
    if i not in result:
        print(i)