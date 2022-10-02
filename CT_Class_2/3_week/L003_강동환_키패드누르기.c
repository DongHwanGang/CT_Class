#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int modulus (int n){
	if(n < 0){
		n = -n;
	}
	return n;
}

void hand_move (int* arr, char* hand){
	int r_hand_rows, r_hand_cols, l_hand_rows, l_hand_cols, m_rows, m_cols, rm_dif, lm_dif;
	int move_num;
	char* result = (char*)malloc(sizeof(char) * 11);
	l_hand_rows = r_hand_rows = 3;
	r_hand_cols = 2;
	l_hand_cols = 0;
	m_rows = 0;
	
	for(move_num = 0; move_num < 10; move_num++){
		if(arr[move_num] % 3 == 0 && arr[move_num] != 0){
			r_hand_rows = arr[move_num] / 3 - 1;
			r_hand_cols = 2;
			result[move_num] = 'R';
		}
		
		else if(arr[move_num] % 3 == 1){
			l_hand_rows = arr[move_num] / 3;
			l_hand_cols = 0;
			result[move_num] = 'L';
		}
		
		else if(arr[move_num] % 3 == 2 || arr[move_num] == 0){
			if(arr[move_num] == 0){
				m_rows = 3;
			}
			else{
				m_rows = arr[move_num] / 3;
			}
			m_cols = 1;
			
			rm_dif = modulus(m_rows - r_hand_rows) + modulus(r_hand_cols - m_cols);
			lm_dif = modulus(m_rows - l_hand_rows) + modulus(l_hand_cols - m_cols);
			
			if(rm_dif > lm_dif){
				result[move_num] = 'L';
				
				if(arr[move_num] == 0){
					l_hand_rows = 3;
				}
				else{
					l_hand_rows = arr[move_num] / 3;
				}
				
				l_hand_cols = 1;
			}
			else if(rm_dif < lm_dif){
				result[move_num] = 'R';
				
				if(arr[move_num] == 0){
					r_hand_rows = 3;
				}
				else{
					r_hand_rows = arr[move_num] / 3;
				}
				
				r_hand_cols = 1;
			}
			else if(rm_dif == lm_dif){
				if(strlen(hand) % 2){
					result[move_num] = 'R';
					
					if(arr[move_num] == 0){
						r_hand_rows = 3;
					}
					else{
						r_hand_rows = arr[move_num] / 3;
					}
					
					r_hand_cols = 1;
				}
				else{
					result[move_num] = 'L';
					
					if(arr[move_num] == 0){
						l_hand_rows = 3;
					}
					else{
						l_hand_rows = arr[move_num] / 3;
					}
					
					l_hand_cols = 1;
				}
			}
		}
	}
	
	result[move_num] = '\0';
	
	puts(result);
}

//void int_one_dim(int* arr){
//	int input_num;
//	
//	for(input_num = 0; input_num < 11; input_num++){
//		scanf("%d", &arr[input_num]);
//	}
//}

int main () {
	int numbers[1000] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	char hand[6] = "right";
	
//	int_one_dim(numbers);
	hand_move (numbers, hand);
}
