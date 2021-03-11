#include <bits/stdc++.h>

using namespace std;

int V[55];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> V[i];
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; i + j <= min(k, n); j++) {
      vector<int> v;
      for (int x = 1; x <= i; x++) v.push_back(V[x]);
      for (int x = 0; x < j; x++) v.push_back(V[n - x]);
      sort(v.rbegin(), v.rend());
      int k2 = k - i - j;
      while (k2 > 0 && !v.empty() && v.back() < 0) {
	v.pop_back();
	k2--;
      }
      int sum = 0;
      for (int x : v) sum += x;
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
}
