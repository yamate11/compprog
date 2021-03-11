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

typedef pair<int, int> Pair;
typedef vector<Pair> Path;

int K, X, Y;

Path revert(Path path, bool xRev, bool yRev, bool xySwap) {
  Path ret;
  for (Pair p : path) {
    if (xySwap) swap(p.first, p.second);
    if (yRev) p.second = -p.second;
    if (xRev) p.first = -p.first;
    ret.push_back(p);
  }
  return ret;
}

bool normal(int& Z) {
  if (Z < 0) {
    Z = -Z;
    return true;
  }
  return false;
}

void getPQ(int& p, int& q) {
  int s = (X+Y) % K;
  int r = s == 0 ? 0 : K - s;
  if (X + Y < K) {
    if (K % 2 != 0 && (X + Y) % 2 != 0) {
      p = K - (X + Y);
      q = (K + (X + Y)) / 2;
    }else {
      p = (r + K) / 2;
      q = 0;
    }
  }else {
    q = 0;
    if (r % 2 == 0)  p = r     / 2;
    else             p = (r+K) / 2;
  }
}

Path solve() {
  Path ret;
  int p, q; getPQ(p, q);
  int x = X + p;
  int y = Y + q;
  while (x >= K) {
    ret.emplace_back(K, 0);
    x -= K;
  }
  if (x > 0) {
    ret.emplace_back(x, K - x);
    y -= K - x;
  }
  while (y >= K) {
    ret.emplace_back(0, K);
    y -= K;
  }
  x = p;
  if (y > 0) {
    ret.emplace_back(-(K - y), y);
    x -= K - y;
  }
  if (x > 0 || q > 0) {
    ret.emplace_back(-x, -q);
  }
  return ret;
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

  cin >> K >> X >> Y;
  
  if (K % 2 == 0 && (X+Y) % 2 != 0) {
    cout << "-1\n";
    return 0;
  }
  bool xRev = normal(X);
  bool yRev = normal(Y);
  bool xySwap = false;
  if (X > Y) {
    swap(X, Y);
    xySwap = true;
  }
  Path path = solve();
  Path answer = revert(path, xRev, yRev, xySwap);
  cout << answer.size() << endl;
  int x = 0;
  int y = 0;
  for (Pair p : answer) {
    x += p.first;
    y += p.second;
    cout << x << " " << y << "\n";
  }

  return 0;
}

