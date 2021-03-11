#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, T; cin >> N >> T;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  B.at(N-1) = A.at(N-1);
  for (int i = N-2; i >= 0; i--) B.at(i) = max(A.at(i), B.at(i+1));
  int vmax = 0;
  int vcnt = 0;
  for (int i = 0; i < N; i++) {
    int v = B.at(i) - A.at(i);
    if (v > vmax) {
      vmax = v;
      vcnt = 1;
    }else if (v == vmax) {
      vcnt++;
    }
  }
  cout << vcnt << endl;

  return 0;
}

