#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

bool solve() {
  string s; cin >> s;
  if (s.at(0) == s.at(s.size() - 1)) {
    return s.size() % 2 == 0;
  }else {
    return s.size() % 2 != 0;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << (solve() ? "First" : "Second") << endl;

  return 0;
}

