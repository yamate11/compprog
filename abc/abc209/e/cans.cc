#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto cenc = [&](char c) -> ll {
    if ('A' <= c && c <= 'Z') return c - 'A';
    else return 26 + c - 'a';
  };
  auto enc = [&](string s) -> ll {
    return ((cenc(s[0]) * 52) + cenc(s[1])) * 52 + cenc(s[2]);
  };

  ll sz = 52 * 52 * 52;  // 140608
  ll N; cin >> N;
  vector<vector<ll>> fwd(sz), bwd(sz);
  vector<string> S(N);
  for (ll i = 0; i < N; i++) {
    string s; cin >> s;
    S[i] = s;
    ll a = enc(s.substr(0, 3));
    ll b = enc(s.substr(s.size() - 3, 3));
    fwd[a].push_back(b);
    bwd[b].push_back(a);
  }
  ll OPP = 1;
  ll PLA = 2;
  // ll DRA = 3;
  vector<ll> judge(sz); 
  vector<ll> copp;
  vector<ll> cpla;
  for (ll i = 0; i < sz; i++) {
    if (fwd[i].empty()) {
      copp.push_back(i);
      judge[i] = OPP;
    }
  }
  while (true) {
    cpla = vector<ll>();
    for (ll i : copp) {
      for (ll j: bwd[i]) {
        if (judge[j] != 0) continue;
        cpla.push_back(j);
        judge[j] = PLA;
      }
    }
    if (cpla.empty()) break;
    copp = vector<ll>();
    for (ll j : cpla) {
      for (ll k : bwd[j]) {
        if (judge[k] != 0) continue;
        bool succ = true;
        for (ll m : fwd[k]) {
          if (judge[m] != PLA) {
            succ = false;
            break;
          }
        }
        if (succ) {
          copp.push_back(k);
          judge[k] = OPP;
        }
      }
    }
    if (copp.empty()) break;
  }
  for (ll i = 0; i < N; i++) {
    ll a = enc(S[i].substr(S[i].size() - 3, 3));
    if (judge[a] == PLA) {
      cout << "Aoki\n";
    }else if (judge[a] == OPP) {
      cout << "Takahashi\n";
    }else {
      cout << "Draw\n";
    }
  }

  return 0;
}

