#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  for (int i = 0; i < 3; i++)  {
    if ('0' <= S.at(i) && S.at(i) <= '9') {
    }else {
      cout << "error\n";
      return 0;
    }
  }
  cout << stoi(S) * 2 << endl;

  return 0;
}

