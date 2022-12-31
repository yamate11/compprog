#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define InpVec(vec, n) vector<ll> vec(n); REP(i, 0, (n)) cin >> vec[i]
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

constexpr ll g1(ll x) { return x * 100; }

template<typename F = negate<ll>>
struct A {
  ll a;
  F f;
  A() : f(F()) {}
  A(F f_) : f(f_) {}
  ll func() { return f(a); }
};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  A a1;
  a1.a = 50;
  cout << a1.func() << endl;
  auto g = [&](ll x) { return x + 100; };
  A<decltype(g)> a(g);
  a.a = 40;
  cout << a.func() << endl;

  A<decltype(&g1)> a2(&g1);
  a2.a = 30;
  cout << a2.func() << endl;

  cout << "sizes " << sizeof(a1) << " " << sizeof(a) << " " << sizeof(a2) << endl;

  set<ll> ss;
  cout << "sizeof ss " << sizeof(ss) << endl;
  vector<ll> v1;
  cout << "sizeof v1 " << sizeof(v1) << endl;
  

  /*
  auto fcmp = [&](ll a, ll b) -> bool { return b < a; };
  set<ll, decltype(fcmp)> ss({2, 70, 5}, fcmp);
  for (ll a : ss) cout << a << endl;
  */

  /*
  vector<int> x({1000, 0, 500, 0, 300});
  auto comp = [&](int i, int j) { return x.at(i) < x.at(j); };
  priority_queue<int, vector<int>, decltype(comp)> pque(comp);
  pque.push(1);
  pque.push(0);
  cout << pque.top() << endl;
  */

  return 0;
}
