#include <stdio.h>

int solution(int n) {
    int answer = 0;
    
	for(answer = 1; answer < n; answer++){
		if(1 == n % answer){
			return answer;
		}
	}
}

int main () {
	int n;
	
	scanf("%d", &n);
	
	printf("%d", solution(n));
}
