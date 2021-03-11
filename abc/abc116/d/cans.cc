#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

typedef pair<int, int> Pair;

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, K; cin >> N >> K;
  vector<Pair> dt;
  for (int i = 0; i < N; i++) {
    int tt, dd; cin >> tt >> dd; tt--;
    dt.emplace_back(dd, tt);
  }
  sort(dt.begin(), dt.end(), greater<Pair>());
       //       [](const Pair& u, const Pair& v) { return u.second > v.second; });
  vector<bool> seen(N);
  vector<int> tops, rests;
  for (int i = 0; i < N; i++) {
    int dd = dt.at(i).first;
    int tt = dt.at(i).second;
    if (seen.at(tt)) {
      rests.push_back(dd);
    }else {
      tops.push_back(dd);
      seen.at(tt) = true;
    }
  }
  ll sd = 0;
  int m = min(K, (int)tops.size());
  ll st = m;
  for (int i = 0; i < m; i++) sd += tops.at(i);
  int j = 0;
  for ( ; j < K - (int)tops.size(); j++) sd += rests.at(j);
  ll ans = sd + st * st;
  int i = m - 1;
  for ( ; i >= 0 && j < (int)rests.size(); i--, j++) {
    sd += rests.at(j) - tops.at(i);
    st--;
    ans = max(ans, sd + st * st);
  }

  cout << ans << endl;

  return 0;
}

