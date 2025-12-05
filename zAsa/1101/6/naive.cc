// Problem: C - Roller
// Contest: AtCoder - AtCoder Regular Contest 154
// URL: https://atcoder.jp/contests/arc154/tasks/arc154_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//不回家了，我们去鸟巢！
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[5003],b[10003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=n,N=n;
		for(int i=1; i<=n; ++i)
		{
			a[i]=read();
			if(a[i]==a[i-1]) --i,--n;
		}
		while(n>1&&a[n]==a[1]) --n;
		for(int i=1; i<=m; ++i)
		{
			b[i]=read();
			if(b[i]==b[i-1]) --i,--m;
		}
		while(m>1&&b[m]==b[1]) --m;
		for(int i=1; i<=m; ++i) b[m+i]=b[i];
		bool ans=0;
		if(n==N&&m==N)
		{
			ans=1;
			for(int i=1; i<=n; ++i) ans&=(a[i]==b[i]);
			if(ans) puts("Yes");
			else puts("No");
			continue;
		}
		for(int i=1; i<=m; ++i)
		{
			int ok=0;
			for(int j=1; ok<m&&j<=n; ++j)
			{
				if(a[j]==b[i+ok]) ++ok;
			}
			if(ok==m) ans=1;
		}
		if(ans) puts("Yes");
		else puts("No");
	}
	return 0;
}
