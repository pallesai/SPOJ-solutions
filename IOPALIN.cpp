#include<cstdio>
#include<cstring>
//#include<iostream>
#include<algorithm>
using namespace std;
#define maxi(a,b) a>b?a:b
int main()
{
	int n;
	scanf("%d",&n);
	char s[n+1];
	//string s,s1;
	scanf("%s",s);
	//s1=s;
	//reverse(s.begin(),s.end());
	int dp[2][n+2];
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++)
	   for(int j=1,k=n;k;k--,j++)
	   {
		if(s[i-1]==s[k-1])
		dp[(i&1)][j]=dp[!(i&1)][j-1]+1;
		else
		dp[(i&1)][j]=maxi(dp[i&1][j-1],dp[!(i&1)][j]);
	   }
	printf("%d\n",n-dp[n&1][n]);
		
} 
