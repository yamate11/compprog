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

ll N, K;
vector<ll> p, q;
vector<vector<ll>> init(7);

vector<ll> comp(vector<ll> s, vector<ll> t) {
  vector<ll> result(N+1);
  for (ll i = 1; i <= N; i++)  result.at(i) = s.at(t.at(i));
  return result;
}

vector<ll> inv(vector<ll> s) {
  vector<ll> result(N+1);
  for (ll i = 1; i <= N; i++)  result.at(s.at(i)) = i;
  return result;
}

vector<ll> unit() {
  vector<ll> result(N+1);
  for (ll i = 1; i <= N; i++)  result.at(i) = i;
  return result;
}

vector<ll> funcf(vector<ll> s, vector<ll> t) {
  return comp(t, inv(s));
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> K;
  p.resize(N+1);
  q.resize(N+1);
  for (ll i = 1; i <= N; i++)  cin >> p.at(i);
  for (ll i = 1; i <= N; i++)  cin >> q.at(i);
  init.at(1) = vector<ll>(p);
  init.at(2) = vector<ll>(q);
  for (ll i = 3; i <= 6; i++)  init.at(i) = funcf(init.at(i-2), init.at(i-1));
  ll n = (K-1) / 6;
  ll k = (K-1) % 6;
  vector<ll> alpha = comp(q, comp(inv(p), comp(inv(q), p)));
  ll pwlen = 32;
  vector<vector<ll>> powA(pwlen);
  powA.at(0) = unit();
  powA.at(1) = vector<ll>(alpha);
  for (ll j = 1; j < pwlen - 1; j++)  {
    powA.at(j+1) = comp(powA.at(j), powA.at(j));
  }
  vector<ll> beta = unit();
  for (ll j = 1, x = n; x > 0; j++, x /= 2) {
    if (x % 2 == 1)  beta = comp(beta, powA.at(j));
  }
  vector<ll> answer = comp(beta, comp(init.at(k+1), inv(beta)));
  for (ll i = 1; i <= N - 1; i++)  cout << answer.at(i) << " ";
  cout << answer.at(N) << endl;

  return 0;
}

