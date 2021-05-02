#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B; cin >> A >> B;
  vector<ll> ans;
  for (ll i = 1; i <= A - 1; i++) ans.push_back(i);
  for (ll i = 1; i <= B - 1; i++) ans.push_back(-i);
  ll sumA = A * (A + 1) / 2;
  ll sumB = B * (B + 1) / 2;
  if (A == B) {
    ans.push_back(A);
    ans.push_back(-B);
  }else if (A < B) {
    ans.push_back(-B);
    ans.push_back(A + sumB - sumA);
  }else {
    ans.push_back(A);
    ans.push_back(-(B + sumA - sumB));
  }
  for (ll a : ans) cout << a << " ";
  cout << endl;

  return 0;
}

