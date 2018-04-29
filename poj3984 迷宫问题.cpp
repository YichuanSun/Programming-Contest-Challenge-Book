#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
typedef struct point{
	int x,y,prex,prey;
	point(){};
	point(int a,int b,int c,int d)	{x=a;y=b;prex=c;prey=d;}
}point;
point dis[7][7];
queue<point> que;
stack<point> sta;
void bfs();
void print();
bool maze[7][7];
bool spot[7][7];
int main()	{
	for (int i=1;i<=5;i++)
		for (int j=1;j<=5;j++)
			scanf("%d",&maze[i][j]);
	bfs();
	print();
	return 0;
}
void bfs()	{
	int sx=1,sy=1;
	int movx[4]={1,0,-1,0},movy[4]={0,1,0,-1};
	dis[1][1]=point(sx,sy,-1,-1);
	spot[1][1]=true;
	que.push(point(sx,sy,-1,-1));
	while (que.size())	{
		point P=que.front();
		if (P.x==5&&P.y==5)	break;
		for (int i=0;i<4;i++)	{
			int nowx=P.x+movx[i],nowy=P.y+movy[i];
			if (nowx>=1&&nowx<=5&&nowy>=1&&nowy<=5&&maze[nowx][nowy]==false&&spot[nowx][nowy]==false)	{
				que.push(point(nowx,nowy,P.x,P.y));
				dis[nowx][nowy]=point(nowx,nowy,P.x,P.y);
				spot[nowx][nowy]=true;
			}
		}
		que.pop();
	}
}
void print()	{
	int i=5,j=5;
	while (i!=-1&&j!=-1)	{
		sta.push(dis[i][j]);
		int inii=i,inij=j;
		i=dis[inii][inij].prex;
		j=dis[inii][inij].prey;
	}
	while (!sta.empty()){
		cout << '(' << sta.top().x-1 << ", " << sta.top().y-1 << ')' << endl;
		sta.pop();
	}
}
