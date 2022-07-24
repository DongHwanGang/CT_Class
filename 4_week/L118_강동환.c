#include <stdio.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    int tep_num = 0;
    
    if(a > b){
    	tep_num = a;
    	a = b;
    	b = tep_num;
	}
	
	for(a; a <= b; a++){
		answer += a;
	}
    
    return answer;
}

int main (){
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	printf("%d", solution(a, b));
}
