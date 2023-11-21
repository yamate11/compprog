/*
 ##  ##                              ##   ##     ####  #######  ######
 ##  ##                              ##   ##      ##    ##   #  # ## #
 ##  ##   ##  ##   ##  ##    ####    ##   ##      ##    ## #      ##
  ####    ##  ##   #######      ##   #######      ##    ####      ##
   ##     ##  ##   ## # ##   #####   ##   ##  ##  ##    ## #      ##
   ##     ##  ##   ##   ##  ##  ##   ##   ##  ##  ##    ##   #    ##
  ####     ######  ##   ##   #####   ##   ##   ####    #######   ####
Welcome to my workspace!
Lang: C++17
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i,a) for(auto &i:a)
#define all(n) n.begin(), n.end()
#define pb push_back
#define elif else if
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ll MOD2 = 998244353;
/* directions */
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
// chmin
template <typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
// chmax
template <typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }

// 素因数分解
template <typename T>
map<T, T> prime_factor(T n) {
    map<T, T> ret;
    for (T i = 2; i * i <= n; i++) {
        T tmp = 0;
        while (n % i == 0) {
            tmp++;
            n /= i;
        }
        ret[i] = tmp % MOD2;
    }
    if (n != 1) ret[n] = 1;
    return ret;
}
/*  divisor_num(n)
    入力：整数 n
    出力：nの約数の個数
    計算量：O(√n)
*/
ll A,B;
template <typename T>
T divisor_num(T N) {
    map<T, T> pf = prime_factor(N);
    T ret = 1;
    for (auto p : pf) {
        // ココのみ変えた
        ret *= (p.second * B + 1) % MOD2;
    }
    return ret;
}

int main(void)
{
  /* 高速化 */
  cin.tie(0)->sync_with_stdio(0);
  /* ##### */
  cin>>A>>B;
  B%=MOD2;
  ll c = divisor_num(A);
  cerr << B << "; " << c << endl;
  cout<<((B*c) / 2) % MOD2<<endl;
  return 0;
}
