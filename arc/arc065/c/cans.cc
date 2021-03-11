#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<string> kws({"dream", "dreamer", "erase", "eraser"});

  string S; cin >> S;
  while (S.size() > 0) {
    bool progress = false;
    for (string kw: kws) {
      if (S.size() < kw.size()) continue;
      if (S.substr(S.size() - kw.size(), kw.size()) == kw) {
	progress = true;
	S.resize(S.size() - kw.size());
	break;
      }
    }
    if (!progress) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}

