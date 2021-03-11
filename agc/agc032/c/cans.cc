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


ll follow(auto& nbr, ll x1, ll x2, ll gA, ll gB) {
  while (1) {
    DLOG("(%lld, %lld)\n", x1, x2);
    if (x2 == gA)  return 0;
    if (x2 == gB)  return 1;
    auto lst = nbr.at(x2);
    assert(lst.size() == 2);
    if (lst.at(0) == x1) {
      x1 = x2;
      x2 = lst.at(1);
    }else {
      assert(lst.at(1) == x1);
      x1 = x2;
      x2 = lst.at(0);
    }
  }
}

string chk(ll n, auto& nbr) {
  ll six = 0;
  ll four = 0;
  ll fourA = 0;
  ll fourB = 0;
  for (ll i = 1; i <= n; i++) {
    ll k = nbr.at(i).size();
    if (k % 2 == 1)  return "No";
    if (k >= 6)  six++;
    if (k == 4)  {
      four++;
      if (four == 1)       fourA = i;
      else if (four == 2)  fourB = i;
    }
  }
  if (six >= 1)   return "Yes";
  if (four >= 3)  return "Yes";
  if (four <= 1)  return "No";
  ll count = 0;
  for (auto x : nbr.at(fourA)) {
    count += follow(nbr, fourA, x, fourA, fourB);
  }
  return count == 2 ? "Yes" : "No";
}

int main() {
  ll n, m;
  cin >> n >> m;
  vector< vector<ll> > nbr(n+1);
  for (ll i = 0; i < m; i++)  {
    ll a, b;
    cin >> a >> b;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
  }

  debug([&](){
    for (ll i = 1; i <= n; i++) {
      fprintf(stderr, "%lld : ", i);
      for (ll j = 0; j < (ll) nbr.at(i).size(); j++) {
	fprintf(stderr, "%lld ", nbr.at(i).at(j));
      }
      fprintf(stderr, "\n");
    }});

  cout << chk(n, nbr) << endl;
  return 0;
}
