#include <stdio.h>
#include <stdlib.h>
// numbers_len�� �迭 numbers�� �����Դϴ�.
int* solution(int numbers[], size_t numbers_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer;
    int natual_number[201] = {0};
	int count, ascending_count, temp;
    
	for(count = 0; count < numbers_len; count++){
		for(ascending_count = count + 1; ascending_count < numbers_len; ascending_count++){
			temp = numbers[count] + numbers[ascending_count];
			natual_number[temp] += 1;
		}	
	}
	
	ascending_count = temp = 0;
	
	for(count = 0; count < 201; count++){
		if(natual_number[count] != 0){
			ascending_count++;
			temp = count;
		}
	}

	answer = (int*)malloc(ascending_count*sizeof(int));
	ascending_count = temp + 1;
	temp = 0;
	
	for(count = 0; count < ascending_count; count++){
		if(natual_number[count] != 0){
			answer[temp] = count;
			temp++;
		}
	}
		
    return answer;
}

int main (void){
	int numbers[5] = {2,1,3,4,1};
	size_t numbers_len = 5;
	int count;
	int* answer; 
	
	answer = solution(numbers, numbers_len);
	
	for(count = 0; count < 6; count++){
		printf("%d ", answer[count]);
	}
	free(answer);
}
