#include <stdio.h>

int* solution(int n, long long left, long long right) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(sizeof(int) * (right - left + 1));
    long long whole, rest, share;
    		
	for(whole = left; whole < right + 1; whole++){
		share = whole / n;
		rest = whole % n; 
		
		if(share < rest){
			answer[whole - left] = rest + 1;
		}
		else{
			answer[whole - left] = share + 1;
		}
	}
	
    return answer;
}

int main () {
	int n, left, right;
	int* answer;
	scanf("%d %d %d", &n, &left, &right);
	
	answer = solution(n, left, right);
	free(answer);
}
