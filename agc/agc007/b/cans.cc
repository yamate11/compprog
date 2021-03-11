#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<int> a(N), b(N), rev(N);
  for (int i = 0; i < N; i++) {
    int p; cin >> p; p--;
    rev.at(p) = i;
  }
  a.at(0) = 1;
  b.at(0) = rev.at(0) - a.at(0);
  for (int i = 1; i < N; i++) {
    int diff = rev.at(i) - rev.at(i-1);
    if (diff > 0) {
      a.at(i) = a.at(i-1) + diff + 1;
      b.at(i) = b.at(i-1) - 1;
    }else {
      a.at(i) = a.at(i-1) + 1;
      b.at(i) = b.at(i-1) + diff - 1;
    }
  }
  int shift = 1 - b.at(N-1);
  for (int i = 0; i < N; i++) b.at(i) += shift;
  
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << a.at(i);
  }
  cout << endl;
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << b.at(i);
  }
  cout << endl;

  return 0;
}

