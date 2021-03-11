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
  vector<int> h(N);
  int vmax = 0;
  for (int i = 0; i < N; i++) {
    cin >> h.at(i);
    vmax = max(vmax, h.at(i));
  }
  int cnt = 0;
  while (vmax > 0) {
    bool on = false;
    for (int i = 0; i < N; i++) {
      if (h.at(i) == vmax) {
	if (!on) cnt++;
	h.at(i)--;
	on = true;
      }else {
	on = false;
      }
    }
    vmax--;
  }
  cout << cnt << endl;

  return 0;
}

