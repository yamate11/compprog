#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M=5e5+5;

double get_time_sec() {
  using namespace std;
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}



inline ll read()
{
	ll x=0,f=1;static char ch;
	while(ch=getchar(),ch<48)if(ch==45)f=0;
	do x=(x<<1ll)+(x<<3ll)+(ch^48);
	while(ch=getchar(),ch>=48);
	return f?x:-x;
}

int n,q;
ll a[M],w[M],der;
ll L[M],R[M],ans[M];

int main()
{
  double t1 = get_time_sec();
	n=read(),q=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
  double t2 = get_time_sec();
	for(int i=1;i<=q;i++)
	{
		w[i]=read(),der+=w[i];
		L[i]=max(L[i-1],-der);
		R[i]=max(R[i-1],der);
	}
	
	ans[1]+=L[q],ans[n]+=R[q];
	for(int i=2;i<=n;i++)
	{
		ll dis=a[i]-a[i-1];
		ll l=1,r=q,res=-1;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(L[mid]+R[mid]>=dis)
				res=mid,r=mid-1;
			else l=mid+1;
		}
		if(res==-1)
		{
			ans[i-1]+=R[q];
			ans[i]+=L[q];
		}
		else
		{
			if(L[res-1]==L[res])
			{
				ans[i-1]+=dis-L[res];
				ans[i]+=L[res];
			}
			else
			{
				ans[i-1]+=R[res];
				ans[i]+=dis-R[res];
			}
		}
	}
	
  double t3 = get_time_sec();

	for(int i=1;i<=n;i++)
		printf("%lld\n",ans[i]);
	
  double t4 = get_time_sec();

  cerr << t2 - t1 << "\n";
  cerr << t3 - t2 << "\n";
  cerr << t4 - t3 << "\n";

	return 0;
}
