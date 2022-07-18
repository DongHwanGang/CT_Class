#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int count = 0;
    char* answer = (char*)malloc((2*n)+1);
    char tmp_water[20001] = "";
    
    for(count = 0; count < n; count++){
    	*(tmp_water + count) = "수"; 
    	printf("%c", tmp_water);
	}
	
    return answer;
}

int main () {
	int n;
	
	scanf("%d", &n);
	
	puts(solution(n));
}
