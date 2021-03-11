#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

template <class T>
class CHT {
  int size;
  vector<T> xs;
  vector<pair<T,T>> vec;
  unordered_map<T, int> mp;
  
  void putSub(T a, T b, int l, int r) {
    // cerr << "putSub " << l << " " << r << endl;
    int m = (l + r) / 2;
    T a0 = vec.at(m).first;
    T b0 = vec.at(m).second;
    T x = xs.at(m);
    if (isnan(a0)) {
      vec.at(m) = {a, b};
      return;
    }
    if (!(a0 * x + b0 >= a * x + b)) {
      vec.at(m) = {a, b};
      swap(a0, a);
      swap(b0, b);
    }
    if (!(a0 * xs.at(l) + b0 >= a * xs.at(l) + b)) {
      putSub(a, b, l, m-1);
    }else if (!(a0 * xs.at(r) + b0 >= a * xs.at(r) + b)) {
      putSub(a, b, m+1, r);
    }
  }

  T getSub(T ans, T x, int i, int l, int r) {
    // cerr << "getSub " << l << " " << r << endl;
    int m = (l + r) / 2;
    T a = vec.at(m).first;
    T b = vec.at(m).second;
    if (isnan(a)) return ans; 
    if (l == 0 && r == size-1) {
      ans = a * x + b;
    }else {
      ans = max(ans, a*x + b);
    }
    return (i == m) ? ans :
           (i <  m) ? getSub(ans, x, i, l, m-1) :
                      getSub(ans, x, i, m+1, r) ;
  }

public:
  CHT(const vector<T>& _xs)
        : size(_xs.size()), xs(_xs), vec(size, {nan(""), 0}) {
    sort(xs.begin(), xs.end());
    for (int i = 0; i < size; i++) {
      mp[xs.at(i)] = i;
    }
  }

  void put(T a, T b) {
    putSub(a, b, 0, size-1);
  }

  T get(T x) {
    int i = mp.at(x);
    return getSub(0, x, i, 0, size-1);
  }

};


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, C; cin >> N >> C;
  vector<ll> H(N);
  for (int i = 0; i < N; i++) cin >> H.at(i);
  
  /*
    (Hj-Hi)^2 + C
    dp[0] = 0
    dp[i] = min { dp[j] + (Hi - Hj)^2 + C | j < i }
          = Hi^2 + C + min { -2 Hi Hj + Hj^2 + dp[j] | j < i }
   */
  
  vector<ll> dp(N);
  dp.at(0) = 0;
  CHT<ll> cht(H);
  for (int i = 0; i < N-1; i++) {
    cht.put(-(-2 * H.at(i)), -(H.at(i) * H.at(i) + dp.at(i)));
    dp.at(i+1) = -cht.get(H.at(i+1)) + H.at(i+1) * H.at(i+1) + C;
  }
  cout << dp.at(N-1) << endl;

  return 0;
}

