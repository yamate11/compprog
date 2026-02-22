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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  string S, T; cin >> S >> T;
  vector<bool> vecS(26);
  vector<bool> vecT(26);
  REP(i, 0, N) vecS[S[i] - 'a'] = true;
  REP(i, 0, M) vecT[T[i] - 'a'] = true;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    string w; cin >> w;
    auto f = [&]() -> string {
      REP(i, 0, ssize(w)) {
        if (not vecS[w[i] - 'a']) return "Aoki";
        else if (not vecT[w[i] - 'a']) return "Takahashi";
      };
      return "Unknown";
    };
    cout << f() << "\n";
  }

  return 0;
}

