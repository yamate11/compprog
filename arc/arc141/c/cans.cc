#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

struct my_exc : exception {};

void my_assert(bool b) {
  if (not b) throw my_exc();
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;

  auto func1 = [&](auto& P) {
    vector<ll> vec(2*N);
    ll i = 0;
    while (i < 2*N) {
      for (; i < 2*N and P[i] == i; i += 2) my_assert(P[i + 1] == i + 1);
      if (i == 2*N) break;
      for (ll p = i, q = i; q <= p; i += 2) {
        ll j = i + 1;
        my_assert(p < P[i]);
        my_assert(P[j] == q);
        p = P[i];
        vec[p] = 1;
        vec[q] = -1;
        for (; q < 2*N and vec[q] != 0; q++);
      }
    }
    return vec;
  };

  vector<ll> P, Q;
  P.reserve(2*N + 10);
  Q.reserve(2*N + 10);
  REP(i, 2*N) { ll p; cin >> p; p--; P.push_back(p); }
  REP(i, 2*N) { ll q; cin >> q; q--; Q.push_back(q); }
  try {
    auto vec1 = func1(P);
    vector<ll> R(2*N);
    REP(i, 2*N) R[i] = 2*N - 1 - Q[i];
    auto vec2 = func1(R);
    reverse(ALL(vec2));
    vector<ll> vec0(2*N);
    REP(i, 2*N) {
      if (vec1[i] == 0) {
        my_assert(vec2[i] != 0);
        vec0[i] = vec2[i];
      }else if (vec2[i] == 0) {
        vec0[i] = vec1[i];
      }else {
        my_assert(vec1[i] == vec2[i]);
        vec0[i] = vec1[i];
      }
    }
    auto check = [&](auto& vec, ll sgn) -> void {
      for (ll i = 0; true; ) {
        for ( ; i < 2*N and vec[i] != 0; i++);
        if (i == 2*N) return;
        ll j = 0;
        for (j = i + 1; j < 2*N and vec[j] == 0; j++);
        ll diff = 0;
        REP2(k, i, j) {
          diff += sgn * vec0[k];
          my_assert(diff >= 0);
        }
        my_assert(diff == 0);
        i = j;
      }
    };
    check(vec1, 1);
    check(vec2, -1);
    REP(i, 2*N) cout << (vec0[i] == 1 ? "(" : ")");
    cout << endl;
  }catch(my_exc& e) {
    cout << -1 << endl; 
  }
  return 0;
}



