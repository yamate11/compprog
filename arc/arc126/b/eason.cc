#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#define F(T, i, a, b) for(T (i) = (a); (i) <= (b); ++(i))
#define R(T, i, a, b) for(T (i) = (a); (i) >= (b); --(i))
#define Fo(T, i, a, b, c) for(T (i) = (a); (i) <= (b); (i) += (c))
#define Re(T, i, a, b, c) for(T (i) = (a); (i) >= (b); (i) -= (c))
#define For(T, i, a, b, c) for(T (i) = (a); (i) <= (b); (i) *= (c))
#define Rep(T, i, a, b, c) for(T (i) = (a); (i) >= (b); (i) /= (c))
#define ll long long
#define ull unsigned long long
#define Tl template<typename T>
#define Tla template<typename T, typename... Args>
#define ii inline int
#define ill inline ll
#define iull inline ull
#define iv inline void
using namespace std;

namespace fastIO {
    const int L = 1 << 15;
    char buf[L], *s = buf, *t = buf;
    inline int gc() {if(s == t) {t = (s = buf) + fread(buf, 1, L, stdin); if(s == t) return EOF;} return *s++;}
    Tl iv read(T& x) {T f = 1; x = 0; int c = gc(); while(c < 48 || c > 57) {if(c == '-') f = -1; c = gc();} while(c >= 48 && c <= 57) {x = x * 10 + c - '0'; c = gc();} x *= f;}
    Tla iv read(T& x, Args& ...args) {read(x), read(args...);}
    Tl iv write(T x) {if(x < 0) {putchar('-'), x = -x;} if(x > 9) write(x / 10); putchar(x % 10 + '0');}
    iv file(string s) {freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout);}
}
using namespace fastIO;
#define MT int Test; read(Test); while(Test--)
#define MCase int Test; read(Test); F(int, kase, 1, Test)

double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

namespace Solution {
    const int N = 2e5 + 7;
    int n, m, ans, sum[N], f[N];
    struct node {
        int a, b;
        bool operator < (const node& t) const {return a < t.a;}
    }a[N];

    iv add(int x, int v) {for(; x <= n; sum[x] = max(sum[x], v), x += (x & -x));}
    ii qry(int x) {int res = 0; for(; x; res = max(res, sum[x]), x ^= (x & -x)); return res;}

    iv Main() {
      double t1 = get_time_sec();
        read(n, m);
        F(int, i, 1, m) read(a[i].a, a[i].b);
      double t2 = get_time_sec();
        sort(a + 1, a + m + 1);
      double t3 = get_time_sec();
        for(int i = 1, j = 0; i <= m; ++i) {
            for(; j < i && a[j].a < a[i].a; ++j)
                if(j) add(a[j].b, f[j]);
            ans = max(ans, f[i] = qry(a[i].b - 1) + 1);
        }
      double t4 = get_time_sec();
        write(ans);
        cerr << endl;
        cerr << t2 - t1 << endl;
        cerr << t3 - t2 << endl;
        cerr << t4 - t3 << endl;
        return;
    }
}

int main() {
    Solution :: Main();
    return 0;
}
/*
2 2 2 2 2
2 2 2 4
2 2 3 3
4 3 3
2 4 4

*/
