#include <stdio.h>

// info_len?? ??? info?? ????????.
// edges_rows?? 2???? ??? edges?? ?? ????, edges_cols?? 2???? ??? edges?? ?? ????????.
int solution(int info[], size_t info_len, int edges[11][2], size_t edges_rows, size_t edges_cols) {
    int temp_num, temp_leef, temp_root, chase_ani_cols, chase_ani_rows, wolf, sheep, answer = 0;
    int check_num, temp_sheep, temp_wolf, check_rows, return_rows, return_cols, total_sheep, index, temp_save, back_num;
    int null_num;
    int temp_loc[17] = {0};
    int check_loc[17] = {0};
    int parameter[17] = {0};
    int return_sum[17] = {0};
    int floor[17][1] = {0};
    
    wolf = temp_num = total_sheep = 0;
    check_loc[0] = sheep = 1;
	
    for(chase_ani_rows = 0; chase_ani_rows < edges_rows; chase_ani_rows++){		
		temp_root = edges[chase_ani_rows][0];
		temp_leef = edges[chase_ani_rows][1];
		floor[temp_leef][0] = temp_root;
	} // Match parameter - root , leef- index
	
	for(check_num = 0; check_num < info_len; check_num++){
		total_sheep += !info[check_num] ? 1 : 0; 
	} // Sum total_sheep
	
	for(chase_ani_cols = 1; chase_ani_cols < edges_rows; chase_ani_cols++){
		if(floor[chase_ani_cols][0] == 0){
			parameter[temp_num] = chase_ani_cols;
			temp_num++;
		}
	} // leef of frist root 
	
	for(check_num = 0; check_num < total_sheep; check_num++){
		index = 0;
//		for(chase_ani_rows = 0; chase_ani_rows < edges_rows; chase_ani_rows++){
//				printf("%d ", parameter[chase_ani_rows]);
//			}
//		printf("\n");
		for(parameter[index]; parameter[index] != 0; index++){
			temp_num = 1;
			if(!info[parameter[index]]){
				temp_save = return_sum[0] = parameter[index];
				for(floor[temp_save][0]; floor[temp_save][0] != 0; ){
					return_sum[temp_num] = floor[temp_save][0];
					temp_save = return_sum[temp_num];
					temp_num++;
				}
			}
			
			temp_sheep = sheep;
			temp_wolf = wolf;
			for(back_num = temp_num - 1; back_num > -1; back_num--){
				if(info[return_sum[back_num]] == 0){
					if(check_loc[return_sum[back_num]] == 0){
						temp_sheep += 1;
					}
				}
				else if(info[return_sum[back_num]] == 1){
					if(check_loc[return_sum[back_num]] == 0){
						temp_wolf += 1;
					}
				}
			}
			
			if(back_num == -1 && temp_wolf < temp_sheep){
				sheep = temp_sheep;
				wolf = temp_wolf;
				for(check_rows = 0; check_rows < temp_num; check_rows++){
					check_loc[return_sum[check_rows]] = 1;
				}
			}
			
			for(null_num = 0; null_num < 17; null_num++){
				return_sum[null_num] = 0;
			}
		}
		
		temp_leef = 0;
		for(temp_root = 0; temp_root < index; temp_root++){
			for(chase_ani_rows = 0; chase_ani_rows < edges_rows; chase_ani_rows++){
				if(floor[chase_ani_rows][0] == parameter[temp_root]){
					temp_loc[temp_leef] = chase_ani_rows;
					temp_leef++;
				}
			}
		}
		
		for(chase_ani_rows = 0; chase_ani_rows < 17; chase_ani_rows++){
			parameter[chase_ani_rows] = temp_loc[chase_ani_rows];
			temp_loc[chase_ani_rows] = 0;
		}
	}
	
    
    return sheep;
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
