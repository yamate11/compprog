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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  deque<int> deq{1, 2, 3, 4};
  REP(i, 0, 4) {
    cout << deq[i] << " ";
  }
  cout << endl;
  string ret = "[";
  for (auto it = deq.begin(); it != deq.end(); it++) {
    if (it != deq.begin()) ret += ", ";
    ret += to_string(*it);
  }
  ret += "]";
  cout << ret << endl;

  enum MyEnum { FOO, BAR };
  MyEnum x = FOO;
  MyEnum y = BAR;
  cout << x << " " << y << endl;

  return 0;
}

