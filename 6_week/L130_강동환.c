#include <stdio.h>
// numbers_len�� �迭 numbers�� �����Դϴ�.
int solution(int numbers[], size_t numbers_len) {
    int count, answer = 0;
    int number09[10] = {0};
    
    for(count = 0; count < numbers_len; count++){
    	number09[numbers[count]] += 1; 
	}
	
	for(count = 0; count < 10; count++){
		answer += number09[count] == 0 ? count : 0;
	}
    
    return answer;
}

int main (void) {
	int numbers[8] = {1, 2, 3, 4, 6, 7, 8, 0};
	size_t numbers_len = 8;
	
	printf("%d", solution(numbers, numbers_len));
}
