#include <stdio.h>

int solution(int num) {
    int answer = 0;
    int count = 0;
    long long tepNumber = num;
    
    for(count = 0; count <= 500; count++){
		
		if(tepNumber == 1){
				break;
		}	
		if(tepNumber % 2 == 0){
	    	tepNumber /= 2; 
		}
	    
	    else
	    	tepNumber = tepNumber * 3 + 1; 
			
		
	}
	
	if(tepNumber == 1){
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
