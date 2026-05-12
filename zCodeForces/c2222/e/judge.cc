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

void ac() {
  cout << "# AC" << endl;
  exit(0);
}

void wa(string msg = "") {
  cout << "# WA: " << msg << endl;
  exit(1);
}

int main(/* int argc, char *argv[] */) {
  ll T = 1;
  cout << T << endl;
  ll N, k, c; cin >> N >> k >> c;
  cout << N << endl;
  set<ll> ss;
  ll a; cin >> a;
  ss.insert(a);
  ll qcnt = 0;
  while (true) {
    string s; cin >> s;
    if (s == "I") {
      ll x; cin >> x;
      ll y;
      if      (k == 1) y = x & c;
      else if (k == 2) y = x | c;
      else if (k == 3) y = x ^ c;
      else assert(0);
      ss.insert(y);
      cout << ssize(ss) << endl;
      qcnt++;
    }else if (s == "Q") {
      ll x; cin >> x;
      ll cnt = 0;
      for (ll t : ss) if (x <= t) cnt++;
      cout << cnt << endl;
      qcnt++;
    }else if (s == "A") {
      ll k_ans, c_ans; cin >> k_ans >> c_ans;
      if (qcnt <= N + 3 and k == k_ans and c == c_ans) ac();
      else wa();
    }else assert(0);
  }

  return 0;
}

