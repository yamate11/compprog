#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(cht)

template<typename T, typename D, bool obt_max>
struct NaiveCHT {
  vector<T> vecA;
  vector<T> vecB;
  
  bool compare(D x, D y) {
    if constexpr (obt_max) return less<D>()(x, y);
    else                   return greater<D>()(x, y);
  }

  void insert(T a, T b) {
    vecA.push_back(a);
    vecB.push_back(b);
  }

  T query(T x) {
    T ans = vecA[0] * x + vecB[0];
    for (size_t i = 1; i < vecA.size(); i++) {
      T v = vecA[i] * x + vecB[i];
      if (compare(ans, v)) ans = v;
    }
    return ans;
  }
};
  

random_device rd;
mt19937_64 rng(rd());
ll randrange(ll i, ll j) {
  uniform_int_distribution<ll> dist(i, j - 1);
  return dist(rng);
}
  
template<bool dir>
void test_rnd() {
  const ll rep_out = 500;
  const ll rep_in = 500;
  const double ratio = 0.4;
  for (size_t i = 0; i < rep_out; i++) {
    CHT<ll, double, dir> cht;
    NaiveCHT<ll, double, dir> ncht;
    const ll range_min = randrange(-100, 101);
    const ll range_size = randrange(1, 100);
    auto g = [&]() -> ll { return randrange(range_min, range_min + range_size); };
    // DLOG("---------------");
    for (size_t j = 0; j < rep_in; j++) {
      if (j == 0 or randrange(0, 100000) < ratio * 100000) {
        ll a = g(), b = g();
        cht.insert(a, b);
        ncht.insert(a, b);
        // DLOGKL("** insert **", a, b);
      }else {
        ll x = g();
        if (cht.query(x) != ncht.query(x)) {
          cerr << "****** different ******  " << x << " " <<  cht.query(x) << " " <<  ncht.query(x) << endl;
          assert(0);
        }
      }
    }
  }
}

void test() {

  {
    CHT<ll, double, true> cht;
    cht.insert(2, 0);
    cht.insert(-2, 60);
    cht.insert(0, 40);
    assert(cht.query(3) == 54);
    assert(cht.query(15) == 40);
    assert(cht.query(21) == 42);

    CHT<ll, double, false> chtMin;
    chtMin.insert(2, 0);
    chtMin.insert(-2, 60);
    chtMin.insert(0, 40);
    assert(chtMin.query(3) == 6);
    assert(chtMin.query(15) == 30);
    assert(chtMin.query(21) == 18);
  }

}

void test2() {
  CHT<int, double, true> cht;
  cht.insert(0, 3);
  assert(cht.query(0) == 3);
  cht.insert(-1, 4);
  assert(cht.query(0) == 4);
  assert(cht.query(10) == 3);
  assert(cht.query(-10) == 14);
  cht.insert(1, 2);
  assert(cht.query(0) == 4);
  assert(cht.query(10) == 12);
  assert(cht.query(-10) == 14);
}


int main() {

  test();
  test2();
  test_rnd<true>();
  test_rnd<false>();

  return 0;
}
