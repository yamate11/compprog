#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  vector<string> v;
  for (int i = 0; i < (int)S.size(); ) {
    assert(isupper(S.at(i)));
    int j = i + 1;
    for ( ; j < (int)S.size(); j++) {
      if (isupper(S.at(j))) break;
    }
    string t = S.substr(i, j - i + 1);
    t.at(0) = tolower(t.at(0));
    t.at(j-i) = tolower(t.at(j-i));
    v.push_back(t);
    i = j + 1;
  }
  sort(v.begin(), v.end());
  string ans;
  for (string t : v) {
    t.at(0) = toupper(t.at(0));
    int k = t.size() - 1;
    t.at(k) = toupper(t.at(k));
    ans += t;
  }
  cout << ans << endl;

  return 0;
}

