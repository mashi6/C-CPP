#include<stdio.h>
#include<limits.h>
#include<float.h>
#include<math.h>

int main(void){

	long long int LongLongInt =LLONG_MAX;
	int Int = 0;
	double Double = DBL_MAX;
	float Float = 0.0;

	printf("LongLongInt Size : %lu\n",sizeof(LongLongInt));
	printf("Int Size : %lu\n",sizeof(Int));
	printf("Double Size : %lu\n",sizeof(Double));
	printf("Float Size : %lu\n\n",sizeof(Float));


	Int = LongLongInt;
	Float = (float)Double;
	printf("convert\n\n");

	printf("LLONG_MAX : %lld\n",LongLongInt);
	printf("DBL_MAX : %lf\n",Double);
	printf("LLONG_MAX -> Int : %d\n",Int);
	printf("DBL_MAX -> Float : %f\n\n",Float);

	LongLongInt = Int;
	Double = (double)Float;

	printf("convert\n\n");

	printf("LLONG_MAX -> Int -> LongLongInt : %lld\n",LongLongInt);
	printf("DBL_MAX -> Float -> Double : %lf\n",Double);
	printf("LLONG_MAX -> Int : %d\n",Int);
	printf("DBL_MAX -> Float : %f\n",Float);

/*--------------------------------------------------------------------*/
	printf("\n対処\n\n");

	LongLongInt =LLONG_MAX;
	Int = 1;
	Double = DBL_MAX;
	Float = 1.0;

	Int = LongLongInt % (INT_MAX+1);
	Float = (float)(fmod((FLT_MAX+1.0),(float)Double));


	printf("LLONG_MAX : %lld\n",LongLongInt);
	printf("DBL_MAX : %lf\n",Double);
	printf("LLONG_MAX -> Int : %d\n",Int);
	printf("DBL_MAX -> Float : %f\n\n",Float);

	LongLongInt = Int;
	Double = (double)Float;

	printf("convert\n\n");

	printf("LLONG_MAX -> Int -> LongLongInt : %lld\n",LongLongInt);
	printf("DBL_MAX -> Float -> Double : %lf\n",Double);
	printf("LLONG_MAX -> Int : %d\n",Int);
	printf("DBL_MAX -> Float : %f\n",Float);

	printf("%lld",LLONG_MAX % (INT_MAX+1));

}
