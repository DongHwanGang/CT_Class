#include <stdio.h>
#include <stdbool.h>
// absolutes_len�� �迭 absolutes�� �����Դϴ�.
// signs_len�� �迭 signs�� �����Դϴ�.
int solution(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len) {
    int count, answer = 0;
    
    for(count = 0; count < signs_len; count++){
    	answer = signs[count] ? answer + absolutes[count] : answer - absolutes[count];
	}
	
    return answer;
}

int main (void){
	int absolutes[3] = {1, 2, 3};
	bool signs[3] = {false, false, true};
	size_t absolutes_len = 3;
	size_t signs_len = 3;
	
	printf("%d", solution(absolutes, absolutes_len, signs, signs_len));
	
}
