#include <stdio.h>
#include <stdlib.h>
// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int first_count, second_count, third_count, sum, answer = 0;
    int sieve[2998] = {0};
    
	for(first_count = 2; first_count < 2998; first_count++){
		if(sieve[first_count] == 0){
			second_count = first_count;
			for(second_count += first_count; second_count < 2998; second_count += first_count){
				if(sieve[second_count] == 0){
					sieve[second_count] = 1;
				} 	
			}
		}
	}
	
    for(first_count = 0; first_count + 2 < nums_len; first_count++){
    	for(second_count = first_count + 1; second_count + 1 < nums_len; second_count++){
    		for(third_count = second_count + 1; third_count < nums_len; third_count++){
    			sum = nums[first_count] + nums[second_count] + nums[third_count];
    			answer += sieve[sum] != 0 ? 0 : 1;
			}
		}
	}
	
    return answer;
}

int main (void) {
	int nums[5] = {1, 2, 7, 6, 4};
	size_t nums_len = 5;
	
	printf("%d", solution(nums, nums_len));
}
