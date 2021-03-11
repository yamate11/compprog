#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    ll r, g, b; cin >> r >> g >> b;
    if (r < g) swap(r, g);
    if (g < b) swap(g, b);
    if (r < g) swap(r, g);
    if (r > g + b + 1) cout << "No\n";
    else cout << "Yes\n";
  }

  return 0;
}

