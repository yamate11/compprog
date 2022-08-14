#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

using pll = pair<ll, ll>;

template<typename T>
ostream& spout(ostream& ostr, const T& coll) {
  for (auto it = coll.cbegin(); it != coll.cend(); ++it) {
    if (it != coll.cbegin()) ostr << " ";
    ostr << *it;
  }
  ostr << "\n";
  return ostr;
}

template<typename T>
ostream& nlout(ostream& ostr, const T& coll) {
  for (auto it = coll.cbegin(); it != coll.cend(); ++it) ostr << *it << "\n";
  return ostr;
}

#define REPOUT(ostr, i, from, to, exp, sep) for (ll i = (from); i < (to); i++) { \
    if (i != (from)) ostr << (sep); ostr << (exp); } ostr << "\n";

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> A{2, 5, 7, 3, -4};
  spout(cout, A);
  nlout(cout, A);
  copy(ALL(A), ostream_iterator<ll>(cout, " "));
  cout << endl;
  const ll big = 1e18;
  REPOUT(cout, i, 0, SIZE(A), A[i] >= big ? -1 : A[i], ' ');
  REPOUT(cout, i, 0, SIZE(A), A[i] >= big ? -1 : A[i], '\n');
  return 0;
}

