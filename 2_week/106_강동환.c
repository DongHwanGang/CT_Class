#include <stdio.h>

// arr_len은 배열 arr의 길이입니다.
double solution(int arr[], size_t arr_len) {
    double answer = 0;
    int count = 0;
    
    for(count = 0; count < arr_len; count++){
        answer += arr[count];
    }
    
    answer /= arr_len;
    
    return answer;
}
