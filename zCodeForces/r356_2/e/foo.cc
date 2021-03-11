#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(binsearch)
// --> binsearch
// ---- inserted library file binsearch.cc

template<typename T>
T binsearch(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / (T)2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  Board<char> brd(cin, n, n, 'X');
  
  Board<ll> cc(n, n, -1);
  vector<ll> ccsize;
  ll seq = 0;
  auto dfs = [&](auto rF, const BrdIdx& bi) -> ll {
    if (brd.at(bi) == 'X' || cc.at(bi) == seq) return 0;
    ll ret = 1;
    assert(cc.at(bi) == -1);
    cc.at(bi) = seq;
    for (const BrdIdx& bd : BrdIdx::nbr4) {
      ret += rF(rF, bi + bd);
    }
    return ret;
  };
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      if (brd.at(i, j) == '.' && cc.at(i, j) == -1) {
	ccsize.push_back(dfs(dfs, BrdIdx(i, j)));
	seq++;
	assert((ll)ccsize.size() == seq);
      }
    }
  }
  ll numcc = seq;
  ll vmax = 0;

  for (ll i = 0; i <= n - k; i++) {

    ll nw = 0;
    ll nc = 0;
    vector<ll> tcc(numcc);

    auto cc_cnt_plus = [&](ll j, ll m) -> void {
      if (brd.at(j, m) != '.') return;
      ll p = cc.at(j, m);
      if (tcc[p] == 0) nc += ccsize[p];
      tcc[p]++;
    };
    auto cc_cnt_minus = [&](ll j, ll m) -> void {
      if (brd.at(j, m) != '.') return;
      ll p = cc.at(j, m);
      if (tcc[p] == 1) nc -= ccsize[p];
      tcc[p]--;
    };

    for (ll j = 0; j < k; j++) {
      for (ll m = 0; m < k; m++) {
	if (brd.at(i + j, m) == 'X') nw++;
	else cc_cnt_plus(i + j, m);
      }
    }
    for (ll j = 0; j < k; j++) {
      cc_cnt_plus(i - 1, j);
      cc_cnt_plus(i + k, j);
      cc_cnt_plus(i + j, k);
    }
    DLOG("i=", i, "j= 0 nw=", nw, "nc=", nc);
    vmax = max(vmax, nw + nc);

    for (ll j = 0; j < n - k; j++) {
      for (ll m = 0; m < k; m++) {
	if (brd.at(i + m, j + k) == 'X') nw++;
	if (brd.at(i + m, j) == 'X') nw--;
	cc_cnt_plus(i + m, j + k + 1);
	cc_cnt_minus(i + m, j - 1);
      }
      cc_cnt_plus(i - 1,  j + k);
      cc_cnt_plus(i + k,  j + k);
      cc_cnt_minus(i - 1, j);
      cc_cnt_minus(i + k, j);
      DLOG("i=", i, "j=", j+1, "nw=", nw, "nc=", nc);
      vmax = max(vmax, nw + nc);
    }
  }
  cout << vmax << endl;

  return 0;
}

