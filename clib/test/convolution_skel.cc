#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#if TEST_CONSTANT_MOD
  #define CONSTANT_MOD 998244353
#endif

// @@ !! LIM(convolution)

template<typename T>
vector<T> naive_convolution(const vector<T>& x, const vector<T>& y) {
  ll nx = x.size();
  ll ny = y.size();
  vector<T> z(nx + ny - 1);
  for (ll i = 0; i < nx; i++) {
    for (ll j = 0; j < ny; j++) {
      z[i + j] += x[i] * y[j];
    }
  }
  return z;
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<int> dist1(61, 130);
  uniform_int_distribution<int> dist2(-10000, 10000);
  uniform_int_distribution<int> dist3(0, 998'244'353 - 1);

#if CONSTANT_MOD
  
  cout << "testing constant mod ..." << endl;

  {
    vector<Fp> vecA({1, 2, 3, 4});
    vector<Fp> vecB({-1, 0, 1, 2});
    auto res1 = convolution(vecA, vecB);
    auto res2 = naive_convolution(vecA, vecB);
    if (res1 != res2) {
      DLOGK_LIB(res1);
      DLOGK_LIB(res2);
      assert(res1 == res2);
    }
  }

  {
    ll loopcnt = 1000;
    while (loopcnt--) {
      ll sza = dist1(rng);
      ll szb = dist1(rng);
      vector<Fp> vecA;
      vector<Fp> vecB;
      for (ll j = 0; j < sza; j++) vecA.push_back(dist3(rng));
      for (ll j = 0; j < szb; j++) vecB.push_back(dist3(rng));
      auto res1 = convolution(vecA, vecB);
      auto res2 = naive_convolution(vecA, vecB);
      if (res1 != res2) {
        DLOGK_LIB(res1);
        DLOGK_LIB(res2);
      }
      assert(res1 == res2);
    }
  }

#else  

  cout << "testing variable mod ..." << endl;

  if (1) {
    Fp::MOD = 754974721;
    vector<Fp> vecA({1, 2, 3, 4});
    vector<Fp> vecB({-1, 0, 1, 2});
    auto res1 = convolution(vecA, vecB);
    DLOGK_LIB(res1);
  }

  if (1){
    Fp::MOD = 998'244'353;
    vector<Fp> vecA({1, 2, 3, 4});
    vector<Fp> vecB({-1, 0, 1, 2});
    auto res1 = convolution(vecA, vecB);
    auto res2 = naive_convolution(vecA, vecB);
    if (res1 != res2) {
      DLOGK_LIB(res1);
      DLOGK_LIB(res2);
      assert(res1 == res2);
    }
  }

  if (1) {
    vector<ll> vecA({1, 2, 3, 4});
    vector<ll> vecB({-1, 0, 1, 2});
    auto res1 = convolution_ll(vecA, vecB);
    auto res2 = naive_convolution(vecA, vecB);
    if (res1 != res2) {
      DLOGK_LIB(res1);
      DLOGK_LIB(res2);
      assert(res1 == res2);
    }
  }

  if (1){
    Fp::MOD = 998'244'353;
    ll loopcnt = 1000;
    while (loopcnt--) {
      ll sza = dist1(rng);
      ll szb = dist1(rng);
      vector<Fp> vecA;
      vector<Fp> vecB;
      for (ll j = 0; j < sza; j++) vecA.push_back(dist3(rng));
      for (ll j = 0; j < szb; j++) vecB.push_back(dist3(rng));
      auto res1 = convolution(vecA, vecB);
      auto res2 = naive_convolution(vecA, vecB);
      if (res1 != res2) {
        DLOGK_LIB(res1);
        DLOGK_LIB(res2);
      }
      assert(res1 == res2);
    }
  }

  if (1){
    ll loopcnt = 1000;
    while (loopcnt--) {
      ll sza = dist1(rng);
      ll szb = dist1(rng);
      sza = 64;
      szb = 64;
      vector<ll> vec1;
      vector<ll> vec2;
      for (ll j = 0; j < sza; j++) vec1.push_back(dist2(rng));
      for (ll j = 0; j < szb; j++) vec2.push_back(dist2(rng));
      auto res1 = convolution_ll(vec1, vec2);
      auto res2 = naive_convolution(vec1, vec2);
      if (res1 != res2) {
        DLOGK_LIB(res1);
        DLOGK_LIB(res2);
      }
      assert(res1 == res2);
    }
  }
#endif

  cout << "ok" << endl;
  return 0;
}
  
