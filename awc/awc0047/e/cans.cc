#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
#include <atcoder/string>
using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(f:updMaxMin)

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  string S; cin >> S;
  string revS = S;
  ranges::reverse(revS);
  auto vec1 = z_algorithm(S);
  auto vec2 = z_algorithm(revS);
  vector<ll> tbl(N, 0LL);
  REP(i, 1, N) {
    if (vec1[i] > 0) updMax(tbl[vec1[i]], (ll)vec2[N - i]);
  }
  REPrev(i, N - 2, 0) updMax(tbl[i], tbl[i + 1]);
  REP(_q, 0, Q) {
    ll L, R; cin >> L >> R; L--;
    ll len = R - L;
    L = L % N;
    if (len > N) {
      cout << "No\n";
    }else if (L + len <= N) {
      cout << "Yes\n";
    }else {
      ll over = L + len - N;
      if (tbl[over] >= N - L) {
        cout << "Yes\n";
      }else {
        cout << "No\n";
      }
    }
    
  }

  return 0;
}

