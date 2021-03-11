#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <boost/optional.hpp>

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

typedef pair<ll, vector<ll>> myElem;

vector<ll> sz(3);
vector<vector<ll>> vec(3);
ll K;

myElem elem(vector<ll> v) {
  ll sum = 0;
  for (ll p = 0; p < 3; p++) { sum += vec.at(p).at(v.at(p)); }
  return make_pair(sum, v);
}

myElem elem(ll i, ll j, ll k) {
  vector<ll> v = {i, j, k};
  return elem(v);
}

ll diff_at(ll p, vector<ll> v) {
  return vec.at(p).at(v.at(p)-1) - vec.at(p).at(v.at(p));
}

boost::optional<myElem> nextElem(myElem e, ll p) {
  ll idx = e.second.at(p);
  if (idx == sz.at(p) - 1)  return boost::optional<myElem>();
  vector<ll> v = e.second;
  v.at(p)++;
  for (ll q = 0; q < 3; q++) {
    if (q == p)  continue;
    if (v.at(q) == 0)  continue;
    ll diff = diff_at(p, v) - diff_at(q, v);
    if (diff < 0 || (diff == 0 && p > q))  return boost::optional<myElem>();
  }
  return elem(v);
}

int main() {
  cin >> sz.at(0) >> sz.at(1) >> sz.at(2) >> K;
  for (ll p = 0; p < 3; p++) {
    vec.at(p).resize(sz.at(p));
    for (ll i = 0; i < sz.at(p); i++)  cin >> vec.at(p).at(i);
    sort(vec.at(p).begin(), vec.at(p).end(), greater<ll>());
  }
  priority_queue<myElem> pque;
  myElem init = elem(0, 0, 0);
  pque.push(init);
  for (int i = 0; i < K; i++) {
    myElem e = pque.top();
    pque.pop();
    cout << e.first << endl;
    for (ll p = 0; p < 3; p++) {
      boost::optional<myElem> eN = nextElem(e, p);
      if (!eN)  continue;
      pque.push(*eN);
    }
  }
  return 0;
}

