#include <iostream>
#include <algorithm>
using namespace std;

int main()	{
	int coins[7],values[7]={1,5,10,50,100,500},money,cnt=0;
	for (int i=0;i<6;i++)	scanf("%d",&coins[i]);
	scanf("%d",&money);
	for (int i=5;i>=0;i--)	{
		while (coins[i])	{
			if (money>=values[i])	{
				money-=values[i];
				coins[i]--;
				cnt++;
			}
			else break;
		}
		if (money==0)	break;
	}
	printf("%d",cnt);
	return 0;
}
