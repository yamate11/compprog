#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<bool> done(N);
  vector<int> wa(N);
  ll ac = 0;
  for (int i = 0; i < M; i++) {
    int p; cin >> p; p--;
    string s; cin >> s;
    if (done.at(p)) continue;
    if (s == "WA") {
      wa.at(p)++;
    }else if (s == "AC") {
      ac++;
      done.at(p) = true;
    }else {
      assert(false);
    }
  }
  ll nwa = 0;
  for (ll i = 0; i < N; i++) {
    if (done.at(i)) nwa += wa.at(i);
  }
  cout << ac << " " << nwa << endl;

  return 0;
}

