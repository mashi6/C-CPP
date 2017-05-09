/*
macOS Sierra 10.12.4
x86_64-apple-darwin 16.5.0
gcc 4.2.1
*/
#include <stdio.h>
#include <string.h>

void sortEng(char a);
void sortJap(char a,char b,char c);
int JudgeLang(char a);
void checkCount();

char input[10000];
char answer[10000];
int strCount = 0;
int strLen = 0;

void sortEng(char a){
	answer[strLen - strCount] = a;
	strCount++;
	checkCount();
}

void sortJap(char a,char b,char c){
	answer[strLen - strCount] = c;
	strCount++;
	answer[strLen - strCount] = b;
	strCount++;
	answer[strLen - strCount] = a;
	strCount++;
	checkCount();
}

int JudgeLang(char a){
	if (a < 0){
		return 1;
	}else{
		return 0;
	}
}

void checkCount(){
	if(strCount > strLen){
	}else{
		if (JudgeLang(input[strCount])){
			sortJap(input[strCount],input[strCount + 1],input[strCount + 2]);
		}else{
			sortEng(input[strCount]);
		}
	}
}

int main(void) {
	printf(">> ");
	scanf("%[^\n]",input);
	strLen = strlen(input) -1;
	checkCount();
	printf("\n>> %s\n",answer);
	return 0;
}
