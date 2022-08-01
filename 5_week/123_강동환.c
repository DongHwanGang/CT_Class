#include <stdio.h>

int solution(int left, int right) {
    int pairDivisor, answer = 0;
    int divisor = 1;

    for(left; left <= right; left++){
    	int count = 0;
	    for(divisor = 1; divisor*divisor <= left; divisor++){
	    	if(left % divisor == 0){
	    		pairDivisor = left / divisor;
	    		count++;
	    		if(pairDivisor != divisor){
	    			count++;
				}
			}
		}
		answer = (count % 2 != 0) ? answer - left : answer + left;
	}
    
    return answer;
}

int main () {
	int left, right;
	
	scanf("%d %d", &left, &right);
	
	printf("%d", solution(left, right));
	
}
