#include <stdio.h>
#include <stdlib.h>
// id_list_len은 배열 id_list의 길이입니다.
// report_len은 배열 report의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(id_list_len * sizeof(int));
    char reporting_id[11] = "";
    char reported_id[11] = "";
    int** report_numbers;
    int check, identify__count, rows_identify, cols_identify, row_count, col_count, rows, cols, space_count, report_sum = 0;
    cols = rows = check = rows_identify = cols_identify = 0;
    
    report_numbers = (int**)malloc(id_list_len * sizeof(int*));
    
    for(col_count = 0; col_count < id_list_len; col_count++){
    	report_numbers[col_count] = (int*)malloc(id_list_len*sizeof(int));
    	answer[col_count] = 0;
    	for(cols = 0; cols < id_list_len; cols++){
    		report_numbers[col_count][cols] = 0;
		}
	}
	
	for(row_count = 0; row_count < report_len; row_count++){
		for(col_count = 0; report[row_count][col_count] != ' '; col_count++){
			reporting_id[col_count] = report[row_count][col_count];
		}
		
		check = space_count = col_count + 1;
		
		for(identify__count = 0; identify__count < id_list_len; identify__count++){
			for(col_count = 0; reporting_id[col_count] != '\0'; col_count++){
				if(reporting_id[col_count] != id_list[identify__count][col_count]){
					break;
				}	
			}
			
			if(id_list[identify__count][col_count] == '\0' && check - 1 == col_count){
				rows = identify__count;
				rows_identify = col_count;
			}
		}
		
		for(col_count = space_count; report[row_count][col_count] != '\0'; col_count++){
			reported_id[col_count - space_count] = report[row_count][col_count];
		}
		
		check = col_count - space_count;
	
		for(identify__count = 0; identify__count < id_list_len; identify__count++){
			for(col_count = 0; reported_id[col_count] != '\0'; col_count++){
				if(reported_id[col_count] != id_list[identify__count][col_count]){
					break;
				}
			}
			
			printf("%d", col_count);
			
			if(id_list[identify__count][col_count] == '\0' && check == col_count){
				cols = identify__count;				
				cols_identify = col_count;
				break;
			}
		}
	
		if(reporting_id[rows_identify] == '\0' && reported_id[cols_identify] == '\0'){	
			if(cols != rows){
				report_numbers[cols][rows] = 1;
				for(row_count = 0; row_count < 11; row_count++){
					reported_id[row_count] = '\0';
					reporting_id[row_count] = '\0';
				}
				rows_identify = 0;
				cols_identify = 0;
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
	//	printf("%d ",array[i]);
	}
	
	free(array);
}
