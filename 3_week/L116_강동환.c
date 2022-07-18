#include <stdio.h>
#include <stdbool.h>

bool solution(const char* s) {
    bool answer = true;
    int count, srt_len;
    
	for(count = 0; s[count] != '\0'; count++){
	}
	
	if(count == 4 || count == 6){
		for(count = 0; s[count] != '\0'; count++){
			if(s[count] < '0' || s[count] > '9'){
				answer = !answer;
				break;
			}
		}
	}
	
	else{
		answer = !answer;
	}
		
    return answer;
}

int main (){
	char s[8] = "";
	
	gets(s);
	
	if(!solution(s)){
		printf("false");
	}
	else
		printf("true");
}
