#include <stdio.h>

int solution(int n) {
    int pairDivisor, answer = 0;
    int divisor = 1;
    
    for(divisor = 1; divisor*divisor <= n; divisor++){
    	if(n % divisor == 0){
    		pairDivisor = n / divisor  ;
    		answer += pairDivisor;
    		if(pairDivisor != divisor){
    			answer += divisor;
			}
		}
	}
    
    return answer;
}

int main () {
	int n;
	
	scanf("%d", &n);
	
	printf("%d", solution(n));
	
}
