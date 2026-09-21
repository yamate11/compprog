#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

// T must be integral or floating
template<typename T = long long, typename comp = less<T>>
requires (std::integral<T> || std::floating_point<T>)
struct LiChaoDyn {
  struct Line {
    T a{};
    T b{};
    T val_at(T t) const { return a * t + b; }
  };

  struct Node {
    Line line;
    Node* cldL{};
    Node* cldH{};
    Node(Line line_ = Line{}) : line(line_) {}
    T val_at(T t) const { return line.val_at(t); }
  };

  T range_min;
  T range_max;
  Node* root{};
  
  LiChaoDyn(T rmin, T rmax) : range_min(rmin), range_max(rmax) {}

  static T _better(T t1, T t2) { return comp(t1, t2) ? t1 : t2; };

  void _sub_add_line(Node* p, T lo, T hi, Line y) {
    if (not p) p = new Node(a, b);
    else {
      bool r_Lo  = comp(p->val_at(lo), y.val_at(lo));
      bool r_hi  = comp(p->val_at(hi), y.val_at(hi));
      if (r_lo and r_hi) return;
      if (not r_lo and not r_hi) { p->line = y; return; }
      T mid = (lo + hi) / 2;
      bool r_mid = comp(p->val_at(mid), y.val_at(mid));
      if (not r_mid) swap(p->line, y);
      if (r_lo)      _sub_add_line(p->cldH, mid, hi, y);
      else if (r_hi) _sub_add_line(p->cldL, lo, mid, y);
      else assert(0);
    }
  }
  void add_line(T a, T b) { _sub_add_line(root, range_min, range_max, Line{a, b}); }

  T _sub_query(Node* p, T lo, T hi, T t) const {
    if (not p) { throw runtime_error("LiChaoDyn.query: null pointer"); }
    T thisval = p->val_at(t);
    if (not p->cldL and not p->cldH) return thisval;
    T mid = (lo + hi) / 2;
    if (t < mid) return p->cldL ? _better(thisval, _sub_query(p->cldL, lo, mid, t)) : thisval;
    else         return p->cldH ? _better(thisval, _sub_query(p->cldH, mid, hi, t)) : thisval;
  }
  T query(T t) const { _sub_query(root, range_min, range_max, t); }
};



int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  return 0;
}

