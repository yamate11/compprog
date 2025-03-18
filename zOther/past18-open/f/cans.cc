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

  string S; cin >> S;
  ll N; cin >> N;
  map<char, ll> mp;
  REP(i, 0, N) {
    char c; cin >> c;
    ll v; cin >> v;
    mp[c] = v;
  }
  ll val = 0;
  REP(i, -1, (ssize(S) - 1) / 2) {
    char op, opr;
    if (i == -1) {
      op = '+';
      opr = S[0];
    }else {
      op = S[2 * i + 1];
      opr = S[2 * i + 2];
    }
    ll vv;
    if ('0' <= opr and opr <= '9') vv = opr - '0';
    else vv = mp[opr];
    if (op == '+') val += vv;
    else val -= vv;
  }
  cout << val << endl;
  return 0;
}

