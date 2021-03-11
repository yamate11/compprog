#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  int vmax = 0;
  int vsum = 0;
  for (int i = 0; i < N; i++) {
    int l; cin >> l;
    vmax = max(vmax, l);
    vsum += l;
  }
  vsum -= vmax;
  cout << (vsum > vmax ? "Yes" : "No") << endl;

  return 0;
}

