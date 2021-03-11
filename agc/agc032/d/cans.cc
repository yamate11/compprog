#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DLOG(...)
#endif

void debug(auto f) {
#if DEBUG
  f();
#endif
}

ll N, A, B;
vector<ll> p;
vector<ll> pos;
vector<ll> tbl;

void showtbl() {
  debug([]() {
      for (ll i = 0; i < 2*N+1; i++)  cerr << tbl.at(i) << ", ";
      cerr << endl;
    });
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> A >> B;
  p.resize(N);
  pos.resize(N);
  for (ll i = 0; i < N; i++)  {
    ll x;
    cin >> x;
    p.at(i) = x - 1;
  }
  for (ll i = 0; i < N; i++)  pos[p.at(i)] = i;
  tbl.resize(2*N+1);
  /*
    2*i+1 ... just i
    2*i+2 ... (i, i+1)
   */

  for (ll k = 0; k < N; k++) {
    ll i0 = pos.at(k);
    for (ll i = 0; i <= 2*i0; i++)  tbl.at(i) += B;
    for (ll i = 2*i0 + 2; i < 2*N + 1; i++)  tbl.at(i) += A;
    showtbl();
    for (ll i = 1; i < 2*N+1; i++) {
      tbl.at(i) = min(tbl.at(i-1), tbl.at(i));
    }
    showtbl();
  }
  cout << tbl.at(2*N) << endl;

  return 0;
}

