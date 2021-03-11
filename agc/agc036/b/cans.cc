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

ll N, K;
vector<ll> A;
vector<ll> lastPos;
vector<ll> nextOccDist;
vector<ll> revNOD;
ll aLim = 2e5;
vector<ll> cleared;

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

  cin >> N >> K;
  A.resize(N);
  lastPos.resize(aLim+1, -1);
  nextOccDist.resize(N);
  revNOD.resize(N);
  for (ll i = 0; i < N; i++)  cin >> A.at(i);
  for (ll i = 0; i < N; i++) {
    ll a = A.at(i);
    ll p = lastPos.at(a);
    if (p >= 0)  {
      nextOccDist.at(p) = i - p;
      revNOD.at(i % N) = i - p;
    }
    lastPos.at(a) = i;
  }
  for (ll i = 0; i < N; i++) {
    ll a = A.at(i);
    ll p = lastPos.at(a);
    if (p >= 0)  {
      nextOccDist.at(p) = N + i - p;
      revNOD.at(i % N) = N + i - p;
    }
    lastPos.at(a) = -1;
  }


  cleared.resize(N, -1);
  ll i = 0;
  while (i < N*K && cleared.at(i % N) == -1) {
    cleared.at(i % N) = i;
    i += nextOccDist.at(i % N) + 1;
  }
  if (i <= N*K) {
    ll dist = i - cleared.at(i % N);
    assert (dist % N == 0);
    i +=  dist * ((N * K - i) / dist);
  }else {
    i = 0;
  }

  vector<ll> answer;
  while (1) {
    while (1) {
      ll j = i + nextOccDist.at(i % N) + 1;
      if (j > N*K) break;
      i = j;
    }
    if (i == N*K) { break; }
    answer.push_back(A.at(i % N));
    i += 1;
  }

  if (answer.size() > 0) {
    for (ll t = 0; t < (ll)answer.size(); t++) {
      if (t > 0) { cout << " "; }
      cout << answer.at(t);
    }
    cout << endl;
  }

  return 0;
}

