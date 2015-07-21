#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
//#define rl(x) scanf("%d",&x)
inline void rl(int &x) 
{
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg)
        x = -x;
}
 
using namespace std;
int main()
{
	int t;
	rl(t);
	while(t--)
	{
		int n;
		rl(n);
		queue<int>freeM;
		int menP[n+10][n+10],womenP[n+10][n+10],c[n+10],x,rank[n+10][n+10],next[n+10],M,W,wife[n+10];
		memset(c,0,sizeof c);
		for(int i=1;i<=n;i++)
		{
			rl(x);
			for(int j=1;j<=n;j++)
			scanf("%d",&womenP[x][j]);
		}
		for(int i=1;i<=n;i++)
		{
			rl(x);
			for(int j=1;j<=n;j++)
			rl(menP[x][j]);
		}
		for(int i=1;i<=n;i++)
		   for(int j=1;j<=n;j++)
			rank[i][womenP[i][j]]=j;
		for(int i=1;i<=n;i++)
		freeM.push(i),next[i]=1;
		
		while(!freeM.empty())
		{
			M=freeM.front();
			W=menP[M][next[M]++];
			if(c[W]==0)
			{
				c[W]=M;
				wife[M]=W;
				freeM.pop();
			}
			else if(rank[W][M]<rank[W][c[W]])
			{
				freeM.pop();
				freeM.push(c[W]);
				c[W]=M;
				wife[M]=W;
				
			}
		}
		for(int i=1;i<=n;i++)
		printf("%d %d\n",i,wife[i]);
		
	}
}  
