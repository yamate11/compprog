#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<int> L(2*N);
  for (int i = 0; i < 2*N; i++) cin >> L.at(i);
  sort(L.begin(), L.end());
  int s = 0;
  for (int i = 0; i < N; i++) {
    int j = 2 * i;
    s += L.at(j);
  }
  cout << s << endl;

  return 0;
}

