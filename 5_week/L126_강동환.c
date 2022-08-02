#include <stdio.h>
#include <stdlib.h>
// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int count_row, temp, big_row, big_col;
    big_row = big_col = 0;
    
    for(count_row = 0; sizes_rows > count_row; count_row++){
    	if(sizes[count_row][0] < sizes[count_row][1]){
    		temp = sizes[count_row][0];
    		sizes[count_row][0] = sizes[count_row][1];
    		sizes[count_row][1] = temp;
		}
		big_row = big_row < sizes[count_row][0] ? sizes[count_row][0] : big_row;
		big_col = big_col < sizes[count_row][1] ? sizes[count_row][1] : big_col;
	}
    
    return big_row*big_col;
}

//int main (void){
//	int arr[4][2] = {
//		{60, 50},
//		{30, 70},
//		{60, 30},
//		{80, 40}
//	};
//	
//	int (*arr2)[2] = arr;
//	int** sizes = (*arr2)[2];
//
//	printf("%d", solution(sizes, 4, 2));
//}
