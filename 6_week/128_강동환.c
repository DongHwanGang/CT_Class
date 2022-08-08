#include <stdio.h>
// a_len은 배열 a의 길이입니다.
// b_len은 배열 b의 길이입니다.
int solution(int a[], size_t a_len, int b[], size_t b_len) {
    int count, answer = 0;
    
    for(count = 0; count < a_len; count++){
    	answer = (a[count]*b[count]) + answer;
	}
    
    return answer;
}

int main (void) {
	int a[4] = {1, 2, 3, 4};
	int b[4] = {-3, -1, 0, 2};
	size_t a_len = 4;
	size_t b_len = 4;
	
	printf("%d", solution(a, a_len, b, b_len));
	
}
