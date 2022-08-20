#include <stdio.h>
#include <stdlib.h>
// id_list_len은 배열 id_list의 길이입니다.
// report_len은 배열 report의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(id_list_len * sizeof(int));
    int** report_numbers;
    int id_space_count, row_count, col_count, space_count, rows, cols, report_sum = 0;
    
    report_numbers = (int**)malloc(id_list_len * sizeof(int*));
    
    for(col_count = 0; col_count < id_list_len; col_count++){
    	report_numbers[col_count] = (int*)malloc(id_list_len*sizeof(int));
    	answer[col_count] = 0;
    	for(cols = 0; cols < id_list_len; cols++){
    		report_numbers[col_count][cols] = 0;
		}
	}
	
	for(row_count = 0; row_count < report_len; row_count++){
		for(id_space_count = 0; id_space_count < id_list_len; id_space_count++){
			for(col_count = 0; report[row_count][col_count] != ' '; col_count++){
				if(report[row_count][col_count] != id_list[id_space_count][col_count]){
					break;
				}
			}
			if(report[row_count][col_count] == ' '){
				rows = id_space_count;
				space_count = col_count = col_count + 1;
				for(id_space_count = 0; id_space_count < id_list_len; id_space_count++){
					for(col_count; report[row_count][col_count] != '\0'; col_count++){
						if(report[row_count][col_count] != id_list[id_space_count][col_count - space_count]){
							break;
						}
					}
					if(report[row_count][col_count] == '\0'){
						cols = id_space_count;
						if(cols != rows){
							report_numbers[cols][rows] = 1;
						}
						break;
					}
				}
				break;
			}
		}
	}
		
	for(row_count = 0; row_count < id_list_len; row_count++){
		for(col_count = 0; col_count < id_list_len; col_count++){
			report_sum += report_numbers[row_count][col_count] == 1 ? 1 : 0;
		}
		
		if(report_sum >= k){
			for(rows = 0; rows < id_list_len; rows++){
				answer[rows] += report_numbers[row_count][rows] == 1 ? 1 : 0;
			}
		}
		report_sum = 0;
	}
	
	for(col_count = 0; col_count < id_list_len; col_count++){
		free(report_numbers[col_count]);
	}
	free(report_numbers);
	
    return answer;
}

void main(){
	const char* id_list[]={"muzi", "frodo", "apeach", "neo"};
	const char* report_list[]={"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
	int i;
	int* array = solution(id_list,4,report_list,5,2);
	
	for(i=0; i<4; i++){
		printf("%d ",array[i]);
	}
	
	free(array);
}
