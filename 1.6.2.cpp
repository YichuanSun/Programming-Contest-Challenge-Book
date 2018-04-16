#include <iostream>
#include <algorithm>
#include <cmath>
#define N 1000003
using namespace std;
int a[N];
int main()	{
	int m;
	scanf("%d",&m);
	while (m--)	{
		int l,n,i=0,near=0,far=0,inear,ifar;
		scanf("%d %d",&l,&n);
		while (i<n)	scanf("%d",&a[i++]);
		i=0;
		while (i<n)	{
			inear=min(a[i],abs(l-a[i]));
			ifar=max(a[i],abs(l-a[i]));
			if (inear>near)	near=inear;
			if (ifar>far)	far=ifar;
			i++;
		}
		printf("%d %d\n",near,far);
	}
	return 0;
}

