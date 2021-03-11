#include <bits/stdc++.h>
#include <cassert>
#include <chrono>
typedef long long int ll;
using namespace std;

// @@ !! LIM(cmpNaive)
// --> cmpNaive
// ---- inserted library file cmpNaive.cc

const string end_mark("^__=end=__^");

int naive(istream& cin, ostream& cout);
int body(istream& cin, ostream& cout);

void cmpNaive() {
  while (true) {
    string s;
    getline(cin, s);
    bool run_body;
    if (s.at(0) == 'Q') {
      return;
    }else if (s.at(0) == 'B') {
      run_body = true;
    }else if (s.at(0) == 'N') {
      run_body = false;
    }else {
      cerr << "Unknown body/naive specifier.\n";
      exit(1);
    }
    string input_s;
    while (true) {
      getline(cin, s);
      if (s == end_mark) break;
      input_s += s;
      input_s += "\n";
    }
    stringstream ss_in(move(input_s));
    stringstream ss_out;
    if (run_body) {
      body(ss_in, ss_out);
    }else {
      naive(ss_in, ss_out);
    }
    cout << ss_out.str() << end_mark << endl;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if CMPNAIVE
  if (argc == 2) {
    if (strcmp(argv[1], "cmpNaive") == 0) {
      cmpNaive();
    }else if (strcmp(argv[1], "naive") == 0) {
      naive(cin, cout);
    }else if (strcmp(argv[1], "skip") == 0) {
      exit(0);
    }else {
      cerr << "Unknown argument.\n";
      exit(1);
    }
  }else {
#endif
    body(cin, cout);
#if CMPNAIVE
  }
#endif
  return 0;
}

/*
int naive(istream& cin, ostream& cout) {
  return 0;
}
int body(istream& cin, ostream& cout) {
  return 0;
}
*/

// ---- end cmpNaive.cc
// @@ !! LIM  -- end mark --

int naive(istream& cin, ostream& cout) {
  ll n, q; cin >> n >> q;
  vector<ll> A(n + 1);
  const ll lim = 110;
  for (ll i = 1; i <= n; i++) cin >> A[i];
  for (ll qq = 0; qq < q; qq++) {
    ll t, b, c; cin >> t >> b >> c;
    if (t == 1) {
      vector<ll> count(lim);
      vector<ll> csize(lim);
      for (ll i = b; i <= c; i++) count[A[i]]++;
      for (ll i = 0; i < lim; i++) csize[count[i]]++;
      for (ll i = 0; i < lim; i++) {
        if (csize[i] == 0) {
          cout << i << "\n";
          break;
        }
      }
    }else {
      A[b] = c;
    }
  }
  

  return 0;
}
int body(istream& cin, ostream& cout) {

  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  ll n, q; cin >> n >> q;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  vector<ll> T(q), B(q), C(q);
  for (ll i = 0; i < q; i++) {
    cin >> T[i] >> B[i] >> C[i];
    if (T[i] == 1) B[i]--;
    if (T[i] == 2) B[i]--;
  }
  map<ll, ll> app;
  for (ll i = 0; i < n; i++) app[A[i]] = 1;
  for (ll i = 0; i < q; i++) if (T[i] == 2) app[C[i]] = 1;
  ll sz = app.size();
  {
    ll i = 1;
    for (auto& [a, v]  : app) v = i++;
  }
  for (ll i = 0; i < n; i++) A[i] = app[A[i]];
  for (ll i = 0; i < q; i++) if (T[i] == 2) C[i] = app[C[i]];

  std::chrono::steady_clock::time_point end;
  end = std::chrono::steady_clock::now();
  cerr << "Point1" << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "\n";

  using modify_t = tuple<ll, ll, ll>; // index, old, new
  vector<modify_t> modify;
  using q_t = tuple<ll, ll, ll, ll>; // q_id, time, left, right(+1)
  vector<q_t> query;
  {
    ll tm = 0;
    auto AA(A);
    for (ll i = 0; i < q; i++) {
      if (T[i] == 1) query.emplace_back(i, tm, B[i], C[i]);
      else if (T[i] == 2) {
        modify.emplace_back(B[i], AA[B[i]], C[i]);
        AA[B[i]] = C[i];
        tm++;
      }
    }
  }
  end = std::chrono::steady_clock::now();
  cerr << "Point2" << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "\n";

  ll P = max(1LL, llround(pow(double(n), 0.66)));
  cerr << "P = " << P << "\n";
  sort(query.begin(), query.end(),
       [&](const q_t& q1, const q_t& q2) -> bool {
         const auto& [q_id1, tm1, l1, r1] = q1;
         const auto& [q_id2, tm2, l2, r2] = q2;
         if (tm1 / P != tm2 / P) return tm1 / P < tm2 / P;
         if (l1 / P != l2 / P) return l1 / P < l2 / P;
         return r1 < r2;
       });

  end = std::chrono::steady_clock::now();
  cerr << "Point3" << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "\n";

  vector<ll> count(sz + 1);
  vector<ll> csize(n + 2);
  ll l0 = 0;
  ll r0 = 0;
  ll tm0 = 0;
  ll op_count = 0;
  auto mod_x = [&](ll x, ll diff) -> void {
    ll c = count[x];
    csize[c]--;
    csize[c + diff]++;
    count[x] += diff;
  };
  auto inc_x = [&](ll x) -> void {
    ll& c = count[x];
    csize[c]--;
    c++;
    csize[c]++;
  };
  auto dec_x = [&](ll x) -> void {
    ll& c = count[x];
    csize[c]--;
    c--;
    csize[c]++;
  };
  vector<ll> ans(q);
  for (const auto& [q_id, tm, l, r] : query) {
    while (r0 < r) {
      inc_x(A[r0]);
      // mod_x(A[r0], 1);
      r0++;
      op_count++;
    }
    while (l < l0) {
      l0--;
      inc_x(A[l0]);
      // mod_x(A[l0], 1);
      op_count++;
    }
    while (r < r0) {
      r0--;
      dec_x(A[r0]);
      // mod_x(A[r0], -1);
      op_count++;
    }
    while (l0 < l) {
      dec_x(A[l0]);
      // mod_x(A[l0], -1);
      l0++;
      op_count++;
    }
    while (tm0 < tm) {
      const auto& [idx, old_v, new_v] = modify[tm0];
      assert(A[idx] == old_v);
      A[idx] = new_v;
      if (l <= idx && idx < r) {
        dec_x(old_v);
        inc_x(new_v);
        // mod_x(old_v, -1);
        // mod_x(new_v, +1);
      }
      tm0++;
      op_count++;
    }
    while (tm < tm0) {
      tm0--;
      const auto& [idx, old_v, new_v] = modify[tm0];
      assert(A[idx] == new_v);
      A[idx] = old_v;
      if (l <= idx && idx < r) {
        dec_x(new_v);
        inc_x(old_v);
        // mod_x(new_v, -1);
        // mod_x(old_v, +1);
      }
      op_count++;
    }
    for (ll i = 1; i < (ll)csize.size(); i++) {
      if (csize[i] == 0) {
        ans[q_id] = i;
        break;
      }
    }
  }
  end = std::chrono::steady_clock::now();
  cerr << "Point4" << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "\n";

  cerr << "op_count = " << op_count << endl;

  for (ll i = 0; i < q; i++) {
    if (T[i] == 1) cout << ans[i] << "\n";
  }
  return 0;
}

