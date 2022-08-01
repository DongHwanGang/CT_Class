#include <stdio.h>

int solution(int n) {
    int answer = 0;
    int temp = 1;
    int ternary_scale = 1;
		
	for(n; n > 3; n /= 3){
		temp = temp*10 + n % 3;
		if(n / 3 < 3){
			temp = temp*10 + n / 3;
		}
	}
	
	for(temp; temp > 0; temp /= 10){
		n = temp % 10;
		for(n; n > 0; n--){
			answer += ternary_scale;
		}
		ternary_scale*= 3;
	}
	
    return answer;
}

int main (viod){
	int n;
	
	scanf("%d", &n);
	printf("%d", solution(n));
}
