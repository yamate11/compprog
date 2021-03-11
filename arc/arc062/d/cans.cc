#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;



int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;
  int np = 0;
  for (int i = 0; i < (int)s.size(); i++) if (s.at(i) == 'p') np++;
  int myNp = s.size() / 2;
  cout << myNp - np << endl;

  return 0;
}

