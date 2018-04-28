#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#define N 100 
#define INF 100000
using namespace std;
typedef pair<int,int> P;
int dis[N][N];
int n,m;
char a[N][N];
queue<P> que;
int bfs(int sx,int sy){
	int movx[4]={-1,0,1,0},movy[4]={0,-1,0,1};
	que.push(P(sx,sy));
	dis[sx][sy]=0;
	while (que.size())	{
		P p=que.front();
		if (a[p.first][p.second]=='G')	break;
		que.pop();
		int nowx,nowy;
		for (int i=0;i<4;i++)	{
			nowx=p.first+movx[i];nowy=p.second+movy[i];
			if (nowx>=0&&nowx<m&&nowy>=0&&nowy<n&&a[nowx][nowy]!='#'&&dis[nowx][nowy]==INF)	{
				que.push(P(nowx,nowy));
				dis[nowx][nowy]=dis[p.first][p.second]+1;
			}
		}
	}
	return dis[que.front().first][que.front().second];
}
int main()	{
	int sx,sy;
	for (int i=0;i<N;i++)		
		for (int j=0;j<N;j++)
			dis[i][j]=INF;
	scanf("%d %d ",&n,&m);
	getchar();
	for (int i=0;i<n;i++)	{
		for (int j=0;j<m;j++)	{
			scanf("%c",&a[i][j]);
			if (a[i][j]=='S')	{sx=i,sy=j;}
		}
		if (i!=n-1)	getchar();
	}
	printf("%d\n",bfs(sx,sy));
	return 0;
}
