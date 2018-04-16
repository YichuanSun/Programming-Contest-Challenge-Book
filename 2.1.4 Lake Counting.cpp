#include <stdio.h>
#include <stdlib.h>
#define N 101
using namespace std;
void dfs(int i,int j);
int b[N][N],number,n,m;
char a[N][N];
int main()	{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)	scanf("%s",a[i]);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (a[i][j]=='W')	{
				dfs(i,j);
				number++;
			}
	printf("%d\n",number);
	return 0;
}

void dfs(int i,int j)	{
	if (i<0||i>m-1||j<0||j>n-1)	return;
	if (b[i][j]==1||a[i][j]=='.')	return;
	b[i][j]=1;
	for (int p=-1;p<=1;p++)	{
		for (int q=-1;q<=1;q++)	{
			int x=i+p,y=j+q;
			if (x!=0||y!=0)
				dfs(x,y);
		}
	}
}
