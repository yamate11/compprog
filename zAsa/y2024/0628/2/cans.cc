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

  string X;
  cin >> X;
  vector<ll> revX(26);
  REP(i, 0, 26) revX[X[i] - 'a'] = i;
  ll N; cin >> N;
  vector A(N, string());
  REP(i, 0, N) {
    string s; cin >> s;
    for (char c : s) A[i].push_back('a' + revX[c - 'a']);
  }
  sort(ALL(A));
  REP(i, 0, N) {
    string t;
    for (char c : A[i]) t.push_back(X[c - 'a']);
    cout << t << "\n";
  }


  return 0;
}

