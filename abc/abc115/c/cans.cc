#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, K; cin >> N >> K;
  vector<int> h(N);
  for (int i = 0; i < N; i++) cin >> h.at(i);
  sort(h.begin(), h.end());
  int v = INT_MAX;
  for (int i = 0; i+K-1 < N; i++) {
    v = min(v, h.at(i+K-1) - h.at(i));
  }
  cout << v << endl;

  return 0;
}

