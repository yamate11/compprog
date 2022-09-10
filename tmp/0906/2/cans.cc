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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  set<string> pos, neg;
  REP(i, 0, N) {
    string s; cin >> s;
    if (s[0] == '!') neg.insert(s.substr(1));
    else pos.insert(s);
  }
  for (auto s : pos) {
    if (neg.find(s) != neg.end()) {
      cout << s << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;

  return 0;
}

