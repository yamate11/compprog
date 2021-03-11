#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, A, B; cin >> N >> A >> B;
  ll diff = B - A;
  if (diff % 2 == 0) {
    cout << diff / 2 << endl;
    return 0;
  }
  ll prep = min(A - 1, N - B);
  cout << (prep + 1) + ((diff - 1) / 2) << endl;

  return 0;
}

