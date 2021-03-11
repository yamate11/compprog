#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// See debug.cc for usage etc
#define DEBUG 0

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#if DEBUG
  #define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DCALL(func, ...)
#endif

enum EVtype { symS, symT, symX };

ll A, B, Q;
vector<ll> s, t, x;
vector<tuple<ll, EVtype, int>> ev;
vector <ll> v_p_s, v_p_t, v_n_s, v_n_t;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> A >> B >> Q;
  s.resize(A);
  for (int i = 0; i < A; i++) {
    cin >> s.at(i);
    ev.push_back(make_tuple(s.at(i), symS, 0));
  }
  t.resize(B);
  for (int i = 0; i < B; i++) {
    cin >> t.at(i);
    ev.push_back(make_tuple(t.at(i), symT, 0));
  }
  x.resize(Q);
  v_p_s.resize(Q);
  v_p_t.resize(Q);
  v_n_s.resize(Q);
  v_n_t.resize(Q);
  for (int i = 0; i < Q; i++) {
    cin >> x.at(i);
    ev.push_back(make_tuple(x.at(i), symX, i));
  }
  sort(ev.begin(), ev.end());
  ll prev_s = -2e10;
  ll prev_t = -2e10;
  vector <int> x_waiting_s;
  vector <int> x_waiting_t;
  for (auto e : ev) {
    DLOG("EVENT: %lld, %d, %d", get<0>(e), (int)get<1>(e), get<2>(e));
    if (get<1>(e) == symS) {
      for (int i : x_waiting_s)  v_n_s.at(i) = get<0>(e);
      x_waiting_s.resize(0);
      prev_s = get<0>(e);
    }else if (get<1>(e) == symT) {
      for (int i : x_waiting_t)  v_n_t.at(i) = get<0>(e);
      x_waiting_t.resize(0);
      prev_t = get<0>(e);
    }else { // e.second == symX
      int idx = get<2>(e);
      v_p_s.at(idx) = prev_s;
      v_p_t.at(idx) = prev_t;
      x_waiting_s.push_back(idx);
      x_waiting_t.push_back(idx);
    }
  }
  for (int i : x_waiting_s)  v_n_s.at(i) = 3e10;
  for (int i : x_waiting_t)  v_n_t.at(i) = 3e10;
  
  for (int i = 0; i < Q; i++) {
    DLOG("x.at(%d) = %lld, v_p_s = %lld, v_p_t = %lld, v_n_s = %lld, v_n_t = %lld", i, x.at(i), v_p_s.at(i), v_p_t.at(i), v_n_s.at(i), v_n_t.at(i));
    ll tx = x.at(i);
    ll cand1 = max(v_n_s.at(i), v_n_t.at(i)) - tx;
    ll cand2 = tx - min(v_p_s.at(i), v_p_t.at(i));
    ll cand3 = 5e10;
    if (v_n_s.at(i) < v_n_t.at(i) && v_p_s.at(i) < v_p_t.at(i)) {
      cand3 = v_n_s.at(i) - v_p_t.at(i)
	+ min(v_n_s.at(i) - tx, tx - v_p_t.at(i));
    }
    if (v_n_s.at(i) > v_n_t.at(i) && v_p_s.at(i) > v_p_t.at(i)) {
      cand3 = v_n_t.at(i) - v_p_s.at(i)
	+ min(v_n_t.at(i) - tx, tx - v_p_s.at(i));
    }
    DLOG("cand1 = %lld, cand2 = %lld, cand3 = %lld", cand1, cand2, cand3);
    cout << min(cand1, min(cand2, cand3)) << "\n";
  }

  return 0;
}

