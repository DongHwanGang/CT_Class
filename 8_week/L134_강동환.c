#include <stdio.h>
#include <stdlib.h>
// survey_len은 배열 survey의 길이입니다.
// choices_len은 배열 choices의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* survey[], size_t survey_len, int choices[], size_t choices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(5);
    char standard[9] = "RTCFJMAN";
    char high_standard;
    int standard_score[8] = {0};
	int survey_count, choice_count, standard_count, answer_count, null_count = 0; 
   	
	for(null_count = 0; null_count < 5; null_count++){
		answer[null_count] = '\0'; // Enter null characters to answer string
	}
   	
	for(survey_count = 0; survey_count < choices_len; survey_count++){
		high_standard = choices[survey_count] < 5 ? survey[survey_count][0] : survey[survey_count][1];
		// Found a higher score indicator in the survey
		for(standard_count = 0; standard_count < 9; standard_count++){
			if(high_standard == standard[standard_count]){
				break;
			} // Found index of index with higher score in standard string
		}
		
		standard_score[standard_count] += choices[survey_count] < 4 ?  4 - choices[survey_count] : choices[survey_count] - 4;
	}	// If the score received is less than 4, subtract the score entered from 4, and if it is greater than 4, subtract 4 from the score entered
		// Add the scores obtained to the score array corresponding to the index obtained above.
	for(choice_count = 0; choice_count < 8; choice_count += 2){
		if(standard_score[choice_count] == standard_score[choice_count + 1]){
			answer[answer_count] = standard[choice_count];
		}	// If the corresponding types have the same score, put the previous type in the answer string in the dictionary.
		
		else{
			answer[answer_count] = standard_score[choice_count] < standard_score[choice_count + 1] ? standard[choice_count + 1] : standard[choice_count];
		}	// If the corresponding types have different scores, put the large type in the answer string.
		
		answer_count++; // Increase the index of the answer string.
	}
      
    return answer;
}

void main(){
	char survey[][3]={"AN", "CF", "MJ", "RT", "NA"};
	int choices[]={5, 3, 2, 7, 5};
	int i;
	char* answer;
	
	answer = solution(survey, 5, choices, 5);
	
	for(i = 0; i < 5; i++){
		printf("%c",answer[i]);
	}
	
	free(answer);
}
