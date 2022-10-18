#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(forall)

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    vector<ll> vec1 = {10, -5, 3, 4, -6, 2};
    assert(FORALL(i, 0, SIZE(vec1), vec1[i] <= 10));
    assert(not FORALL(i, 0, SIZE(vec1), vec1[i] >= 0));
    assert(EXISTS(i, 0, SIZE(vec1), vec1[i] <= -6));
    assert(not EXISTS(i, 0, SIZE(vec1), vec1[i] < -6));
    assert(EXFIND(i, 0, SIZE(vec1), vec1[i] < 0) == 1);
    assert(EXFIND_D(i, 0, SIZE(vec1), vec1[i] < -10, -1LL) == -1LL);
    assert(not FORALL(i, 0, SIZE(vec1), -6 <= vec1[i] and vec1[i] <= 5));
    assert(COUNT(i, 0, SIZE(vec1), vec1[i] % 2 == 0) == 4);
    assert(COUNT(i, 0, SIZE(vec1) - 1, vec1[i] < vec1[i + 1]) == 3);
  }
  {
    vector<ll> vec1 = {10, -5, 3, 4, -6, 2};
    assert(FORALL_C(x, vec1, x <= 10));
    assert(not FORALL_C(x, vec1, x >= 0));
    assert(EXISTS_C(x, vec1, x <= -6));
    assert(not EXISTS_C(x, vec1, x < -6));
    assert(EXFIND_C(x, vec1, x < 0) == -5);
    assert(EXFIND_D_C(x, vec1, x < -10, 100LL) == 100);
  }
  {
    auto func = [&](ll x, ll a) -> ll { return (x - 3) * (x - 3) + a; };
    assert(FORALL(x, 0, 7, func(x, 1) >= 1));
    assert(EXISTS(x, 0, 7, func(x, 1) < 2));
    assert(FORALL(a, -3, 3, FORALL(x, 0, 7, func(x, a) >= a)));
    assert(EXISTS(a, -3, 3, FORALL(x, 0, 7, func(x, a) >= 2)));
  }
  return 0;
}

