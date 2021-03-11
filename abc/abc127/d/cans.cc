#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
  #define DFUNC(fname, ...) fname(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFUNC(fname, ...)
#endif

ll N, M;
vector<ll> A;

typedef pair<ll,ll> myPair;
priority_queue<myPair, vector<myPair>, greater<myPair>> pque;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> M;
  ll sum = 0;
  for (ll i = 0; i < N; i++)  {
    ll a;
    cin >> a;
    sum += a;
    pque.push(make_pair(a,1));
  }
  for (ll i = 0; i < M; i++) {
    ll b, c;
    cin >> b >> c;
    ll x = 0;
    while (x < b) {
      myPair p = pque.top();
      if (c <= p.first)  break;
      pque.pop();
      if (x + p.second <= b) {
	sum += (c - p.first) * p.second;
	x += p.second;
      }else {
	sum += (c - p.first) * (b - x);
	pque.push(make_pair(p.first, p.second - (b-x)));
	x = b;
      }
    }
    pque.push(make_pair(c, x));
  }
  cout << sum << endl;

  return 0;
}

