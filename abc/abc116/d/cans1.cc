#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, K; cin >> N >> K;
  vector<int> t(N), d(N), ord(N);
  for (int i = 0; i < N; i++) {
    cin >> t.at(i) >> d.at(i);
    t.at(i)--;
  }
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(),
       [&](int u, int v) { return d.at(u) > d.at(v); });
  vector<bool> top(N);
  vector<bool> seen(N);
  for (int i = 0; i < N; i++) {
    int j = ord.at(i);
    int tt = t.at(j);
    if (!seen.at(tt)) {
      seen.at(tt) = true;
      top.at(i) = true;
    }
  }
  ll sd = 0;
  ll st = 0;
  for (int i = 0; i < K; i++) {
    int j = ord.at(i);
    sd += d.at(j);
    if (top.at(i)) st++;
  }
  int k = K - 1;
  ll ans = sd + st * st;
  for (int i = K-1; i >= 0; i--) {
    if (top.at(i)) continue;
    k++;
    while (k < N && !top.at(k)) k++;
    if (k == N) break;
    sd += d.at(ord.at(k)) - d.at(ord.at(i));
    st++;
    ans = max(ans, sd + st * st);
  }
  cout << ans << endl;

  return 0;
}

