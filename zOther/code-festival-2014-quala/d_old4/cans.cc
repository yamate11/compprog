#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(cmpNaive)

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

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  ll A; ll K; cin >> A >> K;
  ll ans = 1e9;

  auto used = [&](ll x) -> ll {
    if (x == 0) return 1;
    ll cnt = 0;
    vector<bool> seen(10);
    while (x > 0) {
      ll y = x % 10;
      if (! seen[y]) {
        seen[y] = true;
        cnt++;
      }
      x = x / 10;
    }
    return cnt;
  };

  for (ll x = 0; x <= 11111; x++) {
    if (used(x) > K) continue;
    ans = min(ans, abs(A - x));
  }
  cout << ans << endl;
  return 0;
}
int body(istream& cin, ostream& cout) {

  string A; cin >> A;
  ll sz = A.size();
  if (sz == 1) {
    cout << 0 << endl;
    return 0;
  }

  ll val_orig = stoll(A);
  ll K; cin >> K;
  const ll big = 1e16;

  auto func = [&](ll t, bool isLower) -> ll {
    vector<bool> used(10);
    ll n_used = 0;
    ll val = 0;

    auto usable = [&](ll c, ll d) -> ll {
      for (c += d; 0 <= c && c <= 9; c += d) {
        if (used[c] || n_used < K) return c;
      }
      return -1;
    };

    auto use = [&](ll c) -> void {
      val = val * 10 + c;
      if (! used[c]) {
        used[c] = true;
        n_used++;
      }
    };

    for (ll i = 0; i < t; i++) {
      use(A[i] - '0');
      if (n_used > K) return big;
    }
    if (t < sz) {
      ll step = isLower ? -1 : 1;
      {
        ll c = usable(A[t] - '0', step);
        if (c < 0) return big;
        if (! (t == 0 && c == 0)) {
          use(c);
        }
      }
      for (ll i = t + 1; i < sz; i++) {
        ll c = usable(isLower ? 10 : -1, step);
        assert(c >= 0);
        use(c);
      }
    }
    return abs(val - val_orig);
  };

  ll ans = big;
  for (ll t = 0; t <= sz; t++) {
    ans = min(ans, func(t, true));
    ans = min(ans, func(t, false));
  }
  cout << ans << endl;

  return 0;
}

