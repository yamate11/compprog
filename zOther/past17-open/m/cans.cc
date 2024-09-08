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

  double big = 1e18;

  auto f = [&](ll loA, ll hiA, ll loB, ll hiB, ll vel) -> pair<double, double> {
    if (vel == 0) {
      if (hiA <= loB or hiB <= loA) return {-1.0, -1.0};
      else return {0.0, big};
    }
    if (vel < 0) {
      vel = -vel;
      swap(loA, loB);
      swap(hiA, hiB);
    }
    if (hiA <= loB) return {-1.0, -1.0};
    double end = (double)(hiA - loB) / vel;
    double start;
    if (hiB <= loA) {
      start = (double)(loA - hiB) / vel;
    }else {
      start = 0.0;
    }
    return {start, end};
  };

  ll p1, q1, r1, s1, u1, v1; cin >> p1 >> q1 >> r1 >> s1 >> u1 >> v1;
  ll p2, q2, r2, s2, u2, v2; cin >> p2 >> q2 >> r2 >> s2 >> u2 >> v2;
  
  auto [t1, t2] = f(p1, r1, p2, r2, u2 - u1);
  auto [t3, t4] = f(q1, s1, q2, s2, v2 - v1);
  cout << max(0.0, min(t2, t4) - max(t1, t3)) << endl;

  return 0;
}

