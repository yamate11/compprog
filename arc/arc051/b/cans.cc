#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int lim = 50;
  vector<int> f(lim);
  f.at(0) = 1;
  f.at(1) = 1;
  for (int i = 2; i < lim; i++) f.at(i) = f.at(i-2) + f.at(i-1);
  int K; cin >> K;
  cout << f.at(K+1) << " " << f.at(K) << endl;

  return 0;
}

