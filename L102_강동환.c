#include <stdio.h>

int main (){
	int integer_x, naturalnumber_n, space_xn, answer = 0;
	
	scanf("%d %d", &integer_x, &naturalnumber_n);
	
	if(integer_x > 10000000 || integer_x < -10000000 || naturalnumber_n > 1000){
		return 0;
	}
	
	printf("[");
	
	for(space_xn = 1; space_xn <= naturalnumber_n; space_xn++){
		answer = integer_x*space_xn;
		printf("%d", answer);
		
		if(space_xn != naturalnumber_n){
			printf(",");
		}
	}
	
	printf("]");
	
	return 0;
}
