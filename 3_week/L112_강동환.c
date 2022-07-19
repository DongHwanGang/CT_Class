#include <stdio.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer;
    int count, blank_count = 0;
    count = blank_count = 0; 
	
	for(count = 0; s[count] != '\0'; count++){
	}
	
	answer = (char*)malloc(count + 1);
	
    for(count = 0; s[count] != '\0'; count++){
		answer[count] = s[count];
		
		if(s[count - 1] == ' '){
			blank_count = count;
		}
		
		if(s[count] != ' '){
			if((count - blank_count) % 2 == 0){
				if(answer[count] >= 'a' && answer[count] <= 'z'){
					answer[count] = answer[count] - 32;
				}
			}
			
			else if((count - blank_count) % 2 != 0){
				if(answer[count] >= 'A' && answer[count] <= 'Z'){
					answer[count] = answer[count] + 32;
				}
			}
		}
	} 
	
	answer[count] = '\0';
	
    return answer;
}

int main () {
	
	char s[500] = "";
	char* answer;
	
	gets(s);
	answer = solution(s);
	puts(answer);
	free(answer);
}
