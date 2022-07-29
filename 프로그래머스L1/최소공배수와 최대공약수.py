def solution(n, m):
    answer = []
    temp = True if m < n else False

    if(temp):
        temp = n
        n = m
        m = temp
    
    temp_n = n
    temp_m = m

    while(False if temp_m % temp_n == 0 else True):
        temp = temp_n
        temp_n = temp_m % temp_n
        temp_m = temp

    answer.append(temp_n)
    answer.append(n*m/temp_n)
 
    return answer

print(solution(84,120))