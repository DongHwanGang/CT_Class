#include <stdio.h>
#include <stdlib.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int* solution(const char* s) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(sizeof(int) * 2);
    int div_num, del_num, one_check, bin_num, one_num, zero_num;
    one_num = zero_num = bin_num = 0;
    
    for(one_check = 0; s[one_check] != '\0'; one_check++){
		if(s[one_check] - '0'){
			one_num++;
		}
		
		else{
			zero_num++;
		}
	}
	
    for(del_num = 0; ; ){
    	del_num++;
		if(one_num == 1){
			answer[0] = del_num;
	   		answer[1] = zero_num;
	   		printf("%d %d", answer[0], answer[1]);
	    	return answer;
		}
		
    	div_num = one_num;
    	for(one_num = 0; div_num > 0; div_num /= 2){
    		if(div_num % 2){
    			one_num++;
			}
			else{
				zero_num++;
			}
		}
	}
}

int main () {
	char s[13] = "1111111";
	
	solution(s);
}
