#include <stdio.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    long long answer = 0;
    int count_up;
    
    for(count_up = 1; count_up <= count; count_up++){
    	answer += count_up * price;
	} 
	
	return answer = money - answer < 0 ? -(money - answer) : 0;
}

int main (){
	int price, money, count;
	
	scanf("%d %d %d", &price, &money, &count);
	
	printf("%lld", solution(price, money, count));
}
