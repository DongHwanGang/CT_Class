#include <stdio.h>
#include <stdlib.h>

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int count, countWaterMelon, nullCount = 0;
    char* answer;
	char water[3] = "수";
	char melon[3] = "박";
	
	answer = (char*)malloc((3*n) + 1);
	
	for(count = 0; count < (3*n) + 1; count++){
		answer[count] = '\0';
	}
	
	for(count = 0; count < n; count++){
		for(nullCount = 0; answer[nullCount] != '\0'; nullCount++){
			}
			
		for(countWaterMelon = 0; countWaterMelon < 3; countWaterMelon++){	
			if(count % 2 == 0){
				answer[countWaterMelon + nullCount] = water[countWaterMelon];
			}
			
			else if(count % 2 != 0){
				answer[countWaterMelon + nullCount] = melon[countWaterMelon];	
			}
		}
	}

    return answer;
}

int main () {
	int n;
	char* answer;
	
	scanf("%d", &n);
	answer = solution(n);
	puts(answer);
	free(answer);
}
