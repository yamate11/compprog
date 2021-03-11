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

  int N; cin >> N;
  vector<int> A(3*N);
  for (int i = 0; i < 3*N; i++) cin >> A.at(i);

  priority_queue<int, vector<int>, greater<int>> front;
  priority_queue<int> back;
  vector<ll> fv(N+1);
  vector<ll> bv(N+1);

  ll sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A.at(i);
    front.push(A.at(i));
  }
  fv.at(0) = sum;
  for (int i = 0; i < N; i++) {
    int a = A.at(N + i);
    sum += a;
    front.push(a);
    int b = front.top(); front.pop();
    sum -= b;
    fv.at(i+1) = sum;
  }
  sum = 0;
  for (int i = N - 1; i >= 0; i--) {
    int a = A.at(2*N + i);
    sum += a;
    back.push(a);
  }
  bv.at(N) = sum;
  for (int i = N - 1; i >= 0; i--) {
    int a = A.at(N + i);
    sum += a;
    back.push(a);
    int b = back.top(); back.pop();
    sum -= b;
    bv.at(i) = sum;
  }
  ll ans = LLONG_MIN;
  for (int i = 0; i <= N; i++) {
    ans = max(ans, fv.at(i) - bv.at(i));
  }
  cout << ans << endl;


  return 0;
}

