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

  ll Q; cin >> Q;
  ll vol = 0;
  bool playing = false;
  REP(_q, 0, Q) {
    ll a; cin >> a;
    if (a == 1) {
      vol++;
    }else if (a == 2) {
      if (vol >= 1) vol--;
    }else if (a == 3) {
      playing = not playing;
    }else assert(0);
    if (vol >= 3 and playing) {
      cout << "Yes\n";
    }else {
      cout << "No\n";
    }
  }

  return 0;
}

