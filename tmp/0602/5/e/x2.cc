#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <boost/multiprecision/cpp_int.hpp>
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

constexpr int primeA = 1'000'000'007;

using ci = boost::multiprecision::cpp_int;

ci my_gcd(ci a, ci b) {
  if (a < b) swap(a, b);
  while (b != 0) {
    ci x = a % b;
    a = b;
    b = x;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ci x = 1;
  REP2(i, 1, N + 1) {
    x *= i;
    // ci y = boost::math::gcd(x, primeA);
    ci y = my_gcd(x, primeA);
  }

}
