#include <stdio.h>
#include <stdbool.h>

bool solution(int x) {
    bool answer = true;
    int count, sum = 0;
    
    for(count = x; count > 0; count /= 10){
    	sum += count%10;
	}
	
	if(x % sum != 0){
		answer = !answer;
	}
    
    return answer;
}

int main (){
	int x;
	
	scanf("%d", &x);
	
	if(!solution(x)){
		printf("false");
	}
	
	else
		printf("true");
	
	return 0;
}
