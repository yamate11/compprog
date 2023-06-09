#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using ld = long double;
using P = pair<int,int>;
static const int mod1 = 998244353;
static const int mod2 = 1000000007;
static const long double pi = 3.14159265359;
static const long double eps = 1e-9;

template<class T> bool chmax(T &a, T b) {
  if(a<=b) {
    a = b;
    return true;
  }
  return false;
}

template<class T> bool chmin(T &a, T b) {
  if(a>b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T>
T extgcd(T a,T b,T&x,T&y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	T q=a/b;
	T g=extgcd(b,a-q*b,y,x);
	y-=q*x;
	return g;
}

using mint = modint998244353;

int main()
{
	int N;
	cin >> N;
	vector<int> C(10);
	for(int i = 1; i<10; i++) cin >> C[i];

	vector<vector<int>> dp(N+1, vector<int>(10, -1));
	dp[0][0] = 1;
	rep(i,N) rep(j,10) if(dp[i][j]!=-1)
	{
		rep(k,10) if(k!=0)
		{
			if(i+C[k]<=N) chmax(dp[i+C[k]][k], dp[i][j]+1);
		}
	}
	/*
	rep(i,N+1)
	{
		rep(j,10) cout << dp[i][j] << " ";
		cout << endl;
	}*/

	int mx = -1;
	int x = -1;
	int y = -1;
	rep(j,10) rep(i,N+1) if(chmax(mx, dp[i][j]))
	{
		x = i;
		y = j;
	}
        cerr << "*** " << x << ", " << y << endl;

	while(x)
	{
		cout << y;
		x-=C[y];
		mx = -1;
		rep(j,10) if(chmax(mx, dp[x][j])) y = j;
	}
	cout << endl;
}
