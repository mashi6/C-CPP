#include<stdio.h>

struct a{
	int a_a;
	int b_b;
	int c_c;
};

struct A{
	int a;
	int b;
	int c;
	struct a aaaa;
	struct a *aa;
};
struct name{
	char sei[5];
	char mei[5];
};

struct line{
	struct name Name[5];
};

int main(){
	struct A A_[10];
	struct A *A__ = A_;
	for(int i=0;i<10;i++){
		A_[i].a = i;
		A_[i].b = i;
		A_[i].c = i;
		A_[i].aaaa.a_a = i;
		A_[i].aa = &(A_[i].aaaa);
 	}
 	struct a aaaaaa = A__->aaaa;
 	struct a *aaaaaa___ = &aaaaaa;
 	printf("%d\n",(&(A__->aaaa))->a_a); 
 	// printf("%d\n",(A__->aaaa)->a_a);
 	struct line lines[10];
 	// lines[0].name[0] = 'a';
 	struct line *linesP = lines;
 	printf("%s\n",(&(((linesP+0)->Name)[0]))->sei);


	// printf("%d\n",*(A__->aaaa)->a_a);

	return 0;
}