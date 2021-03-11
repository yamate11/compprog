#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++) cin >> v.at(i);
  return cin;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> a(N); cin >> a;
  cout << accumulate<vector<ll>::iterator, ll>(a.begin(), a.end(), 0LL) - N << endl;

  return 0;
}

