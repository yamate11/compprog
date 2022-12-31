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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto rem = [](ll i, ll j) -> ll {
    vector b(3, 0);
    b[i] = b[j] = 1;
    REP(k, 0, 3) if (b[k] == 0) return k;
    assert(0);
  };

  ll N; cin >> N;
  vector<ll> X(3);
  REP(i, 0, 3) cin >> X[i];
  ll p = 0;
  vector<ll> ans;
  auto read1 = [&]() -> tuple<ll, ll, ll> {
    string s; cin >> s;
    ll i = s[0] - 'A';
    ll j = s[1] - 'A';
    ll k = rem(i, j);
    return make_tuple(i, j, k);
  };
  auto move1 = [&](ll i, ll j) -> void {
    p++;
    ans.push_back(j);
    X[i]--;
    X[j]++;
  };
  auto go_on = [&]() -> void {
    while (p < N) {
      auto [i, j, k] = read1();
      if (X[k] > 0 or p == N - 1) {
        if (X[i] > 0) move1(i, j);
        else if (X[j] > 0) move1(j, i);
        else assert(0);
      }else {
        auto [i2, j2, k2] = read1();
        if (k2 == i) {
          move1(i, j); move1(j, k);
        }else if (k2 == j) {
          move1(j, i); move1(i, k);
        }else {
          move1(i, j); move1(j, i);
        }
      }
    }
  };
  if (X[0] == 0 and X[1] == 0 and X[2] == 0) {
    cout << "No\n";
    return 0;
  } else if (X[0] + X[1] + X[2] == 1) {
    REP(_p, 0, N) {
      auto [i, j, k] = read1();
      if (X[i] == 0 and X[j] == 0) {
        cout << "No\n";
        return 0;
      }else if (X[i] > 0) move1(i, j);
      else move1(j, i);
    }
  }else if ((X[0] == 0 and X[1] == 0) or (X[1] == 0 and X[2] == 0) or (X[2] == 0 and X[0] == 0)) {
    auto [i, j, k] = read1();
    if (X[i] == 0 and X[j] == 0) {
      cout << "No\n";
      return 0;
    }
    if (X[i] == 0) move1(j, i);
    else move1(i, j);
    go_on();
  }else {
    go_on();
  }
  cout << "Yes\n";
  REPOUT(i, 0, N, (char)(ans[i] + 'A'), "\n");


  return 0;
}

