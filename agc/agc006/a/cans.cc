#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;



int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  string s, t; cin >> s >> t;
  for (int i = 0; i < N; i++) {
    bool found = true;
    for (int j = i; j < N; j++) {
      if (s.at(j) != t.at(j - i)) {
	found = false;
	break;
      }
    }
    if (found) {
      cout << N+i << endl;
      return 0;
    }
  }
  cout << 2*N << endl;

  return 0;
}

