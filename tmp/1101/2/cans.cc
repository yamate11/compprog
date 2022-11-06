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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string X; cin >> X;
  vector<ll> ord(26);
  vector<ll> revord(26);
  REP(i, 0, 26) {
    ord[X[i] - 'a'] = i;
    revord[i] = X[i] - 'a';
  }
  auto g = [&](char c) -> char {
    return (char)('a' + ord[c - 'a']);
  };
  auto f = [&](string s) -> string {
    string ret;
    for (char c : s) ret += g(c);
    return ret;
  };
  auto h = [&](char c) -> char {
    return (char)('a' + revord[c - 'a']);
  };
  auto revF = [&](string s) -> string {
    string ret;
    for (char c : s) ret += h(c);
    return ret;
  };

  ll N; cin >> N;
  using sta = pair<string, string>;
  vector<sta> ST(N);
  REP(i, 0, N) {
    string s; cin >> s;
    ST[i] = {f(s), s};
  }
  sort(ALL(ST));
  REPOUT(i, 0, N, ST[i].second, "\n");

  return 0;
}

