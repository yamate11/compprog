#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  string S, T; cin >> S >> T;
  for (int i = 0; i < N; i++) {
    cout << S.at(i) << T.at(i);
  }
  cout << endl;

  return 0;
}

