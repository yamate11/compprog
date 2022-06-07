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

/*
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
*/

ll my_gcd(BI a, ll b) {
  return std::gcd((a % b).convert_to<ll>(), b);
}

BI my_lcm(BI a, ll b) {
  return a * (b / my_gcd(a, b));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  BI l = 1;
  for (ll i = 0; i < N; i++) l = my_lcm(l, A[i]);
  mint ans = 0;
  for (ll i = 0; i < N; i++) ans += (l / A[i] % primeA).convert_to<ll>();
  cout << ans.val() << endl;

  return 0;
}

