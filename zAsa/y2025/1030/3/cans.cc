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

  string T("AKIHABARA");
  string S; cin >> S;

  vector<ll> p{0, 4, 6, 8};
  REP(x, 0, 16) {
    string a = T;
    REP(i, 0, 4) if (x >> i & 1) a[p[i]] = '.';
    string y;
    for (char c : a) if (c != '.') y += c;
    if (S == y) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";



  
  return 0;
}

