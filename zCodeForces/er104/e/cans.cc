#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> N(4);
  REP(i, 4) cin >> N[i];
  vector<vector<ll>> A(4, vector<ll>());
  REP(i, 4) REP(j, N[i]) {
    ll a; cin >> a;
    A[i].push_back(a);
  }
  vector<ll> M(3);
  vector<vector<ll>> X(3, vector<ll>()), Y(3, vector<ll>());
  REP(i, 3) {
    cin >> M[i];
    REP(j, M[i]) {
      ll x, y; cin >> x >> y; x--; y--;
      X[i].push_back(x);
      Y[i].push_back(y);
    }
  }
  
  ll big = 1e18;
  auto func = [&](auto& vecA, auto& vecB, auto& vecX, auto& vecY) -> void {
    vector<vector<ll>> bad(SIZE(vecB));
    REP(i, SIZE(vecY)) bad[vecY[i]].push_back(vecX[i]);
    multiset<ll> rec;
    REP(i, SIZE(vecA)) rec.insert(vecA[i]);
    REP(i, SIZE(vecB)) {
      for (ll j : bad[i]) rec.erase(rec.find(vecA[j]));
      if (rec.empty()) vecB[i] = big;
      else vecB[i] += *rec.begin();
      for (ll j : bad[i]) rec.insert(vecA[j]);
    }
  };
  func(A[0], A[1], X[0], Y[0]);
  func(A[1], A[2], X[1], Y[1]);
  func(A[2], A[3], X[2], Y[2]);
  auto it = min_element(ALL(A[3]));
  cout << (*it >= big ? -1 : *it) << endl;

  return 0;
}

