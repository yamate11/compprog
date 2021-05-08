#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(cht)

// ---- inserted library file cht.cc

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

// ---- end cht.cc

// @@ !! LIM -- end mark --

int main() {

  CHT<int> cht1(vector<int>({-10, 0, 10}));
  cht1.put(0, 3);
  assert(cht1.get(0) == 3);
  cht1.put(-1, 4);
  assert(cht1.get(0) == 4);
  assert(cht1.get(10) == 3);
  assert(cht1.get(-10) == 14);
  cht1.put(1, 2);
  assert(cht1.get(0) == 4);
  assert(cht1.get(10) == 12);
  assert(cht1.get(-10) == 14);

  // Compare the results with naively computed values
  mt19937_64 mt(1234);
  uniform_int_distribution<int> randN(2, 1000), randD(0, 1);
  uniform_real_distribution<double> randA(-1, 1), randB(-1, 1), randX(0, 1);
  for (int zz = 0; zz < 100; zz++) {
    int n = randN(mt);
    vector<double> as(n), bs(n), xs(n);
    vector<bool> eff(n);
    for (int i = 0; i < n; i++) {
      as.at(i) = randA(mt);
      bs.at(i) = randB(mt);
      xs.at(i) = randX(mt);
    }
    CHT<double> chtC(xs);
    for (int i = 0; i < n; i++) {
      if (i == 0 || randD(mt) == 0) {
	chtC.put(as.at(i), bs.at(i));
	eff.at(i) = true;
      }
      if (randD(mt) == 0) {
	double x = xs.at(i);
	double v = 0;
	for (int j = 0; j <= i; j++) {
	  if (!eff.at(j)) continue;
	  double y = as.at(j) * x + bs.at(j);
	  if (j == 0) v = y;
	  else        v = max(v, y);
	}
	assert(v == chtC.get(x));
      }
    }
  }
  
  return 0;
}
