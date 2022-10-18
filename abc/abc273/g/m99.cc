#include <stdio.h>
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 2000000000000000001



int main(){
	
	int n;
	cin>>n;
	
	vector<int> r(n);
	int s = 0,c1 = 0;
	rep(i,n){
		cin>>r[i];
		s += r[i];
		if(r[i]==1)c1++;
	}
	vector<mint> dp(n+1,0);
	dp[c1] = 1;
	
	rep(i,n){
		int c;
		cin>>c;
		if(c==0)continue;
		vector<mint> ndp(n+1,0);
		rep(j,n+1){
			if(dp[j]==0)continue;
			int x = j;
			int y = s - x;
			if(y%2==1)continue;
			y /= 2;
			if(c==1){
				if(j!=0)ndp[j-1] += dp[j] * x;
				if(j+1<=n)ndp[j+1] += dp[j] * y;
			}
			else{
				if(j>=2)ndp[j-2] += dp[j] * (x * (x-1) / 2);
				ndp[j] += dp[j] * x * y;
				if(j+2<=n)ndp[j+2] += dp[j] * (y * (y-1) / 2);
				ndp[j] += dp[j] * y;
			}
		}
		swap(dp,ndp);
		s -= c;
	}
	
	if(s!=0){
		cout<<0<<endl;
	}
	else{
		cout<<dp[0].val()<<endl;
	}
	
	return 0;
}
