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

// @@ !! LIM(doubling)

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  
  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  { // ABC179-E  
    using vll = vector<ll>;
    auto func = [&](ll N, ll K, const vll& A) -> ll {
      auto d1 = DoublingFRel(K, N, [&](int i) -> int { return (i + A[i]) % N; });
      auto d2 = DoublingCum<ll>(d1, [&](int i) -> ll { return A[i]; });
      return d2.val(K, 0);
    };
    assert(func(5, 3, vll({2, 1, 6, 3, 1})) == 11);
    assert(func(10, 1000000000000, vll({260522, 914575, 436426, 979445, 648772, 690081, 933447, 190629, 703497, 47202})));
  }

  {
    ll n = 10;
    ll K = 100;
    ll rep = 1000;
    vector<ll> A(n), B(n);
    REP(i, 0, n) {
      A[i] = randrange(0, n);
      B[i] = randrange(0, (ll)1e9);
    }
    auto naive = [&](ll r, ll x) -> ll {
      REP(i, 0, r) x = A[x];
      return x;
    };
    auto naive2 = [&](ll r, ll x) -> ll {
      ll s = 0;
      REP(i, 0, r) {
        s += B[x];
        x = A[x];
      }
      return s;
    };
    auto d = DoublingFRel(K, n, [&](int i) -> int { return A[i]; });
    auto d2 = DoublingCum<ll>(d, [&](int i) -> ll { return B[i]; });
    REP(i, 0, rep) {
      ll r = randrange(0, K + 1);
      ll x = randrange(0, n);
      assert(naive(r, x) == d.val(r, x));
    }
    REP(i, 0, rep) {
      ll r = randrange(0, K + 1);
      ll x = randrange(0, n);
      assert(naive2(r, x) == d2.val(r, x));
    }
    REP(i, 0, rep) {
      ll k = randrange(1, K + 1);
      ll x = randrange(0, n);
      auto d3 = DoublingFRel(k, n, [&](int j) -> int { return A[j]; });
      assert(naive(k, x) == d3.val(k, x));
    }
    REP(i, 0, rep) {
      ll k = randrange(1, K + 1);
      ll x = randrange(0, n);
      auto d4 = DoublingFRel(k, n, [&](int j) -> int { return A[j]; });
      auto d5 = DoublingCum<ll>(d4, [&](int j) -> ll { return B[j]; });
      assert(naive2(k, x) == d5.val(k, x));
    }

  }

  cout << "ok" << endl;
  return 0;
}

