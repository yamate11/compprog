#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/modint>
using namespace atcoder;

constexpr ll primeA = 1000000007;
using mint = modint1000000007;
using BI = boost::multiprecision::cpp_int;

BI my_gcd(BI a, BI b) {
  if (a < b) swap(a, b);
  while (b != 0) {
    BI x = a % b;
    a = b;
    b = x;
  }
  return a;
}

BI my_lcm(BI a, BI b) {
  return a * (b / my_gcd(a, b));
}

int main() {

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  BI l = 1;
  mint ans = 0;
  for (ll i = 0; i < N; i++) {
    ll g = boost::math::gcd(l, A[i]).convert_to<ll>();
    // ll g = my_gcd(l, A[i]).convert_to<ll>();
    ll z = A[i] / g;
    ans = ans * z + mint((l / g % primeA).convert_to<ll>());
    l *= z;
  }
  cout << ans.val() << endl;

  return 0;
}

