#include <stdio.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* dirs) {
    int answer = 0;
    int coordinate[21][21] = {0};
    int score_count, move_count, top_bottom, left_right, coordinate_move = 0;
    top_bottom = left_right = 10;
    coordinate[top_bottom][left_right] = 1;
    
    for(move_count = 0; dirs[move_count] != '\0'; move_count++){
		for(score_count = 0; score_count < 2; score_count++){
  			switch(dirs[move_count]){
	    		case 'U':
	    			top_bottom = (top_bottom - 1 < 0) ? top_bottom : top_bottom - 1;
	    			break;
	    		
	    		case 'D':
	    			top_bottom = (top_bottom + 1 > 20) ? top_bottom : top_bottom + 1;
	    			break;
	    		
	    		case 'R':
	    			left_right = (left_right + 1 > 20) ? left_right : left_right + 1;
	    			break;
	    		
	    		case 'L':
	    			left_right = (left_right - 1 < 0) ? left_right : left_right - 1;
	    			break;
			}
			coordinate_move = coordinate[top_bottom][left_right] == 0 ? coordinate_move + 1 : coordinate_move;
  			coordinate[top_bottom][left_right] += 1;
		}
		answer = coordinate_move > 0 ? answer + 1 : answer;
		coordinate_move = 0; 
	}
		
    return answer;
}

int main () {
	char dirs[501] = "";
	
	gets(dirs);
	
	printf("%d", solution(dirs));
}
