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

ll N, Q;
set<ll> A;

void myAdd(ll x) {
  auto it = A.find(x);
  if (it == A.end()) A.insert(x);
  else               A.erase(it);
}

int main(int argc, char *argv[]) {
#if defined(DEBUG)
  // GDB on Cygwin ignores redirection at run command.
  if (argc == 2) dup2(open(argv[1], 0), 0);
#else
  // For performance.  We should not use C-style stdio functions
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> N >> Q;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    myAdd(a);
  }
  for (ll j = 0; j < Q; j++) {
    ll l, r, x; cin >> l >> r >> x;
    ll ax = 0;
    ll cnt = 0;
    {
      auto itB = A.lower_bound(l);
      auto it = itB;
      for ( ; it != A.end() && *it <= r; it++) {
	ax ^= *it;
	cnt++;
      }
      A.erase(itB, it);
    }
    cout << ax << "\n";
    if (cnt % 2 == 1)  myAdd(x);
  }

  return 0;
}

