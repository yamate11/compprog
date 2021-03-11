#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(intervalSet)
// --> intervalSet
// ---- inserted library file intervalSet.cc

using itv_elem_t = pair<ll, ll>;
using itv_set = set<itv_elem_t>;

// internal use
itv_set::iterator itv_right(itv_set& s, ll x) {
  return s.lower_bound(itv_elem_t(x + 1, x));
}

// Checks if x is in an interval in s.
//   Returns an iterator to [a, b) \in s such that x \in [a, b),
//   or s.end() if no such interval exisits.
itv_set::iterator itv_in(itv_set& s, ll x) {
  auto it = itv_right(s, x);
  if (it == s.begin()) return s.end();
  it--;
  if (x < it->second) return it;
  else                return s.end();
}

// Add a value x to interval set s, if x is not in Union(s).
//    Returns true if x was not in Union(s) and is now added.
//    Returns false if x was already in Union(s).
bool itv_add(itv_set& s, ll x) {
  auto it_r = itv_right(s, x);
  bool mg_r = false;
  if (it_r != s.end() && x + 1 == it_r->first) mg_r = true;
  bool mg_l = false;
  auto it_l = it_r;
  if (it_r != s.begin()) {
    it_l--;
    if (x < it_l->second)  return false;   // x is included in an interval.
    if (x == it_l->second) mg_l = true;
  }
  if (mg_l && mg_r) {
    s.emplace_hint(it_r, it_l->first, it_r->second);
    s.erase(it_l);
    s.erase(it_r);
  }else if (mg_l) {
    s.emplace_hint(it_r, it_l->first, it_l->second + 1);
    s.erase(it_l);
  }else if (mg_r) {
    s.emplace_hint(it_r, it_r->first - 1, it_r->second);
    s.erase(it_r);
  }else {
    s.emplace_hint(it_r, x, x + 1);
  }
  return true;
}

// Delete a value x from interval set s, if x is in Union(s).
//    Returns true if x was in Union(s) and is now deleted.
//    Returns false if x was not in Union(s).
bool itv_del(itv_set& s, ll x) {
  auto it = itv_in(s, x);
  if (it == s.end()) return false;
  auto nxt = it; nxt++;
  if (it->first == x && it->second == x + 1) {
    s.erase(it);
  }else if (it->first == x) {
    s.emplace_hint(nxt, it->first + 1, it->second);
    s.erase(it);
  }else if (it->second == x + 1) {
    s.emplace_hint(nxt, it->first, it->second - 1);
    s.erase(it);
  }else {
    s.emplace_hint(it, it->first, x);
    s.emplace_hint(nxt, x + 1, it->second);
    s.erase(it);
  }
  return true;
}

// Constructs an interval set from a sorted vector, typically vector<ll>.
itv_set from_sorted_vector(const auto& vec) {
  itv_set is;
  ll sz = vec.size();
  ll st = -1;
  for (ll i = 0; i < sz; i++) {
    if (i == 0 || vec[i-1] + 1 < vec[i])  {
      st = vec[i];
    }
    if (i+1 == sz || vec[i] + 1 < vec[i+1]) {
      is.emplace_hint(is.end(), st, vec[i] + 1);
    }
  }
  return is;
}

// ---- end intervalSet.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  vector<ll> B;
  vector<ll> cnt(N);
  for (ll i = 0; i < M; i++) {
    ll v = A[i];
    if (cnt[v] == 0) B.push_back(v);
    cnt[v]++;
  }
  sort(B.begin(), B.end());
  auto is = from_sorted_vector(B);
  auto mex = [&]() -> ll {
    auto [a, b] = *is.begin();
    if (0 < a) return 0;
    else return b;
  };
  ll ans = mex();
  for (ll i = M; i < N; i++) {
    ll j = i - M;
    if (cnt[A[j]] == 1) itv_del(is, A[j]);
    cnt[A[j]]--;
    if (cnt[A[i]] == 0) itv_add(is, A[i]);
    cnt[A[i]]++;
    ans = min(ans, mex());
  }
  cout << ans << endl;

  return 0;
}

