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

  int N, K; cin >> N >> K;
  vector<int> P(N);
  for (int i = 0; i < N; i++) cin >> P.at(i);

  vector<bool> incK(N);
  {
    int i = 1;
    int cont = 1;
    while (i < N) {
      if (P.at(i-1) < P.at(i)) {
	cont++;
	if (cont >= K) incK.at(i+1-K) = true;
      }else cont = 1;
      i++;
    }
  }

  int count = 0;
  bool seeInc = false;
  set<int> cset;
  for (int i = 0; i < K; i++) cset.insert(P.at(i));
  count = 1;
  if (incK.at(0)) seeInc = true;
  for (int i = 1; i < N-K+1; i++) {
    auto itSmall = cset.begin();
    auto itBig = cset.rbegin();
    if (incK.at(i)) {
      if (!seeInc) {
	count ++;
	seeInc = true;
      }
    }else if (*itSmall == P.at(i-1) && *itBig < P.at(i+K-1)) {
      // do nothing
    }else {
      count ++;
    }
    cset.erase(P.at(i-1));
    cset.insert(P.at(i+K-1));
  }
  cout << count << endl;

  return 0;
}

