#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(f:updMaxMin)
// --> f:updMaxMin
// ---- inserted function updMaxMin from util.cc
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
// ---- end updMaxMin
// @@ !! LIM  -- end mark --

template <typename T>
vector<T> read_vector(istream& is) {
  size_t n; is >> n;
  vector<T> ret(n);
  for (size_t i = 0; i < n; i++) is >> ret[i];
  return ret;
}

template <typename T>
istream& operator>> (istream& is, vector<T>& v) {
  for (size_t i = 0; i < v.size(); i++) is >> v[i];
  return is;
}

template <typename T1, typename T2, typename T3>
istream& operator>> (istream& is, tuple<T1,T2,T3>& t) {
  is >> get<0>(t) >> get<1>(t) >> get<2>(t);
  return is;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using info_t = tuple<ll, ll, ll>;
  auto info = read_vector<info_t>(cin);
  ll N = info.size();
         
  sort(info.begin(), info.end());
  const ll lim = 5000;
  auto cur = vector(lim + 1, -1LL);
  cur[0] = 0;
  for (ll i = 0; i < N; i++) {
    auto [d, c, s] = info[i];
    for (ll j = d - c; j >= 0; j--) {
      if (cur[j] < 0) continue;
      updMax(cur[j + c], cur[j] + s);
    }
  }
  auto it = max_element(cur.begin(), cur.end());
  cout << *it << endl;

  return 0;
}

