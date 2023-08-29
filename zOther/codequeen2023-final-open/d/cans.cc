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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto func = [&](ll X, ll Y, ll xs, ll ys, ll xt, ll yt) -> ll {
    ll ret = 0;
    REP(x, 0, X) {
      if (xs == x or xt == x) {
        if (xs == xt) {
          if (ys == yt) ret += (Y - 1) * (Y - 2);
          else ret += (Y - 2) * (Y - 3) + 1 * (Y - 2) + 1 * (Y - 2) + 1 * 1;
        }else {
          ll y_th = (xs == x) ? ys : yt;
          ll y_ot = (xs == x) ? yt : ys;
          for (ll y : vector<ll>{y_ot, y_ot - abs(xt - xs), y_ot + abs(xt - xs)}) {
            if (0 <= y and y < Y) {
              if (y_th == y) {
                ret += Y - 1;
              }else {
                ret += Y - 2;
              }
            }
          }
        }
      }else {
        for (ll y1 : vector<ll>{ys, ys - abs(x - xs), ys + abs(x + xs)}) {
          if (y1 < 0 or Y <= y1) continue;
          for (ll y2 : vector<ll>{yt, yt - abs(x - xt), yt + abs(x - xt)}) {
            if (y2 < 0 or Y <= y2) continue;
            if (y1 == y2) continue;
            ret++;
          }
        }
      }
    }
    REP(k, 0, X + Y - 1) {
      ll xmin = max(0, k - Y + 1);
      ll xmax = min(k, X - 1);
      ll len = xmax - xmin + 1;
      if (xs + ys == k and xt + yt == k) {
        if (xs == xt) {
          ret += (len - 1) * (len - 2);
        }else {
          ret += (len - 2) * (len - 3) + 1 * (len - 2) + 1 * (len - 2) + 1 * 1;
        }
      }else if (xs + ys == k and xt + yt != k) {
        for (ll x : 
      }else if (xs + ys != k and xt + yt == k) {
      }else {
      }
    }



  };

  ll R, C, rs, cs, rt, ct; cin >> R >> C >> rs >> cs >> rt >> ct; rs--; cs--; rt--; ct--;
  ll a = func(R, C, rs, cs, rt, ct);
  ll b = func(C, R, cs, rs, ct, rt);
  cout << a + b << endl;


  return 0;
}

