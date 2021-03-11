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

  double s = 0;

  for (int i = 0; i < N; i++) {
    double x;
    string u;
    cin >> x >> u;
    if (u == "JPY") {
      s += x;
    }else {
      s += x * 380000;
    }
  }
  cout << s << endl;
  
  

  return 0;
}

