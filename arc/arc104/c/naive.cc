#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
  if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
  if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  rep(i, v.size()) {
    if (i) os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
#define debug(...) \
  cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

int main() {
  int N;
  cin >> N;
  V<int> A(N), B(N);
  int sz = N * 2;
  V<int> tp(sz), com(sz, -1);

  bool ng = false;

  rep(i, N) {
    cin >> A[i] >> B[i];
    if (A[i] != -1) {
      --A[i];
      if (tp[A[i]]) ng = true;
      tp[A[i]] = i + 1;
    }
    if (B[i] != -1) {
      --B[i];
      if (tp[B[i]]) ng = true;
      tp[B[i]] = -(i + 1);
    }

    if (A[i] != -1 && B[i] != -1) {
      com[A[i]] = B[i];
      com[B[i]] = A[i];
    }
  }
  if (ng) {
    puts("No");
    return 0;
  }

  V<bool> dp(sz + 1);
  dp[0] = true;

  rep(i, sz) {
    if (!dp[i]) continue;
    for (int j = i + 1; j < sz; ++j) {
      int w = j - i + 1;
      if (w & 1) continue;
      w /= 2;
      bool ok = true;
      V<bool> exist(N);

      rep(k, w) {
	int p = i + k, q = i + k + w;
	if (com[p] != -1 && !(i <= com[p] && com[p] <= j)) {
	  ok = false;
	}
	if (com[q] != -1 && !(i <= com[q] && com[q] <= j)) {
	  ok = false;
	}

	bool same = true;
	if (tp[p] != 0 && tp[q] != 0) {
	  if (tp[p] < 0 || tp[p] + tp[q] != 0) {
	    ok = false;
	  } else
	    same = true;
	}
	if (tp[p] < 0 || tp[q] > 0) {
	  ok = false;
	} else {
	  if (tp[p] != 0) {
	    int v = tp[p] - 1;
	    if (exist[v]) {
	      ok = false;
	    }
	    exist[v] = true;
	  }
	  if (!same && tp[q] != 0) {
	    int v = -tp[q] - 1;
	    if (exist[v]) {
	      ok = false;
	    }
	    exist[v] = true;
	  }
	}
      }
      if (ok) {
	dp[j + 1] = true;
      }
    }
  }
  puts(dp[sz] ? "Yes" : "No");

  return 0;
}
