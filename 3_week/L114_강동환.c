#include <stdio.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int count, answer = 0;
    
	for(count = 0; s[count] != '\0';count++){
		if('0' <= s[count] && '9' >= s[count]){
			answer = answer*10 + (s[count] - '0');
		}
	}
	
	if(s[0] == '+'){
		answer = +answer;
	}
	
	else if(s[0] == '-'){
		answer = -answer;
	}
	
    return answer;
}

int main (){
	char s[5] = "";
	
	gets(s);
	
	printf("%d", solution(s));
}
