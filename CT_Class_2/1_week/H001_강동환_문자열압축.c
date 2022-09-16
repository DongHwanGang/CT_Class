#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int solution(char* S){
	int check_num, str_num, null_num, sum_num, str_set, compare_copy_str, compare_str, copy_str, copy_num, divide_str, answer = 0;
	char* copy_s = (char*)malloc(strlen(S) + 1);
	char* sum_s = (char*)malloc(strlen(S) + 1);
	int* compression = (int*)malloc(4*strlen(S));
	
	str_num = sum_num = str_set = 0;
	
	for(null_num = 0; copy_s[null_num] != '\0'; null_num++){
		compression[null_num] = 0;
		copy_s[null_num] = '\0';
		sum_s[null_num] = '\0';
	}
	
	for(divide_str = 0; divide_str < strlen(S) / 2; divide_str++){
		sum_num = str_set = 0;
		for(null_num = 0; null_num < strlen(S) + 1; null_num++){
			copy_s[null_num] = '\0';
			sum_s[null_num] = '\0';
		}
		for(compare_str = 0; compare_str < strlen(S) + 1; compare_str){
			if(copy_s[compare_copy_str] == S[compare_str]){
				if(copy_s[compare_copy_str + 1] != '\0'){
					compare_copy_str++;
				}
				else{
					str_set += 1;
					compare_copy_str = 0;
				}
				compare_str++;
			}
			
			if(copy_s[compare_copy_str] != S[compare_str] || S[compare_str] == '\0'){
				if(S[compare_str] == '\0'){
					str_set += 1;
				}
				
				if(str_set > 1){
					sum_s[sum_num] = str_set + '0';
					sum_num++;
				}
				
				null_num = 0;
				for(sum_num; copy_s[null_num] != '\0'; sum_num++){
					sum_s[sum_num] = copy_s[null_num];
					null_num++;
				}
				str_set = 0;
				compare_str -= compare_copy_str;
				compare_copy_str = 0;
				copy_num = 0;
				for(copy_str = compare_str; copy_num < divide_str + 1; copy_str++){
					copy_s[copy_num] = S[copy_str];
					if(S[copy_str] == '\0'){
						break;
					}
					copy_num++;
				}
				
				if(S[copy_str] == '\0' && strlen(copy_s) < divide_str + 1){
					null_num = 0;
					for(sum_num; copy_s[null_num] != '\0'; sum_num++){
						sum_s[sum_num] = copy_s[null_num];
						null_num++;
					}
					break;
				}
			}
		}
		compression[divide_str] = strlen(sum_s);
	}
	
	answer = compression[0];
	for(check_num = 1; compression[check_num] != 0; check_num++){
		answer = compression[check_num] < answer ? compression[check_num] : answer;
	}
	
	free(copy_s);
	free(sum_s);
	free(compression);
	
	return answer;
}

int main (){
	char S[1001] = "";
	
	gets(S);
	printf("%d", solution(S));
}
