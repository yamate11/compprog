#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B, K; cin >> A >> B >> K;
  if (K <= A) {
    cout << A - K << " " << B << endl;
    return 0;
  }else if (K <= A + B) {
    cout << "0 " << (A + B) - K << endl;
  }else {
    cout << "0 0" << endl;
  }

  return 0;
}

