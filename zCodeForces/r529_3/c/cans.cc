#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  if (k > n) {
    cout << "NO\n";
    return 0;
  }
  ll lim = 3e5;
  vector<ll> rec;
  ll p = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      rec.push_back(p);
    }
    n /= 2;
    p *= 2;
  }
  ll m = rec.size();
  if (k < m) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  ll r = k - m;
  ll idx = m - 1;
  rec.resize(lim);
  bool first = true;
  auto pout = [&](ll xx) -> void {
    if (first) first = false;
    else cout << " ";
    cout << xx;
  };
  while (true) {
    if (r == 0) {
      if (idx < 0) break;
      pout(rec[idx--]);
    }else {
      if (rec[idx] == 1) {
	pout(1);
	idx--;
      }else {
	rec[idx] /= 2;
	idx++;
	rec[idx] = rec[idx - 1];
	r--;
      }
    }
  }
  cout << endl;


  return 0;
}

