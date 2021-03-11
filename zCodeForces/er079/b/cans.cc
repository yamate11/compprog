#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int solve() {
  int n, s; cin >> n >> s;
  ll sum = 0;
  ll argmax = -1;
  ll vmax = -1;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  for (int i = 0; i < n; i++) {
    ll p = a.at(i);
    if (sum + vmax <= s) {
      if (vmax < p) {
	argmax = i;
	vmax = p;
      }
      sum += p;
    }else {
      if (vmax > p) return argmax;
      else return i;
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int t; cin >> t;
  for (int z = 0; z < t; z++) cout << solve() + 1 << endl;

  return 0;
}

