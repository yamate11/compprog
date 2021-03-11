#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(int argc, char** argv) {
  stringstream ss(argv[1]);
  ll N; ss >> N;
  ll lim = 1LL << N;
  vector<pair<ll, ll>> v;
  for (ll x = 0; x < lim; x++) v.emplace_back(__builtin_popcountll(x), x);
  sort(v.begin(), v.end());
  cout << v.at(lim-1).second << endl;
}
