#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll lim = 1e5;

  ll n; cin >> n;
  vector<ll> num(lim + 1);
  using StA = pair<ll, ll>;
  set<StA, greater<StA>> sset;
  for (ll i = 0; i < n; i++) {
    ll x; cin >> x;
    num[x]++;
  }
  for (ll i = 1; i <= lim; i++) {
    sset.emplace(num[i], i);
  }
  ll q; cin >> q;
  for (ll q_ = 0; q_ < q; q_++) {
    char c; cin >> c;
    ll x; cin >> x;
    {
      auto it = sset.find(StA(num[x], x));
      assert(it != sset.end());
      sset.erase(it);
      if (c == '+') num[x]++;
      else          num[x]--;
      sset.emplace(num[x], x);
    }

    auto it = sset.begin();
    ll m = it->first;
    if (m >= 8) {
      cout << "YES\n";
    }else if (m < 4) {
      cout << "NO\n";
    }else {
      it++;
      if (it == sset.end()) {
	cout << "NO\n";
      }else {
	ll k = it->first;
	if ((m >= 6 && k >= 2) || k >= 4) {
	  cout << "YES\n";
	}else if (k <= 1) {
	  cout << "NO\n";
	}else {
	  it++;
	  if (it == sset.end() || it->first <= 1) {
	    cout << "NO\n";
	  }else {
	    cout << "YES\n";
	  }
	}
      }
    }

  }


  return 0;
}

