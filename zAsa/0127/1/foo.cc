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


template <typename I>
struct EnumDirProd {
  int n;
  vector<I> lim;
  vector<int> vec;
  bool started;

  EnumDirProd(const vector<I>& lim_) : n(size(lim_)), lim(lim_), vec(n), started(false) {}
  EnumDirProd(vector<I>&& lim_) : n(size(lim_)), lim(move(lim_)), vec(n), started(false) {}

  int at(int i) const { return vec[i]; }

  const vector<int>& vec_view() const { return vec; }

};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  

  return 0;
}

