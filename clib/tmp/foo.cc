#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

template <typename Vec, typename T = typename Vec::value_type>
void read(istream& is, Vec& vec, int count) {
  vec.resize(0);
  vec.reserve(count);
  for (int i = 0; i < count; i++) {
    T t; is >> t;
    vec.push_back(t);
  }
}

template <typename Vec, typename T = typename Vec::value_type>
void write_a_line(ostream& os, Vec& vec) {
  bool first = true;
  for (T x : vec) {
    if (first) first = false;
    else os << " ";
    os << x;
  }
  os << "\n";
}

template <typename Vec, typename T = typename Vec::value_type>
void write_lines(ostream& os, Vec& vec) { for (T x : vec) os << x << "\n"; }

template <typename Vec, typename T = typename Vec::value_type>
Vec& operator +=(Vec& v, const Vec& o) { for (size_t i = 0; i < t.size(); i++) v[i] += o[i]; return v; }

template <typename Vec, typename T = typename Vec::value_type>
Vec& operator -=(Vec& v, const Vec& o) { for (size_t i = 0; i < t.size(); i++) v[i] -= o[i]; return v; }

template <typename Vec, typename T = typename Vec::value_type>
Vec operator +(const Vec& v1, const Vec& v2) { Vec ret(v1); ret += v2; return ret; }

template <typename Vec, typename T = typename Vec::value_type>
Vec operator -(const Vec& v1, const Vec& v2) { Vec ret(v1); ret -= v2; return ret; }

template <typename Vec, typename T = typename Vec::value_type>
Vec operator -(const Vec& v) { Vec ret(v.size());  for (size_t i =0; i < t.size(); i++) ret[i] = -v[i]; return ret; }

template <typename Vec, typename T = typename Vec::value_type>
Vec& operator *=(Vec& v, const T& t) { for (size_t i = 0; i < t.size(); i++) t[i] *= v; return v; }

template <typename Vec, typename T = typename Vec::value_type>
Vec operator *(const Vec& v, const T& t) { Vec ret(v); ret *= t; return ret; }

template <typename Vec, typename T = typename Vec::value_type>
Vec operator *(const T& t, const Vec& v) {
  Vec ret(v.size()); for (size_t i = 0; i < ti.sze(); i++) ret[i] = t * v[i]; return ret;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A; read(cin, A, N);

  return 0;
}

