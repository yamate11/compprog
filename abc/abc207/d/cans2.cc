#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(ipoint f:itrange)

// ---- inserted library file ipoint.cc

struct IPoint {
  ll x;
  ll y;
  IPoint(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}

  IPoint rotate(int r = 1) const {
    ll rd = r % 4;
    ll rr = r >= 0 ? rd : rd == 0 ? 0 : rd + 4;
    if      (rr == 0) return IPoint( x,  y);
    else if (rr == 1) return IPoint(-y,  x);
    else if (rr == 2) return IPoint(-x, -y);
    else if (rr == 3) return IPoint( y, -x);
    assert(0);
  }

  IPoint mirror_x() const { return IPoint(x, -y); }
  IPoint mirror_y() const { return IPoint(-x, y); }

  bool parallel(const IPoint o) const { return x * o.y == y * o.x; }

  IPoint& operator +=(const IPoint& o) {
    x += o.x;
    y += o.y;
    return *this;
  }

  IPoint& operator -=(const IPoint& o) {
    x -= o.x;
    y -= o.y;
    return *this;
  }

  IPoint& operator *=(ll k) {
    x *= k;
    y *= k;
    return *this;
  }

  bool operator ==(const IPoint& o) const { return x == o.x && y == o.y; }
  bool operator !=(const IPoint& o) const { return x != o.x || y != o.y; }
  IPoint operator +(const IPoint& o) const { return IPoint(x, y) += o; }
  IPoint operator -(const IPoint& o) const { return IPoint(x, y) -= o; }
  IPoint operator *(ll k) const { return IPoint(x, y) *= k; }
  IPoint operator -() const { return IPoint(-x, -y); }

  bool operator <(const IPoint& o) const {
    // This seems awkward, but is needed for storing objects in maps.
    if (x != o.x) return x < o.x;
    else return y < o.y;
  }

};
    
IPoint operator *(ll k, const IPoint& p) { return p * k; }
istream& operator >>(istream& is, IPoint& p) {
  ll x_, y_; is >> x_ >> y_;
  p.x = x_;
  p.y = y_;
  return is;
}
ostream& operator <<(ostream& os, const IPoint& p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

namespace std {
  template<>
  struct hash<IPoint> {
    std::size_t operator()(const IPoint& p) const {
      return p.x * 37 + p.y * 41;
    }
  };
}

// ---- end ipoint.cc

// ---- inserted function f:itrange from util.cc

struct ItRange {
  ll st;
  ll en;

  struct Itr {
    using iterator_category = input_iterator_tag;
    using value_type = ll;
    using difference_type = ptrdiff_t;
    using reference = value_type const&;
    using pointer = value_type const*;

    ll val;

    bool operator ==(const Itr& o) const { return val == o.val; }
    bool operator !=(const Itr& o) const { return val != o.val; }

    reference operator *() const { return val; }
    pointer operator ->() const { return &val; }

    Itr& operator ++() {
      val++;
      return *this;
    }
    Itr operator ++(int) {
      Itr const tmp(*this);
      ++*this;
      return tmp;
    }

  };

  ItRange(ll v_start, ll v_end): st(v_start), en(v_end) {}
  Itr begin() { return Itr({st}); }
  Itr end() { return Itr({en}); }
};

// Imitation to Python range operator....


// ---- end f:itrange

// @@ !! LIM -- end mark --

ll len2(IPoint p) {
  return p.x * p.x + p.y * p.y;
}

ll outprod(IPoint p, IPoint q) {
  return p.x * q.y - p.y * q.x;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<IPoint> P(N), Q(N);
  for (ll i = 0; i < N; i++) cin >> P[i];
  for (ll i = 0; i < N; i++) cin >> Q[i];

  auto phase2 = [&](ll i0, ll j0, ll k0, IPoint v1, IPoint v2) -> void {
    ItRange rng(0, N);
    return any_of(rng.begin(), rng.end(), [&](ll i) {
      return any_of(rng.begin(), rng.end(), [&](ll j) {
        IPoint w1 = Q[j] - Q[i];
        if (len2(w1) != len2(v1)) return false;
        return any_of(rng.begin(), rng.end(), [&](ll k) {
          IPoint w2 = Q[k] - Q[i];
          if (len2(w2) != len2(v2)) return false;
          if (outprod(w1, w2) != outprod(v1, v2)) return false;
          return all_of(rng.begin(), rng.end(), [&](ll l) {
            if (l == i0 || l == j0 || l == k0) return true;
            return any_of(rng.begin(), rng.end(), [&](ll m) {
              if (m == i || m == j || m == k) return false;
              IPoint up = P[l] - P[i0];
              IPoint uq = Q[m] - Q[i];
              if (len2(up) != len2(uq)) return false;
              if (outprod(up, v1) != outprod(uq, w1)) return false;
              if (outprod(up, v2) != outprod(uq, w2)) return false;
              return true;
            });
          });
        });
      });
    });
  };

  for (ll i = 0; i < N; i++) {
    for (ll j = i + 1; j < N; j++) {
      for (ll k = j + 1; k < N; k++) {
        IPoint v1 = P[j] - P[i];
        IPoint v2 = P[k] - P[i];
        ll dir = outprod(v1, v2);
        if (dir != 0) {
          if (phase2(i, j, k, v1, v2)) cout << "Yes\n";
          else cout << "No\n";
          return 0;
        }
      }
    }
  }
  
  auto sameLine = [&]() -> bool {
    for (ll i = 1; i < N; i++) {
      IPoint v = P[i] - P[0];
      IPoint w = Q[i] - Q[0];
      if (len2(v) != len2(w)) return false;
    }
    return true;
  };
  sort(P.begin(), P.end());
  sort(Q.begin(), Q.end());
  if (sameLine()) {
    cout << "Yes\n";
    return 0;
  }
  reverse(Q.begin(), Q.end());
  if (sameLine()) {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";

  return 0;
}

