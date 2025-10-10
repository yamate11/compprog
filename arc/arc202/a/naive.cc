// created:  2025-07-20 20:01:11
#include<cstdio>
#include<cctype>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define I128 //||is_same<T,__int128_t>::value||is_same<T,__uint128_t>::value
using namespace std;
template<typename T>enable_if_t<is_integral<T>::value I128,void> readmain(T &x)
{
	bool neg=false;int c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=true;
	for(x=0;isdigit(c);c=getchar())x=(T)(10*x+(c-'0'));
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
typedef long long ll;
constexpr int N=2e5+5;
int n,s[N],t;
void push(int a)
{
	while(t&&s[t-1]==a)--t,++a;
	s[t++]=a;
}
void solve()
{
	read(n);
	ll ans=0;
	t=0;
	F(i,0,n)
	{
		int a;read(a);
		while(t&&s[t-1]<a)
		{
			--t;
			int x=a;
			if(t)x=min(x,s[t-1]);
			ans+=x-s[t];
			push(x);
		}
		push(a);
	}
	while(t>1)
	{
		--t;
		ans+=s[t-1]-s[t];
		++s[t-1];
	}
	printf("%lld\n",ans);
}
int main()
{
	int tt;read(tt);
	while(tt--)solve();
	return 0;
}
