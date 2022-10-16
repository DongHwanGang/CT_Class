#include <stdio.h>

void immigration (int* times, int* choice_times,int n, int judge){
	int im_gate, cmp_num, save_idx, tmp_low, before_num, low_num = 0;
	long long sum_time = 0;
	
	before_num = -1;
	
	for(im_gate = 0; im_gate < n; im_gate++){
		tmp_low = choice_times[0];
		for(cmp_num = 0; cmp_num < judge; cmp_num++){
			if(before_num != cmp_num){
				choice_times[cmp_num] = choice_times[cmp_num] - low_num;
			} //spare time
			
			if(choice_times[cmp_num] < tmp_low){
				save_idx = cmp_num;
			} // the smallest amount of time
		}
		
		sum_time = sum_time + choice_times[save_idx];
		low_num = choice_times[save_idx];
		choice_times[save_idx] = times[save_idx];
		before_num = save_idx;
	} 
	
	printf("%lld", sum_time);
}

void input_norm(int* norm, int* norm2, int size){
	int row;
	
	for(row = 0; row < size; row++){
		scanf("%d", &norm[row]);
		norm2[row] = norm[row];
	}
}

int main () {
	int times[100000] = {0};
	int choice_times[100000] = {0};
	int n, judge;
	
	scanf("%d %d", &n, &judge);
	input_norm(times, choice_times, judge);
	immigration (times, choice_times, n, judge);
	
}
