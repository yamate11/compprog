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

  ll N; cin >> N;
  set<string> pos, neg;
  REP(i, 0, N) {
    string s; cin >> s;
    if (s[0] == '!') {
      string t = s.substr(1);
      if (pos.contains(t)) {
        cout << t << "\n";
        return 0;
      }
      neg.insert(t);
    }else {
      if (neg.contains(s)) {
        cout << s << "\n";
        return 0;
      }
      pos.insert(s);
    }
  }
  cout << "satisfiable\n";
  return 0;
}

