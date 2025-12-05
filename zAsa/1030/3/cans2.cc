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

  ll idx = 0;
  REP(i, 0, ssize(T)) {
    if (idx < ssize(S) and T[i] == S[idx]) idx++;
    else {
      if (T[i] == 'A');
      else {
        cout << "NO\n";
        return 0;
      }
    }
  }
  if (idx == ssize(S)) {
    cout << "YES\n";
  }else {
    cout << "NO\n";
  }
  
  return 0;
}

