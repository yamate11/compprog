#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string tt = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int N;
  string S;
  cin >> N >> S;
  char buf[S.size() + 10];
  for (int i = 0; i < (int)S.size(); i++) {
    buf[i] = (S.at(i) - 'A' + N) % 26 + 'A';
  }
  buf[S.size()] = 0;
  string ans(buf);
  cout << ans << endl;

  return 0;
}

