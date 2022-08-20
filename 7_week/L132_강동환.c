#include <stdio.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2*sizeof(int));
    int my_lottos_count, same_number_count, unknown_quantity = 0;
    int same_number = 0;
    
    for(my_lottos_count = 0; my_lottos_count < lottos_len; my_lottos_count++){ //Compare my lotto number and winning number
    	if(lottos[my_lottos_count] == 0){ //If my lotto number is cleared, increase the variable 'unknown_quantity'.
    		unknown_quantity++; 
			continue;
		}
    	for(same_number_count = 0; same_number_count < lottos_len; same_number_count++){
    		if(lottos[my_lottos_count] == win_nums[same_number_count]){
    			same_number++;
			}
		}
	}
	
	answer[0] = (same_number != 0 || unknown_quantity != 0) ? 7 - (unknown_quantity + same_number) : 6;
	answer[1] = (7 - same_number) > 5 ? 6 : (7 - same_number);
	
    return answer;
}

int main (void) {
	int lottos[6] = {0, 0, 0, 0, 0, 0};
	int wins_num[6] = {38, 19, 20, 40, 15, 25};
	size_t lottos_len = 6;
	size_t win_nums_len = 6;
	int* answer;
	int count;
	
	answer = solution(lottos, lottos_len, wins_num, win_nums_len);
	
	for(count = 0; count < 2; count++){
		printf("%d ", answer[count]);
	}
	
	free(answer);
}
