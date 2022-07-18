#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    
    for(n; n > 0; n /= 10){
    	answer += n % 10; 
	}
    
	return answer;
}

int main (){
	int n = 0;
	
	scanf("%d", &n);
	
	printf("%d", solution(n));
}
