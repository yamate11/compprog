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

struct AInfo {
  int black;
  int y0;
  int y1;
  int x0;
  int x1;
  AInfo(int b, int q0, int q1, int p0, int p1)
    : black(b), y0(q0), y1(q1), x0(p0), x1(p1) {}
};

int H, W;
vector<vector<bool>> brd;

void area(int, int, AInfo&);

void jtry(int i, int j, AInfo& ai) {
  if (i < 0 || H <= i || j < 0 || W <= j) return;
  if (!brd.at(i).at(j)) return;
  brd.at(i).at(j) = false;
  ai.black++;
  ai.y0 = min(ai.y0, i);
  ai.y1 = max(ai.y1, i);
  ai.x0 = min(ai.x0, j);
  ai.x1 = max(ai.x1, j);
  area(i, j, ai);
}

void area(int i, int j, AInfo& ai) {
  for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      if (di == 0 && dj == 0) continue;
      jtry(i - di, j + dj, ai);
    }
  }
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

  cin >> H >> W;
  brd.resize(H, vector<bool>(W));
  for (int i = 0; i < H; i++) {
    string s; cin >> s;
    for (int j = 0; j < W; j++) brd.at(i).at(j) = s.at(j) == 'o';
  }

  int numA = 0;
  int numB = 0;
  int numC = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (!brd.at(i).at(j)) continue;
      brd.at(i).at(j) = false;
      AInfo ai(1, i, i, j, j);
      area(i, j, ai);
      int h = ai.y1 - ai.y0 + 1;
      int w = ai.x1 - ai.x0 + 1;
      assert((h == w) && (h % 5 == 0));
      int d = h / 5;
      int bl = ai.black / (d*d);
      if (bl == 12) numA++;
      else if (bl == 16) numB++;
      else if (bl == 11) numC++;
      else assert(false);
    }
  }
  cout << numA << " " << numB << " " << numC << endl;

  return 0;
}

