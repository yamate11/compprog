#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()


string func(ll x) {
  if (x == 0) return "";
  if (x % 2 == 0) {
    return func(- x / 2) + "0";
  }else {
    return func(- (x - 1) / 2) + "1";
  }
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  ll N; cin >> N;
  string ans = func(N);
  cout << (ans == "" ? "0" : ans) << endl;
  

  return 0;
}

