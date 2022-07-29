def solution(n):
    answer = 1
    
    while n > answer**2:
        answer+=1
          
    answer = answer + 1 if n == answer**2 else -1

    if(answer != -1):
        answer = answer**2

    return answer

print(solution(3))