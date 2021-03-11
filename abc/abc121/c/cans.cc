#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<long long,long long>> vec;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vec.emplace_back(a, b);
  }
  sort(vec.begin(), vec.end());
  long long sum = 0;
  int remain = m;
  for (int i = 0; i < n; i++) {
    auto p = vec.at(i);
    if (p.second >= remain) {
      sum += remain * p.first;
      cout << sum << endl;
      return 0;
    }
    remain -= p.second;
    sum += p.second * p.first;
  }
}
