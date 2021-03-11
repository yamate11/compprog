#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string S; cin >> S;

  ll cnt = 0;
  for (int i = 0; i < N; i++) {
    if (S.substr(i, 3) == string("ABC")) cnt++;
  }
  cout << cnt << endl;


  return 0;
}

