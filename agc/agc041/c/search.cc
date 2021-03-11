#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// --- DEBUG begin --- cut here ---
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(Head&& head) {
  cerr << head << endl;
}

template <class Head, class... Tail>
void dbgLog(Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(__VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

// operator<< definitions for some classes

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig) {
  priority_queue<T, T2, T3> pq(orig);
  bool first = true;
  os << '[';
  while (!pq.empty()) {
    T x = pq.top(); pq.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}
// --- DEBUG end --- cut here ---



// --- FIX begin --- cut here ---
template<typename F>
class FixPoint : private F {
public:
  explicit constexpr FixPoint(F&& f) noexcept : F(forward<F>(f)) {}

  template<typename... Args>
  constexpr decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template<typename F>
static inline constexpr decltype(auto) fix(F&& f) noexcept {
  return FixPoint<F>{forward<F>(f)};
}
// --- FIX end --- cut here ---

vector<vector<char>> render(auto brd) {
  int N = brd.size();
  vector<vector<char>> ret(N, vector<char>(N, '.'));

  auto add1 = [&](auto& v, int jj, int ii) {
    if (0 <= jj && jj < N && 0 <= ii && ii < N) {
      if (ret.at(jj).at(ii) != '.') {
	v.at(ret.at(jj).at(ii) - 'a') = true;
      }
    }
  };
  auto add2 = [&](int jj, int ii, int pid, int sym) {
    if (0 <= jj && jj < N && 0 <= ii && ii < N) {
      if (brd.at(jj).at(ii) == pid) ret.at(jj).at(ii) = sym;
    }
  };

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      if (ret.at(j).at(i) != '.') continue;
      int pid = brd.at(j).at(i);
      if (pid == -1) continue;
      vector<bool> tmp(4);
      add1(tmp, j-1, i);
      add1(tmp, j-1, i+1);
      add1(tmp, j, i-1);
      char sym = -1;
      for (int c = 0; c < 4; c++) {
	if (!tmp.at(c)) {
	  sym = 'a' + c;
	  break;
	}
      }
      ret.at(j).at(i) = sym;
      add2(j+1, i, pid, sym);
      add2(j, i+1, pid, sym);
    }
  }
  return ret;
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N = stoi(argv[1]);
  int qual = stoi(argv[2]);
  vector<vector<int>> brd(N, vector<int>(N, -1));
  vector<int> qX(N);
  vector<int> qY(N);
  int pid = 0;
  auto sch = fix([&](const auto& recF, int y, int x) -> bool {
      DLOG("sch", y, x);
      if (x == 0) {
	if (y-1 >= 0 && qY.at(y-1) != qual) return false;
      }
      if (y == N) {
	for (int i = 0; i < N; i++) {
	  if (qX.at(i) != qual) return false;
	}
	return true;
      }
      int nxtX = x+1 < N ? x+1 : 0;
      int nxtY = x+1 < N ? y   : y+1;
      if (recF(nxtY, nxtX)) return true;
      if (brd.at(y).at(x) >= 0) {
	return false;
      }

      auto check = [&](int yy, int xx) {
	if (yy >= N || xx >= N) return false;
	if (brd.at(yy).at(xx) >= 0) return false;
	brd.at(yy).at(xx) = brd.at(y).at(x) = pid++;
	qY.at(y)++;
	qX.at(x)++;
	if (yy == y) qX.at(xx)++;
	else         qY.at(yy)++;
	DLOG("brd", brd);
	if (recF(nxtY, nxtX)) return true;
	pid--;
	brd.at(yy).at(xx) = brd.at(y).at(x) = -1;
	qY.at(y)--;
	qX.at(x)--;
	if (yy == y) qX.at(xx)--;
	else         qY.at(yy)--;
	return false;
      };
      return check(y, x+1) || check(y+1, x);
    });
  bool b = sch(0, 0);
  if (!b) {
    cout << "-1\n";
    return 0;
  }
  vector<vector<char>> rb = render(brd);
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) cout << rb.at(j).at(i);
    cout << "\n";
  }
  return 0;
}

