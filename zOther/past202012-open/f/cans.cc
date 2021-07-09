#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(f:itrange)

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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> B(M);
  for (ll i = 0; i < M; i++) {
    ll a, b, c; cin >> a >> b >> c; a--; b--; c--;
    B[i] = (1LL << a) | (1LL << b) | (1LL << c);
  }
  ll ans = 0;
  ItRange r0M(0, M);
  for (ll x = 0; x < (1LL << N); x++) {
    if (any_of(r0M.begin(), r0M.end(), [&](ll i) -> bool {
      return (B[i] & ~x) == 0;
    })) continue;
    ll cnt = 0;
    for (ll j = 0; j < N; j++) {
      if (any_of(r0M.begin(), r0M.end(), [&](ll i) -> bool {
        return (B[i] & (~(x | (1LL << j)))) == 0;
      })) cnt++;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  
  return 0;
}

