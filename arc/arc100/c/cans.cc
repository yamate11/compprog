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

ll N;
vector<ll> A;
vector<ll> ord;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif


  cin >> N;
  A.resize(N);
  for (ll i = 0; i < N; i++) {
    ll x;
    cin >> x;
    A.at(i) = x - i;
  }
  ord.resize(N);
  for (ll i = 0; i < N; i++)  ord.at(i) = i;
  sort(ord.begin(), ord.end(), [](ll x,ll y){ return A.at(x) < A.at(y); });
  ll b = A.at(ord.at(N / 2));
  ll sad = 0;
  for (ll i = 0; i < N; i++)  sad += abs(A.at(i) - b);
  cout << sad << endl;
  return 0;
}

