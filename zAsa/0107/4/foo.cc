#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

struct X {
  int a;
  X(int a_ = 0) : a(a_) { cout << "X()" << " " << a << endl; }
};

vector<X> vvec;

X& foo(int i) {
  return vvec[i];
}
  
X bar(int i) {
  return vvec[i];
}


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  REP(i, 0, 10) vvec.push_back(X());
  X& x1 = foo(3);
  const X& x2 = bar(4);
  x1.a = 100;
  x2.a = 200;
  REP(i, 0, 10) cout << i << " " << vvec[i].a << endl;
  

  return 0;
}

