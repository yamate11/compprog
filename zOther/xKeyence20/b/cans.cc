#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<pair<ll,ll>> range(N);
  for (ll i = 0; i < N; i++) {
    ll x, l; cin >> x >> l;
    range.at(i) = make_pair(x - l, x + l);
  }
  sort(range.begin(), range.end(),
       [&](auto p, auto q) -> bool { return p.second < q.second; });
  ll cur = LLONG_MIN;
  ll count = 0;
  for (ll i = 0; i < N; i++) {
    if (cur <= range.at(i).first) {
      count++;
      cur = range.at(i).second;
    }
  }
  cout << count << endl;

  return 0;
}

