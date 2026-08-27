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

// @@ !! LIM(f:updMaxMin)

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

template<typename T>
struct base_vector {
  int base;
  vector<T>& body;
  base_vector(int base_, vector<T>& body_) : base(base_), body(body_) {}
  const T& operator[](int i) const { return body[i - base]; }
  T& operator[](int i) { return body[i - base]; }
};

template<typename T>
base_vector<T> make_base_vector(int start, int end, const T& val) {
  vector<T>* body = new vector(end - start, val);
  return base_vector(start, *body);
}


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  auto A = make_base_vector(-1, N + 1, 0LL);
  REP(i, 0, N) cin >> A[i];

  ll big = 1LL << 60;
  auto B = make_base_vector(-1, N + 1, -big);
  B[0] = 0;
  REP(i, 1, N + 1) {
    updMax(B[i], B[i - 2]);
    updMax(B[i], B[i - 1] + A[i - 1]);
    updMax(B[i], B[i - 2] + A[i - 2] + A[i - 1]);
  }


  cout << B[N] << endl;
  return 0;
}

