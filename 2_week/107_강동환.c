#include <stdio.h>

int solution(int num) {
    int answer = 0;
    int count = 1;
    
    for(count = 1; count <= 500; count++){
		if(num % 2 == 0){
	    	num /= 2; 
		}
	    
	    else
	    	num = num * 3 + 1; 
	    
		if(num == 1){
			break;
		}	
		
		if (num > 8000000){
			break;
		}
	}
	
	if(num == 1){
		answer = count;
	}
	
	else
		answer = -1;
    
    return answer;
}

int main (){
	int num;
	
	scanf("%d", &num);
	
	printf("%d", solution(num));
	
	return 0;
}
