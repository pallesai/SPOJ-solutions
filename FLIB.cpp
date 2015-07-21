#include<cstdio>
#define ll long long
#define rl(x) scanf("%lld",&x)
#define MOD  1000000007
struct Matrix
{
	ll a,b,c,d;
};
int main()
{
 
	Matrix F,I,R;
	F.a=1,F.b=1,F.c=1,F.d=0;
	R.a=1,R.b=0,R.c=0,R.d=1;
	ll t,x,n;
	rl(t);
	while(t--)
	{
		rl(x);
		n=2*x;
		F.a=1,F.b=1,F.c=1,F.d=0;
		R.a=1,R.b=0,R.c=0,R.d=1;
		while(n)
		{
			if(n&1)
			{
				I.a=((F.a*R.a)+(F.b*R.c))%MOD;
				I.b=((F.a*R.b)+(F.b*R.d))%MOD;
				I.c=((F.c*R.a)+(F.d*R.c))%MOD;
				I.d=((F.c*R.b)+(F.d*R.d))%MOD;
 
				R.a=I.a%MOD,R.b=I.b%MOD,R.c=I.c%MOD,R.d=I.d%MOD;
				//printf("%lld   %lld\n%lld   %lld\n\n\n",R.a,R.b,R.c,R.d);
			}
				I.a=((F.a*F.a)+(F.b*F.c))%MOD;
				I.b=((F.a*F.b)+(F.b*F.d))%MOD;
				I.c=((F.c*F.a)+(F.d*F.c))%MOD;
				I.d=((F.c*F.b)+(F.d*F.d))%MOD;
				F.a=I.a%MOD,F.b=I.b%MOD,F.c=I.c%MOD,F.d=I.d%MOD;
				//printf("%lld   %lld\n%lld   %lld\n\n",F.a,F.b,F.c,F.d);
			n>>=1;
 
		}
		printf("%lld\n",(R.a*R.c)%MOD);
		
	}
} 
