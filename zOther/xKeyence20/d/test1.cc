#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(int argc, char** argv) {
  stringstream ss(argv[1]);
  ll N; ss >> N;
  ll lim = 1LL << N;
  vector<ll> v(lim);
  iota(v.begin(), v.end(), 0);
  sort(v.begin(), v.end(),
       [](ll a, ll b) -> bool {
	 return __builtin_popcountll(a) < __builtin_popcountll(b);
       });
  cout << v.at(lim-1) << endl;
}
