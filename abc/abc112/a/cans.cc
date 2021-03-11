#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  if (N == 1) {
    cout << "Hello World\n";
    return 0;
  }
  int A, B; cin >> A >> B;
  cout << A+B << endl;

  return 0;
}

