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
  string s; cin >> s;
  vector<ll> op(128, -1), cl(128, -1);
  for (ll i = 0; i < n; i++) {
    char c = s[i];
    if (op[c] < 0) op[c] = i;
    cl[c] = i + 1;
  }
  using ev_t = pair<ll, ll>;
  const ll OP = 1;
  const ll CL = 0;
  vector<ev_t> ev;
  for (ll c = 'A'; c <= 'Z'; c++) {
    if (op[c] < 0) continue;
    ev.emplace_back(op[c], OP);
    ev.emplace_back(cl[c], CL);
  }
  sort(ev.begin(), ev.end());
  ll cmax = 0;
  ll cur = 0;
  for (auto [t, tp] : ev) {
    if (tp == OP) cur++;
    else cur--;
    cmax = max(cmax, cur);
  }
  if (cmax <= k) cout << "NO\n";
  else cout << "YES\n";

  return 0;
}

