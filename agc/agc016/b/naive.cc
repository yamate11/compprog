#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int mn = a[0], mx = a[0];
  for (int i = 1; i < n; i++) {
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
  if (mx - mn > 1)
    return cout << "No\n", 0;
  else if (mx - mn == 1) {
    int x = 0;
    for (int i = 0; i < n; i++)
      if (a[i] == mn)
	x++;
    return cout << (mx * 2 - x <= n && x <= mn? "Yes\n": "No\n"), 0;
  }
  else
    return cout << (mn * 2 <= n || mn == n - 1? "Yes\n": "No\n"), 0;
}
