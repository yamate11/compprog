#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"
#define rep(i,a) REP(i, 0, a)
#define all(coll) ALL(coll)

ll keta(ll x){
    vector<ll> a;
    while(x){
        a.push_back(x%10);
        x /= 10;
    }
    int m = a.size();
    reverse(all(a));
    using VI = vector<ll>;
    using VVI = vector<VI>;
    using VVVI = vector<VVI>;
    VVVI dp(m,VVI(10,VI(2))); // どの桁まで見たか、天井はどこか、余裕があるか
    for(int i=1;i<=a[0];i++){
        dp[0][i][i!=a[0]]++;
    }
    rep(i,m-1){
        rep(j,10){
            rep(next,j){
                dp[i+1][j][1] += dp[i][j][1];
            }
            if(a[0]<a[i+1]){
                rep(next,a[0]-1){
                    dp[i+1][a[0]][1] += dp[i][j][0];
                }
                dp[i+1][a[0]][0]++;
            }else{
                rep(next,a[i+1]){
                    dp[i+1][a[0]][1] += dp[i][j][0];
                }
            }
        }
    }
    ll ans = 0;
    rep(j,10){
        rep(small,2){
            ans += dp[m-1][j][small];
        }
    }
    vector<vector<ll>> pow(10,vector<ll>(m));
    rep(i,10){
        pow[i][0] = 1;
    }
    rep(j,m-1){
        rep(i,10){
            pow[i][j+1] = pow[i][j]*ll(i);
        }
    }
    for(int i=1;i<m;i++){
        for(ll now=1;now<10;now++){
            ans += pow[now][m-i-1];
        }
    }
    return ans;
}

int main() {
  ll x, y;
  cin >> x >> y;
  ll a = keta(x);
  ll b = keta(y - 1);
  cout << b - a << endl;
}
