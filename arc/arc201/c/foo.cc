#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

template<typename T>
struct A {
  int x = 0;
  inline static A the_instance;

  static A* get_def_obj() { return &the_instance; }
  void dummy() {}

};

int main() {
  auto pa = new A<int>();
  auto pb = new A<int>();
  pb = nullptr;
  assert(pa->get_def_obj() == pb->get_def_obj());
  cerr << "hello" << endl;
  pb->dummy();

  return 0;
}
