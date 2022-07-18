#include <stdio.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int count, answer = 0;
    
    if(s[0] == '+' || s[0] == '-'){
    	for(count = 1; s[count] != '\0';count++){
    		answer = answer*10 + (s[count] - 48);
    	}
    	if(s[0] == '+'){
    		answer = +answer;
		}
		else
			answer = -answer;
	}
	
	else
		for(count = 0; s[count] != '\0';count++){
    		answer = answer*10 + (s[count] - 48);
    	}
    
    return answer;
}

int main (){
	char s[5] = "";
	
	gets(s);
	
	printf("%d", solution(s));
}
