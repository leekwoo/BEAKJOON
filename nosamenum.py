def solution1(arr):
  result=[]
  result.append(arr[0])
  for i in range(1,len(arr)):
    if arr[i] != arr[i-1]:
      result.append(arr[i])
  return result
numbers=[1,2,2,2,3,3,3,3,4,4,4,4,5,5,6]
print(solution1(numbers))