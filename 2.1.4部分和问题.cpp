#include <stdio.h>
#include <cstring>
#define N 25
using namespace std;
bool numbersum(int i,int sum);
int a[N],b[N],n,k;
int main()	{
	while (scanf("%d %d",&n,&k)!=EOF)	{
		int i=0;
		while (i<n)	scanf("%d",&a[i++]);
		memset(b,0,sizeof(b));
		if (numbersum(0,0))	{
			printf("YES\n");
			for (int j=0;j<n;j++)
				if (b[j])	printf("%d ",a[j]);
			printf("\n");
		}
		else	printf("NO\n");
	}
	return 0;
}

bool numbersum(int i,int sum)	{
	if (i==n)	return sum==k;
	if (numbersum(i+1,sum)) return true;
	if (numbersum(i+1,sum+a[i]))	{b[i]=1;return true;}
	return false;
}
