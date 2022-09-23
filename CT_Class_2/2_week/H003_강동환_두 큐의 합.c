#include <stdio.h>
#include <stdlib.h>

// queue1_len은 배열 queue1의 길이입니다.
// queue2_len은 배열 queue2의 길이입니다.
int solution(int queue1[], size_t queue1_len, int queue2[], size_t queue2_len) {
    long long total_num, check_num, rest_sum, rest_num, para_sum, sum_num, order_num, input_num, two_Qsum, calc_num, Q_sum, temp_answer,answer;
    int* Q1_Q2_para = (int*)malloc(queue1_len * 2 * sizeof(int));
    int* check_Q1 = (int*)malloc(queue1_len * sizeof(int));
    int* check_Q2 = (int*)malloc(queue1_len * sizeof(int));
    
    total_num = Q_sum = 0;
    temp_answer = -1;
    
    for(calc_num = 0; calc_num < queue1_len; calc_num++){
    	Q_sum += queue1[calc_num];
    	Q_sum += queue2[calc_num];
    	check_Q1[calc_num] = check_Q2[calc_num] = 0;
	}
    
    if(Q_sum % 2){
    	return -1;
	}
    
    two_Qsum = Q_sum / 2;
    
    for(input_num = 0; input_num < queue1_len; input_num++){
    	Q1_Q2_para[input_num] = queue1[input_num];
	}
	
	for(input_num = queue1_len; input_num < queue1_len * 2; input_num++){
		Q1_Q2_para[input_num] = queue2[input_num - queue1_len];
	}

	for(order_num = 0; order_num < queue1_len + 1; order_num++){
		for(calc_num = 0; calc_num < queue1_len * 2; calc_num++){
			for(sum_num = 0; sum_num < order_num + 1; sum_num++){
				if(calc_num + sum_num >= queue1_len * 2){
					para_sum += Q1_Q2_para[calc_num + sum_num - queue1_len * 2];
				}
				else{
					para_sum += Q1_Q2_para[calc_num + sum_num];
				}
				
			}
			
			if(para_sum == two_Qsum){
				if(calc_num + sum_num >= queue1_len * 2){
					for(rest_num = calc_num + sum_num - queue1_len * 2; rest_num < calc_num; rest_num++){
						rest_sum += Q1_Q2_para[rest_num];
					}
				}
				
				else{
					for(rest_num = 0; rest_num < calc_num; rest_num++){
						rest_sum += Q1_Q2_para[rest_num];
					}
					for(rest_num = calc_num + sum_num; rest_num < queue1_len * 2; rest_num++){
						rest_sum += Q1_Q2_para[rest_num];
					}
				}
			}
			
			if(rest_sum == two_Qsum && para_sum == two_Qsum){
				for(sum_num = 0; sum_num < order_num + 1; sum_num++){
					if(calc_num + sum_num >= queue1_len * 2){
						if(calc_num + sum_num - queue1_len * 2 < queue1_len){
							check_Q1[calc_num + sum_num - queue1_len * 2] = 1;
						}
						else{
							check_Q2[calc_num + sum_num - 2 * queue1_len] = 1;
						}
					}
					else{
						if(calc_num + sum_num < queue1_len){
							check_Q1[calc_num + sum_num] = 1;
						}
						else{
							check_Q2[calc_num + sum_num - queue1_len] = 1;
						}
					}
				}
				
				for(check_num = 0; check_num < queue1_len; check_num++){
		    		if(check_Q1[check_num] != check_Q1[0]){
		    			break;
					}
					total_num++;
				}
				
				if(check_Q1[0] != check_Q2[0]){
					for(check_num = 0; check_num < queue1_len; check_num++){
				    	if(check_Q2[check_num] != check_Q2[0]){
		    				break;
						}
						total_num++;
			    	}
				}
				
				else{
					for(check_num = 0; check_num < queue1_len; check_num++){
				    	if(check_Q2[check_num] == check_Q2[0]){
		    				total_num++;
						}
			    	}
				}
				
				for(check_num = 0; check_num < queue1_len; check_num++){
			    	check_Q1[check_num] = check_Q2[check_num] = 0;
				}
				
				if(temp_answer == -1){
					temp_answer = total_num;
				}
			
				else{
					temp_answer = total_num < temp_answer ? total_num : temp_answer;
				}
			}
			
			
			total_num = 0;
			para_sum = 0;
			rest_sum = 0;
		}
    }
    
    free(Q1_Q2_para);
    free(check_Q1);
    free(check_Q2);
    
    return answer = temp_answer;
}

int main () {
	int queue1[] = {1,1,1};
	int queue2[] = {5,1,1};
	
	
	printf("%d", solution(queue1, 6, queue2, 6));
}
