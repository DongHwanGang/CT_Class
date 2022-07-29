def solution(arr):
    answer = []
    min = arr[0]
    for i in range(len(arr)):
        min = arr[i] if min > arr[i] else min 

    arr.remove(min)

    for i in range(len(arr)):
        answer.append(arr[i])

    if(len(answer)==0):
        answer = [-1]

    return answer

print(solution([4,3,2,1]))