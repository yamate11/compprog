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

  vector<ll> vec{6, 12, 2, 10, 3, 9, 4, 8};

  ll N; cin >> N;
  if (N == 3) {
    cout << "2 5 63\n";
    return 0;
  }
  if (N == 4) {
    cout << "2 3 9 10\n";
    return 0;
  }
  if (N == 5) {
    cout << "2 3 6 9 10\n";
    return 0;
  }
  if (N == 6) {
    cout << "2 3 6 9 10 12\n";
    return 0;
  }
  vector<ll> ans;
  ll p = N / 8;
  ll q = N % 8;
  if (q % 2 == 0) {
    REP(i, 0, q) ans.push_back(vec[i]);
  }else {
    REP(i, 1, q + 1) ans.push_back(vec[i]);
  }
  if (q == 0) {
    REP(i, 0, p) {
      REP(j, 0, 8) ans.push_back(12 * i + vec[j]);
    }
  }else {
    REP(i, 1, p + 1) {
      REP(j, 0, 8) ans.push_back(12 * i + vec[j]);
    }
  }
  REPOUT(i, 0, ssize(ans), ans[i], " ");
  return 0;
}

