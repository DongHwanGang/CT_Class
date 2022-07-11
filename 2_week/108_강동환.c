#include <stdio.h>

long long solution(long long n) {
    long long answer = 0;
    long long Division = 1;
    
    for( ; ; ){
    	answer = (n / Division);
    	
    	if(answer * answer == n){
    		answer = (answer + 1)*(answer + 1);
    		break;
		}
		
		else{
			Division++;
			if(Division > n){
				answer = -1;
				break;
			}
		}
	}
    return answer;
}

int main (){
	long long n;
	
	scanf("%d", &n);
	
	printf("%d", solution(n));
	
}
