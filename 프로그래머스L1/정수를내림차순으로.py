def solution(n):
    answer = 0
    reversint = []
    for i in str(n):
        reversint.append(int(i))
    
    reversint.sort()
    reversint.reverse()

    for i in reversint:
        answer = answer*10 + i

    return answer

print(solution(118372))