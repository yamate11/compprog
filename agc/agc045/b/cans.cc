#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(binsearch)
// --> binsearch
// ---- inserted library file binsearch.cc

template<typename T>
T binsearch(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / (T)2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll n = S.size();
  
  auto check = [&](ll k) -> bool {
    assert(k >= 1);
    ll rmax = k;
    ll rmin = 0;
    ll eo = 0;
    /*
    auto incmax = [&]() -> void { if (++rmax > k) rmax -= 2; };
    auto decmin = [&]() -> void { if (--rmin < 0) rmin += 2; };
    */
    for (ll i = 0; i < n; i++) {
      if (S[i] == '1') {
	if (rmin == k) return false;
	else if (rmin == k - 1) {
	  rmax = rmin = k;
	  eo = 1;
	}else {
	  if (rmax < k) rmax++;
	  else if (eo) rmax--;
	  rmin++;
	}
      }else if (S[i] == '0') {
	if (rmax == 0) return false;
	else if (rmax == 1) {
	  rmax = rmin = 0;
	  eo = 1;
	}else {
	  if (rmin > 0) rmin--;
	  else if (eo) rmin++;
	  rmax--;
	}
      }else {
	if (eo) {
	  if (rmax == k) rmax = k - 1;
	  else rmax++;
	  if (rmin == 0) rmin = 1;
	  else rmin--;
	}else {
	  if (rmax < k) rmax++;
	  if (rmin > 0) rmin--;
	}
      }
      // DLOG("i=", i, "rmax=", rmax, "rmin=", rmin);
    }
    return true;
  };

  ll x = binsearch<ll>(check, n, 0);
  cout << x << endl;

  return 0;
}

