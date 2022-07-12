#include <stdio.h>
#include <stdlib.h>

int cip (long long n){
	int count = 0;
	
	for(n; n > 0; n /= 10){
		n % 10;
		count++;
	}
	
	return count;
}

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int* answer = (int*)malloc(4*(cip(n) + 1));
    int count = 0;
    
    for(n; n > 0; n /= 10){
    	answer[count] = n % 10;
    	count++;
	}

    return answer;
}

int main () {
	long long n = 0;
	int count = 0;
	int* answer;
	
	scanf("%d", &n);
	
	answer = solution(n);
	
	for(count = 0; count < cip(n); count++){
		printf("%d", answer[count]);
	}

}
