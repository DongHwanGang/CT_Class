#include <stdio.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int count, low_count = 0;
    char tep_word;
	char* answer;
	
	for(count = 0; s[count] != '\0'; count++){
	}
	
	answer = (char*)malloc(count + 1);
	answer[count] = '\0';
	
	for(count = 0; s[count] != '\0'; count++){
		answer[count] = s[count];	
	}
	
	for(low_count = 0; answer[low_count] != '\0'; low_count++){
		for(count = 0; answer[count + 1] != '\0'; count++){
			if(answer[count] < answer[count + 1]){
				tep_word = answer[count];
				answer[count] = answer[count + 1];
				answer[count + 1] = tep_word;
			}
		}
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
