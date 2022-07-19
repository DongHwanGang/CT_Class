#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer;
    char copy_word[500] = "";
    int count, copy_count, answer_count, blank_count = 0;
    count = copy_count = answer_count = blank_count = 0; 
	
	for(count = 0; s[count] != '\0'; count++){
	}
	
	answer = (char*)malloc(count + 1);
	
    for(count = 0; s[count] != '\0'; count++){
		if(s[count] >= ' '){
			copy_word[count - blank_count] = s[count];
//			printf("%c ", copy_word[count - blank_count]);
		}
	
		if(s[count] == ' ' || s[count + 1] == '\0'){
			for(copy_count = 0; copy_word[copy_count] != '\0'; copy_count++){				
				if(copy_count % 2 == 0 && copy_word[copy_count] >= 'Z'){
					answer[copy_count + blank_count] = copy_word[copy_count] - 32;
				}
				
				else if(copy_count % 2 != 0){
					answer[copy_count + blank_count] = copy_word[copy_count];
				}
				blank_count = count + 1;
				printf("%d ", copy_count);
				
			}
//			printf("%c ", answer[copy_count + blank_count]);
			
			for(copy_count = 0; copy_word[copy_count] != '\0'; copy_count++){
				copy_word[copy_count] = '\0'; 
			}
		}
		printf("%c ", answer[count]);
	} 
	
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
