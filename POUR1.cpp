#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int change(int A,int B,int C)
{
	int a=0,b=0,res=0,x=0;
	while(a!=C && b!=C)
	{
		if(a==0)
		a=A;
		else if(b==B)
		b=0;
		else
		{
			x=min(a,B-b);	
			a-=x,b+=x;
		}
		res++;
	}
	return res;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,m1,m2;
		cin>>a>>b>>c;
		if((a<c && b<c) || c%__gcd(a,b)!=0)
		{
			printf("-1\n");continue;
		}
		else
		{
			m1=change(a,b,c);
			m2=change(b,a,c);
		}
		printf("%d\n",min(m1,m2));
 
	}
 
} 
