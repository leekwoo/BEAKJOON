number = int(input())
result = []
while number != 1:
    for i in range(2, number + 1):
        if number % i == 0:
            result.append(i)
            number = number // i
            break

for i in result:
    print(i)