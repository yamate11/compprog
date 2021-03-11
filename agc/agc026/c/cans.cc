#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  string S; cin >> S;
	      
  string s1 = S.substr(0, N);
  string s2 = S.substr(N, N);
  reverse(s2.begin(), s2.end());
  map<pair<string, string>, ll> mp1, mp2;

  auto divide = [&](const string& s, int i, string& tA, string& tB) -> void {
    tA = tB = "";
    for (int j = 0; j < N; j++) {
      if ((i >> (N-1 - j)) & 1) tA += s.at(j);
      else                      tB += s.at(j);
    }
  };

  for (int i = 0; i < (1 << N); i++) {
    string tA, tB; divide(s1, i, tA, tB);
    mp1[make_pair(tA, tB)] ++;
  }
  for (int i = 0; i < (1 << N); i++) {
    string tA, tB; divide(s2, i, tA, tB);
    mp2[make_pair(tA, tB)] ++;
  }
  ll cnt = 0;
  for (auto const& x : mp1) {
    cnt += x.second * mp2[x.first];
  }
  cout << cnt << endl;

  return 0;
}

