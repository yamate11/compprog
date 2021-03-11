#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end(), greater<ll>());
  ll sum = 0;
  for (ll i = 0; i < N; i+= 2) sum += A.at(i);
  cout << sum << endl;

  return 0;
}

