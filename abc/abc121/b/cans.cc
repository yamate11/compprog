#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  for (int i = 0; i < m; i++)  cin >> b.at(i);
  int count = 0;
  for (int j = 0; j < n; j++) {
    int val = 0;
    for (int i = 0; i < m; i++)  {
      int a;
      cin >> a;
      val += b.at(i) * a;
    }
    val += c;
    if (val > 0)  count++;
  }
  cout << count << endl;
  return 0;
}
