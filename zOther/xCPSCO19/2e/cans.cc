#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#if defined(DEBUG)

#include <unistd.h>
#include <sys/fcntl.h>
#define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
#define DCALL(func, ...) func(__VA_ARGS__)

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#else  // defined(DEBUG)

#define DLOG(...)
#define DCALL(func, ...)

#endif // defined(DEBUG)

typedef pair<ll,ll> Pair;
typedef vector<Pair> Dinfo;

ll N;
vector<ll> parent;
vector<vector<ll>> child;
vector<ll> H;

Dinfo conv(Dinfo di1, Dinfo di2, ll lim) {
  Dinfo work;
  for (Pair p1 : di1) {
    for (Pair p2 : di2) {
      ll x = p1.first + p2.first;
      if (x > lim) continue;
      work.emplace_back(x, p1.second + p2.second);
    }
  }
  sort(work.begin(), work.end());
  Dinfo retval;
  ll prev = -1;
  for (ll i = 0; i < (ll)work.size(); i++) {
    if (i == (ll)work.size() - 1 || work.at(i).first != work.at(i+1).first) {
      if (work.at(i).second > prev) {
	retval.push_back(work.at(i));
	prev = work.at(i).second;
      }
    }
  }
  return retval;
}

Dinfo solve(ll n, ll lim) {
  ll newLim = min(lim, H.at(n));
  Dinfo di;
  if (child.at(n).size() == 0) {
    di = {make_pair(0, 0)};
  }else {
    ll c = child.at(n).at(0);
    di = solve(c, newLim);
    for (ll i = 1; i < (ll)child.at(n).size(); i++) {
      ll cc = child.at(n).at(i);
      Dinfo dic = solve(cc, newLim);
      di = conv(di, dic, newLim);
    }
  }
  if (n != 0 && H.at(n) <= lim) {
    if (di.size() == 0) {
      di.emplace_back(H.at(n), 1);
    }else {
      ll didx = di.size() - 1;
      Pair ld = di.at(didx);
      if (ld.first == H.at(n)) {
	di.at(didx) = make_pair(ld.first, ld.second + 1);
      }else {
	di.emplace_back(H.at(n), ld.second + 1);
      }
    }
  }
  return di;
}

int main(int argc, char *argv[]) {
#if defined(DEBUG)
  // GDB on Cygwin ignores redirection at run command.
  if (argc == 2) dup2(open(argv[1], 0), 0);
#else
  // For performance.  We should not use C-style stdio functions
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cout << setprecision(20);

  cin >> N;
  parent.resize(N); child.resize(N); H.resize(N);
  for (ll i = 1; i <= N-1; i++) {
    cin >> parent.at(i) >> H.at(i);
    child.at(parent.at(i)).push_back(i);
  }
  H.at(0) = (ll)(1e9) + 1;
  Dinfo di = solve(0, (ll)(1e9)+1);
  cout << di.at(di.size()-1).second + 1 << endl;

  return 0;
}

