#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 1

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
string cs;
vector<set <ll>> children;
vector<ll> parent;
vector<ll> round;
vector<ll> diff1;
vector<ll> diffarg1;
vector<ll> diff2;
vector<ll> diffarg2;
vector<ll> cost;

ll color(node i) {
  return cs.at[i-1] == 'B' ? 1 : 0;
}

ll parity(node i) {
  return (color(i) + children.at(i)) % 2;
}

void mkParent(ll p, ll c) {
  auto lst = children.at(c);
  if (p >= 1)  lst.erase(p);
  parent.at(c) = p;
  for (ll cc : lst)  mkParent(c, cc);
}

ll prune() {
  ll root;
  stack<ll> yet;
  for (ll i = 1; i <= N; i++)  yet.push(i); 
  while(!yet.empty()) {
    ll i = yet.top();
    yet.pop();
    if (color(i) == 0)  {
      root = i;
      continue;
    }
    if (children.at(i).size() >= 2)  continue;
    ll j = *(children.at(i).begin());
    children.at(j).erase(i);
    yet.push(j);
  }
  return root;
}

void round(ll i) {
  return csum.at(i) + 2 + (1 - parity(i));
}

void oneway(ll i) {
  return csum.at(i) + diff1.at(i) + 1 + parity(i);
}

void phase1(ll i0) {
  ll imax, imaxarg;
  if (children.at(i0).empty()) {
    round.at(i0) = 2;
    diffarg1.at(i0) = -1;
    diffarg2.at(i0) = -1;
    return;
  }
  ll imin;
  ll iminarg = -1;
  ll imin2;
  ll iminarg2 = -1;
  ll sum = 0;
  for (ll i : children.at(i0)) {
    phase1(i);
    sum += round.at(i);
    diff = oneway(i0) - round.at(i0);
    if (iminarg < 0 || diff < imin) {
      imin2 = imin;
      iminarg2 = iminarg;
      imin = diff;
      iminarg = i;
    }else if (imin2 < 0 || diff < imin2) {
      imin2 = diff;
      iminarg2 = i;
    }
  }
  round.at(i0) = sum + (1 - parity(i0));
  diff1.at(i0) = imin;
  diffarg1.at(i0) = iminarg;
  diff2.at(i0) = imin2;
  diffarg2.at(i0) = iminarg2;
}

void phase2sub(ll i0, ll rRound, ll rOneway) {
  ll par = parent.at(i0);
  ll sum = 0;
  for (i 
  ll sum = round.at(i0) + rRound;
  ll diff = rOneway - rRound;
  ll diff1 = diff1.at(i0);
  ll diffarg1 = diffarg1.at(i0);
  ll diff2 = diff2.at(i0);
  ll diffarg2 = diffarg2.at(i0);
  if (diffarg1 < 0 || diff < diff1) {
    diff2 = diff1;
    diffarg2 = diffarg1;
    diff1 = diff;
    diffarg1 = par;
  }else if (diffarg2 < 0 || diff < diff2) {
    diff2 = diff;
    diffarg2 = par;
  }
  cost.at(i0) = 
}

void phase2(ll root) {
  
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N;
  children.resize(N+1);
  parent.resize(N+1);
  round.resize(N+1);
  diff1.resize(N+1);
  diffarg1.resize(N+1);
  diff2.resize(N+1);
  diffarg2.resize(N+1);
  cost.resize(N+1);
  for (ll i = 1; i <= N; i++)  {
    ll x, y;
    cin >> x >> y;
    children.at(x).insert(y);
    children.at(y).insert(x);
  }
  cin >> cs;
  ll root = prune();
  mkParent(-1, root);
  phase1(root);
  phase2(root);

  return 0;
}


/*

 x --> y

 */
