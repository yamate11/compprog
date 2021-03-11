#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, X; cin >> N >> X;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  vector<bool> sol(X+1);

  auto fill = [&]() {
    int b = 1;
    for (int i = 0; i < N; i++) {
      b *= A.at(i) + 1;
      if (b - 1 > X) return;
    }
    b--;
    sol.at(b) = true;
    for (int i = 0; i < N; i++) {
      for (int j = 0; b + j * A.at(i) <= X; j++) {
	sol.at(b + j * A.at(i)) = true;
      }
    }
  };
  fill();

  for (int i = 1; i <= X; i++) cout << (sol.at(i) ? "1" : "0");
  cout << endl;
  return 0;
}

