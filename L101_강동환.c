#include <stdio.h>

int main (){
	int RowVolume, ColumnVolume;
	int RowRepetition, ColumnRepetition;
	
	scanf("%d %d", &RowVolume, &ColumnVolume);
	
	if(RowVolume > 1000 || ColumnVolume > 1000){
		return 0;
	}
	//////////////////
	for(ColumnRepetition = 0; ColumnVolume > ColumnRepetition; ColumnRepetition++){
		for(RowRepetition = 0; RowVolume > RowRepetition; RowRepetition++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
