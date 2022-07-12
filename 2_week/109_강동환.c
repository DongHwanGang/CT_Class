#include <stdio.h>
#include <stdlib.h>

char* solution(int num) {
    // 리턴할 값은 메모리를 동적 할당해주세요
    char* answer; 
    
    if(num % 2 == 0){
	    answer = (char*)malloc(6);   
		answer = "Even";
       
    }
    else{
    	answer = (char*)malloc(5);  
		answer = "Odd";
	}
    return answer;
}

int main (){
	int num = 0;
	char* answer;
	
	scanf("%d", &num);
	
	answer= solution(num);
	puts(answer);
	free(answer);
}
