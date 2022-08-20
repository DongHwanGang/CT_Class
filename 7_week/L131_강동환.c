#include <stdio.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int numbers_count, copy_count, check, row_count, col_count, null_count, answer = 0;
    char numbers[][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char numbers_copy[6] = "";
    copy_count = 0;
    
    for(numbers_count = 0; s[numbers_count] != '\0'; numbers_count++){
    	if(s[numbers_count] >= '0' && s[numbers_count] <= '9'){
    		answer = answer* 10 + s[numbers_count] - '0'; 
		}
		else{
			check = answer;
			numbers_copy[copy_count] = s[numbers_count];
			
			if(copy_count > 1){
				for(row_count = 0; row_count < 10 ; row_count++){
					for(col_count = 0; numbers[row_count][col_count] != '\0'; col_count++){
						if(numbers_copy[col_count] != numbers[row_count][col_count]){
							break;
						}
					}
					if(numbers_copy[copy_count + 1] == '\0' && numbers[row_count][col_count] == '\0'){
						answer = answer * 10 + row_count;
						copy_count = 0;
						for(null_count = 0; numbers_copy[null_count] != '\0'; null_count++){
							numbers_copy[null_count] = '\0';
						}
						break; 
					}
				}	
			}
			
			if(check == answer){
				copy_count++;
			}
		}
	}
    return answer;
}

int main (){
	char s[50] = "";
	
	printf("Enter a string: ");
	gets(s);
	
	printf("결과:" " %d", solution(s));
	
	return 0;
}
