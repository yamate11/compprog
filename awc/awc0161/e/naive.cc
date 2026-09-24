#include<bits/stdc++.h>
namespace {
#pragma GCC diagnostic ignored "-Wunused-function"
#include<atcoder/all>
#pragma GCC diagnostic warning "-Wunused-function"
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  VI h(n);
  rep(i, n) cin >> h[i];
  segtree<int, [](int x, int y) { return max(x, y); }, []() { return 0; }> seg(h);
  int w = 0;
  rep(_, m) {
    int x;
    cin >> x;
    chmax(w, x);
  }
  VL s(n + 1);
  rep(i, n) s[i+1] = s[i] + h[i];
  ll ans = 0;
  rep(i, n - w + 1) {
    chmax(ans, s[i] + (s[n] - s[i+w]) + (ll)seg.prod(i, i + w) * w);
  }
  cout << ans << '\n';
}
