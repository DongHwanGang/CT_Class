#include <stdio.h>
#include <stdlib.h>

int* solution(int n, long long left, long long right) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * (right - left + 1));
    int** N_N = (int**)malloc(sizeof(int*) * n);
    int* N_one = (int*)malloc(sizeof(int) * n * n);
    long long N_cols, Grid_rows, Grid_cols, make_one, answer_move, answer_f, contract, whole;
    answer_f = make_one = contract = 0;
    
    for(N_cols = 0; N_cols < n; N_cols++){
    	N_N[N_cols] = (int*)malloc(sizeof(int) * n);
	}
		
	for(whole = 0; whole < n; whole++){
		for(Grid_rows = 0; Grid_rows < n - contract; Grid_rows++){
			for(Grid_cols = 0; Grid_cols < n - contract; Grid_cols++){
				N_N[Grid_rows][Grid_cols] = n - contract;
			}
		}
		contract++;
	}

	for(Grid_rows = 0; Grid_rows < n; Grid_rows++){
		for(Grid_cols = 0; Grid_cols < n; Grid_cols++){
			N_one[make_one] = N_N[Grid_rows][Grid_cols];
			if(make_one < n*n - 1){
				make_one++;
			}
		}
	}
	
	for(answer_move = left; answer_move < right + 1; answer_move++){
		answer[answer_f] = N_one[answer_move];
		if(answer_f < right - left){
			answer_f++;
		}
	}
    
    for(N_cols = 0; N_cols < n; N_cols++){
    	free(N_N[N_cols]);
	}
	

    free(N_N);
    free(N_one);
    return answer;
}

int main () {
	int n, left, right;
	int* answer;
	scanf("%d %d %d", &n, &left, &right);
	
	answer = solution(n, left, right);
	free(answer);
}
