#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  int lim = 1e5;
  vector<int> vec(lim);
  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    vec.at(a)++;
  }
  int vmax = 0;
  for (int i = 0; i < lim; i++) {
    int s = vec.at(i);
    if (i-1 >= 0)  s += vec.at(i-1);
    if (i+1 < lim) s += vec.at(i+1);
    vmax = max(vmax, s);
  }
  cout << vmax << endl;

  return 0;
}

