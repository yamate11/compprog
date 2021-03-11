#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K; K--;
  map<string, ll> mp;
  for (ll i = 0; i < N; i++) {
    string s; cin >> s;
    mp[s]++;
  }
  using sta = pair<ll, string>;
  vector<sta> rec;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    rec.emplace_back(it->second, it->first);
  }
  sort(rec.begin(), rec.end(), greater<sta>());
  if ((K >= 1 && rec[K-1].first == rec[K].first) ||
      (K + 1 < (ll)rec.size() && rec[K].first == rec[K+1].first)) {
    cout << "AMBIGUOUS\n";
    return 0;
  }else {
    cout << rec[K].second << endl;
  }


  return 0;
}

