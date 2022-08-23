#include <stdio.h>
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
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
