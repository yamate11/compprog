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
  vector A(N, vector<ll>());
  for (ll i = 0; i < N; i++) {
    ll k; cin >> k;
    A[i].resize(k);
    for (ll j = 0; j < k; j++) cin >> A[i][j];
  }
  ll P, Q; cin >> P >> Q;
  vector<ll> B(P);
  for (ll i = 0; i < P; i++) cin >> B[i];
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ll cnt = 0;
    for (ll a : A[i]) {
      if (any_of(B.begin(), B.end(), [&](ll b) -> bool {
        return b == a;
      })) cnt++;
    }
    if (cnt >= Q) ans++;
  }
  cout << ans << endl;

  return 0;
}

