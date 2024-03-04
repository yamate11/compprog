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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

ll ask(ll a, ll b, ll c, ll d) {
  cout << "? " << a << " " << b << " " << c << " " << d << endl;
  char ch; cin >> ch;
  if (ch == '<') return -1;
  else if (ch == '=') return 0;
  else return 1;
}

void fin(ll a, ll b) {
  cout << "! " << a << " " << b << endl;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N; cin >> N;
    ll vmax = 0;
    REP(i, 1, N) {
      ll r = ask(vmax, vmax, i, i);
      if (r == -1) {
        vmax = i;
      }
    }
    ll wmax = (vmax == 0) ? 1 : 0;
    vector<ll> cand;
    cand.push_back(wmax);
    REP(i, wmax + 1, N) {
      if (i == vmax) continue;
      ll r = ask(vmax, wmax, vmax, i);
      if (r == -1) {
        wmax = i;
        cand.resize(0);
        cand.push_back(wmax);
      }else if (r == 0) {
        cand.push_back(i);
      }
    }
    ll xmin = cand[0];
    REP(i, 1, SIZE(cand)) {
      ll r = ask(xmin, xmin, cand[i], cand[i]);
      if (r == 1) {
        xmin = cand[i];
      }
    }
    fin(vmax, xmin);
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

