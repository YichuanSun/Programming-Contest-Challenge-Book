#include <iostream>
#include <algorithm>
#include <time.h>
#define N 1000005
using namespace std;
int fib(int n);
int fi[N];
int main()	{
	int n;
	scanf("%d",&n);
	int a=clock();
	fib(n);
	int b=clock();
	for(int i=0;i<n;i++) printf("%d\n",fi[i]);
	printf("Time:%lf\n",(double)(b-a)/CLOCKS_PER_SEC);
	return 0;
}

int fib(int n)	{
	if (n<2)	fi[n]=1;
	if (fi[n]!=0)	return fi[n];
	else	return fi[n]=fib(n-2)+fib(n-1);
}
