#include <iostream>
#include <algorithm>
#include <cstdlib>
#define N 1005
void ssort(int a[N],int n);
using namespace std;
int a[N],n;
int cmp(const void *a,const void *b)	{return -*(int*)a+*(int*)b;}
int main()	{
	int i=0,n0,ans=0;
	scanf("%d",&n);n0=n;
	while (n0--)	scanf("%d",&a[i++]);
	qsort(a,n,sizeof(int),cmp);
	for (int j=0;j<n;j++)	{
		if (a[j]<a[j+1]+a[j+2])	{
			ans=a[j]+a[j+1]+a[j+2];
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
} 

