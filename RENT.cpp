#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct Jobs
{
	int st,end,cost;
};
bool cmp(struct Jobs a,struct Jobs b)
{	
	return a.end<b.end;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,ans=0;
		cin>>n;
		Jobs s[n];
		long long temp[n];
		for(int i=0;i<n;i++)
		{
		cin>>s[i].st>>s[i].end>>s[i].cost;
		s[i].end+=s[i].st;
		}
		sort(s,s+n,cmp);
		for(int i=0;i<n;i++)
		{
		temp[i]=s[i].cost;
		}	
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(s[j].end < s[i].st and ((temp[j]+s[i].cost)>temp[i]))
				temp[i]=(temp[j]+s[i].cost);
				ans=max(temp[i],ans);
			}
		}
		cout<<ans<<endl;
	}
}
