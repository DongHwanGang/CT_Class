#include <stdio.h>

// info_len은 배열 info의 길이입니다.
// edges_rows는 2차원 배열 edges의 행 길이, edges_cols는 2차원 배열 edges의 열 길이입니다.
int solution(int info[], size_t info_len, int edges[11][2], size_t edges_rows, size_t edges_cols) {
    int temp_leef, temp_root, chase_ani_cols, chase_ani_rows, wolf, sheep, answer = 0;
    int check_num, temp_sheep, check_rows, return_rows, return_cols;
    int visited_loc[17] = {0};
    int check_loc[17] = {0};
    int floor[17][17] = {0};
    
    sheep = 1;

    for(chase_ani_rows = 0; chase_ani_rows < edges_rows; chase_ani_rows++){	
    	for(chase_ani_cols = 0; chase_ani_cols < edges_cols; chase_ani_cols++){
    		temp_root = edges[chase_ani_rows][0];
    		temp_leef = edges[chase_ani_rows][chase_ani_cols];
    		if(edges[chase_ani_rows][0] != edges[chase_ani_rows][chase_ani_cols]){
    			floor[temp_root][temp_leef] = edges[chase_ani_rows][chase_ani_cols];
    		}
    	}
	}
		
    for(chase_ani_rows = 0; chase_ani_rows < 17; chase_ani_rows++){
    	for(chase_ani_cols = 0; chase_ani_cols < 17; chase_ani_cols++){
    		printf("%d ", floor[chase_ani_rows][chase_ani_cols]);
    	}
    	printf("\n");
	}
    return answer;
}

int main (){
	int info[12] = {0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1};
	int edges[11][2] = {
		{0, 1},
		{1, 2},
		{1, 4},
		{0, 8},
		{8, 7},
		{9, 10},
		{9, 11},
		{4, 3},
		{6, 5},
		{4, 6},
		{8, 9}
	};
	
	printf("%d", solution(info, 12, edges, 11, 2));
}
