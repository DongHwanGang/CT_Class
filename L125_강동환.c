#include <stdio.h>
#include <stdlib.h>

char* solution(int a, int b) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(4);
    char Day[][4] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int count, month, days = -1;
    
    for(month = 1; a > month; month++){
	    switch(month){
	    	case 2:
	    		days+=29;
	    		break;
	    	case 4: case 6: case 9: case 11:
	    		days+=30;
	    		break;
	    	default:
	    		days+=31;
	    		break;
		}
	}
	
	days = (days + b) % 7;
	
	for(count = 0; 4 > count; count++){
		answer[count] = Day[days][count];
	}
	
    return answer;
}

int main (void){
	int a, b;
	char* answer;
	
	scanf("%d %d", &a, &b);
	answer = solution(a, b);
	puts(answer);
	free(answer);
}
