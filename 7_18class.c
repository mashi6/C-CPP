#include<stdio.h>
#include<stdlib.h>

int main(void){
	FILE *fp;
	int a,b;

	a=2;
	b=1;

	fp = fopen("test.txt","w");

	if(fp==NULL){
		printf("ファイルを開けませんでした。\n");
		exit(-1);
	}

	fprintf(fp,"a=%d\n",a);
	fprintf(fp,"b=%d\n",b);

	fclose(fp);

	fp=fopen("test.txt","r");


	fscanf(fp,"a=%d\n",&b);
	fscanf(fp,"b=%d\n",&a);
	printf("a/b=%lf\n",(double)a/(double)b);

	fclose(fp);
	printf("test.txtに書き込みました。\n");



	return 0;
}
