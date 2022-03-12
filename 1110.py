num=input()
n=int(num)
cycle=0
while True:
  a=n//10
  b=n%10
  c=(a+b)%10
  n=(b*10)+c

  cycle+=1
  if(int(num)==n):
    break
print(cycle)
