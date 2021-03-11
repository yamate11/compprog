#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()
// --> 
// @@ !! LIM  -- end mark --

template <typename T, typename Fop>
struct Doubling {
  vector<int> nxt;   // g |-> nxt[g]
  int size;
  vector<T> alpha;
  T unit; // monoid unit
  Fop op; // monoid operation   op :: T -> T -> T
  int height;
  vector<vector<int>> tblP;
  vector<vector<T>> tblQ;

  void precalc() {
    tblP = vector(height, vector<int>(size));
    tblP[0] = move(nxt);
    tblQ = vector(height, vector<T>(size));
    tblQ[0] = move(alpha);
    for (ll i = 1; i < height; i++) {
      for (ll j = 0; j < size; j++) {
	ll x = tblP[i-1][j];
	tblP[i][j] = tblP[i-1][x];
	tblQ[i][j] = op(tblQ[i-1][j], tblQ[i-1][x]);
      }
    }
    /*
    DLOG("height=", height);
    DLOG("tblP=", tblP);
    DLOG("tblQ=", tblQ);
    */
  }

  Doubling(ll lim_, vector<int>&& nxt_, vector<T>&& alpha_, T unit_, Fop op_)
    : nxt(nxt_), size(nxt.size()), alpha(alpha_),
      unit(unit_), op(op_), height(64 - __builtin_clzll(lim_)) {
    precalc();
  }

  Doubling(ll lim_, const vector<int>& nxt_, const vector<T>& alpha_,
	   T unit_, Fop op_)
    : nxt(nxt_), size(nxt.size()), alpha(alpha_),
      unit(unit_), op(op_), height(64 - __builtin_clzll(lim_)) {
    precalc();
  }

  T calc(int x, ll y) {
    int cur = x;
    T sum = unit;
    ll hy = 64 - __builtin_clzll(y);
    if (hy > height) {
      cerr << "Fatal: calc(): hy (" << hy << ") > height("
	   << height << ")" << endl;
      exit(1);
    }
    for (ll i = 0; i < hy; i++) {
      if ((y >> i) & 1) {
	sum = op(sum, tblQ[i][cur]);
	cur = tblP[i][cur];
      }
    }
    return sum;
  }
};

template<typename T>
auto make_doubling(ll lim, auto&& nxt, auto&& alpha, T unit, auto op)
  -> Doubling<T, decltype(op)> {
  return Doubling(lim, move(nxt), move(alpha), unit, op);
}

template<typename T>
auto make_doubling(ll lim, const auto& nxt, const auto& alpha, T unit, auto op)
  -> Doubling<T, decltype(op)> {
  return Doubling(lim, nxt, alpha, unit, op);
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  { // ABC179-E  

    auto func = [&](ll N, ll X, ll M) -> ll {
      vector<int> nxt(M);
      using T = ll;
      vector<T> alpha(M);
      for (ll i = 0; i < M; i++) {
	nxt[i] = i * i % M;
	alpha[i] = i;
      }
      auto op = [](T x, T y) { return x + y; };
      auto dbl = make_doubling(N, move(nxt), move(alpha), 0LL, op);
      return dbl.calc(X, N);
    };
    auto naive = [&](ll N, ll X, ll M) -> ll {
      ll sum = 0;
      ll cur = X;
      for (ll i = 1; i <= N; i++) {
	sum += cur;
	cur = cur * cur % M;
      }
      return sum;
    };

    assert(func(6, 2, 1001) == 1369);
    assert(func(1000, 2, 16) == 6);
    assert(func(10000, 418, 725) == 11140);
    for (ll n = 1; n <= 20; n++) {
      for (ll m = 1; m < 20; m++) {
	for (ll x = 0; x < m; x++) {
	  assert(func(n, x, m) == naive(n, x, m));
	}
      }
    }

  }
  return 0;
}

