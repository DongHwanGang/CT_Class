#include <stdio.h>

// info_len?? ?עק info?? ????????.
// edges_rows?? 2???? ?עק edges?? ?? ????, edges_cols?? 2???? ?עק edges?? ?? ????????.
int solution(int info[], size_t info_len, int edges[11][2], size_t edges_rows, size_t edges_cols) {
    int temp_num, temp_leef, temp_root, chase_ani_cols, chase_ani_rows, wolf, sheep, answer = 0;
    int check_num, temp_sheep, check_rows, return_rows, return_cols, total_sheep, index;
    int visited_loc[17] = {0};
    int check_loc[17] = {0};
    int parameter[17] = {0};
    int return_sum[17] = {0};
    int floor[17][2] = {0};
    
    total_sheep = 0;
    visited_loc[0] = sheep = 1;

    for(chase_ani_rows = 0; chase_ani_rows < edges_rows; chase_ani_rows++){		
		temp_root = edges[chase_ani_rows][0];
		temp_leef = edges[chase_ani_rows][1];
		chase_ani_cols = 0;
		if(!floor[temp_root][chase_ani_cols]){
			floor[temp_root][chase_ani_cols] = temp_leef;
		}
		else{
			chase_ani_cols += 1;
			floor[temp_root][chase_ani_cols] = temp_leef;
		}
		
		if(floor[temp_root][0] > floor[temp_root][1] && chase_ani_cols > 0){
			temp_num = floor[temp_root][0];
			floor[temp_root][0] = floor[temp_root][1];
			floor[temp_root][1] = temp_num;
		} 
	} // Match root - index, leef - parameter
	
	for(check_num = 0; check_num < info_len; check_num++){
		total_sheep += !info[check_num] ? 1 : 0; 
	} // Sum total_sheep
	
	for(chase_ani_cols = 0; chase_ani_cols < edges_cols; chase_ani_cols++){
		parameter[chase_ani_cols] = floor[0][chase_ani_cols];
	} // leef of frist root 
	
	for(check_num = 0; check_num < total_sheep; check_num++){
		index = 0;
		for(parameter[index]; parameter[index] != 0; index++){
			if(!info[parameter[index]]){
				for(return_rows = 0; ){
					for(return_cols = 0;){
						
					}
				}
			}
		}

		for()
	}
	
    for(chase_ani_rows = 0; chase_ani_rows < 17; chase_ani_rows++){
    	for(chase_ani_cols = 0; chase_ani_cols < 2; chase_ani_cols++){
    		printf("%d ", floor[chase_ani_rows][chase_ani_cols]);
    	}
    	printf("\n");
	}
    return total_sheep;
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
