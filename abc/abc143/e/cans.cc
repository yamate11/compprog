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
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
typedef pair<ll, ll> Pair;

ll big = (ll)(1e18);
// Pair big = make_pair(i_big, 0);

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

  ll N, M, L; cin >> N >> M >> L;
  // vector<int> A(M), B(M), C(M);
  vector<vector<ll>> dist1(N, vector<ll>(N, big));
  vector<vector<ll>> dist2(N, vector<ll>(N, big));
  for (int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c; a--; b--;
    /*
    A.at(i) = a;
    B.at(i) = b;
    C.at(i) = c;
    */
    dist1.at(a).at(b) = dist1.at(b).at(a) = c;
  }
  for (int i = 0; i < N; i++) dist1.at(i).at(i) = 0;

  /*
  auto conc = [&](Pair x, Pair y) -> Pair {
    ll x1 = x.first;
    ll x2 = x.second;
    ll y1 = y.first;
    ll y2 = y.second;
    if (x2 + y2 <= L) return make_pair(x1 + y1,     x2 + y2);
    else              return make_pair(x1 + y1 + 1, x2 + y2 - L);
  };
  */

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
	dist1.at(i).at(j) = min(dist1.at(i).at(j),
				dist1.at(i).at(k) + dist1.at(k).at(j));
      }
    }
  }

  for (int i = 0; i < N; i++) {
    dist2.at(i).at(i) = 0;
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      if (dist1.at(i).at(j) <= L) dist2.at(i).at(j) = 1;
      else                        dist2.at(i).at(j) = big;
    }
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
	dist2.at(i).at(j) = min(dist2.at(i).at(j),
				dist2.at(i).at(k) + dist2.at(k).at(j));
      }
    }
  }

  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int s, t; cin >> s >> t; s--; t--;
    ll d = dist2.at(s).at(t);
    if (d > (int)(1e9)) d = -1;
    else d = d - 1;
    cout << d << "\n";
  }

  return 0;
}

