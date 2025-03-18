#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

// void show2(const vector<vector<ll>>& x) {
void show2(const auto& x) {
  REP(i, 0, SIZE(x)) {
    REP(j, 0, SIZE(x[0])) cout << x[i][j] << " ";
    cout << endl;
  }
}

string show3(const vector<vector<ll>>& v) {
  string ret;
  for (auto r : v) {
    for (ll x : r) {
      ret += to_string(x) + " ";
    }
    ret += "\n";
  }
  return ret;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, P, type=string) [afWSmwqC]
  auto P = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; P[i] = v; }
  // @End [afWSmwqC]
  
  vector D(N + 1, vector(N + 1, 0LL));
  REP(i, 0, N) REP(j, 0, N) D[i + 1][j + 1] = P[i][j] == 'B' ? 1 : 0;
  REP(i, 1, N + 1) REP(j, 1, N + 1) D[i][j] += D[i][j - 1];
  REP(i, 1, N + 1) REP(j, 1, N + 1) D[i][j] += D[i - 1][j];
  show2(D);

  auto f = [&](ll x, ll y) -> ll {
    ll px = x / N;
    ll qx = x % N;
    ll py = y / N;
    ll qy = y % N;
    ll a1 = px * py * D[N][N];
    ll a2 = D[qx][qy];
    ll a3 = py * D[qx][N];
    ll a4 = px * D[N][qy];
    return a1 + a2 + a3 + a4;
  };

  REP(_q, 0, Q) {
    ll a, b, c, d; cin >> a >> b >> c >> d; c++; d++;
    ll ans = f(c, d) + f(a, b) - f(a, d) - f(c, b);
    cout << ans << "\n";
  }

  return 0;
}

