#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
#include <atcoder/maxflow>
using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(strSearch)

// ---- inserted library file strSearch.cc
vector<int> zAlg(string s) {
  int n = s.size();
  vector<int> z(n);
  z.at(0) = n;
  int i = 1;
  int j = 0;
  while (i < n) {
    for ( ; i+j < n && s.at(j) == s.at(i+j); j++) {}
    z.at(i++) = j;
    if (j > 0) {
      for (int k = 1; i < n && z.at(k) < j-1; k++, j--, i++) z.at(i) = z.at(k);
      j--;
    }
  }
  return z;
}

// matches("abab", "xababab") --> [1,3]
vector<int> matches(string p, string s, char sepChar = '\xff') {
  auto v = zAlg(p + string(1, sepChar) + s);
  int n = p.size();
  vector<int> res;
  for (size_t i = 0; i < s.size() - (n-1); i++) {
    if (v.at(n+1 + i) == n) res.push_back(i);
  }
  return res;
}
// ---- end strSearch.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, S, type=string) [5uSuXR0s]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [5uSuXR0s]
  // @InpVec(N, A) [kKRwrSnq]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [kKRwrSnq]

  vector B(N, vector(N, false));
  string alls = "";
  REP(i, 0, N) for (char c : A[i]) alls.push_back(c);
  REP(i, 0, N) {
    string x = A[i];
    x.push_back('@');
    for (char c : alls) x.push_back(c);
    auto z = zAlg(x);
    ll p = 0;
    REP(j, 0, N) {
      B[i][j] = ([&]() -> bool {
        if (j == i) return false;
        REP(q, 0, ssize(A[j]) - ssize(A[i]) + 1) if (z[ssize(A[i]) + 1 + p + q] == ssize(A[i])) return true;
        return false;
      })();
    }
    p += ssize(A[j]);
  }
  ll big = 1e18;
  mf_graph<ll> gr(2 * N + 2);
  REP(i, 0, N) {
    gr.add_edge(2*N, i, A[i]);
    gr.add_edge(N + i, 2*N + 1, A[i]);
  }
  REP(i, 0, N) REP(j, 0, N) if (B[i][j]) gr.add_edge(i, N + j, big);
  ll flow = gr.flow(2*N, 2*N + 1);
  ll tota = 0;
  REP(i, 0, N) tota += A[i];
  cout << tota - flow << endl;

  return 0;
}

