#include <stdio.h>

int main (int argc,char**argv){
	int a=0;
	int b=0;
	char s[10];
	/*
	printf("嫌いなYouTuberをいれてください \n");
	scanf("まじかよ %s 最低だな",a);
	printf("入力されたYouTuber は%sです\n",a);
	*/

	// scanf("%s",s);
	// printf("入力された数は%sです\n",s);
	printf("%lu\n",sizeof(s));
	fgets(s,sizeof(s),stdin);
	printf("%s\n",s);

/*
	printf("数を入れてください\n");
	scanf("%d",&b);
	printf("入力された数は %dです\n",b);
*/

	return 0;
}
