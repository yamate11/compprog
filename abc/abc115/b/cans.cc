#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  int vmax = 0;
  int sum = 0;
  vector<int> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p.at(i);
    vmax = max(vmax, p.at(i));
    sum += p.at(i);
  }
  sum -= vmax / 2;
  cout << sum << endl;

  return 0;
}

