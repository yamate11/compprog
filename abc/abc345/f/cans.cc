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
    ss_out << setprecision(20);
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
  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N, M, K; cin >> N >> M >> K;
  // @InpMVec(M, ((U, dec=1), (V, dec=1))) [shGBSE7u]
  auto U = vector(M, ll());
  auto V = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; U[i] = v1;
    ll v2; cin >> v2; v2 -= 1; V[i] = v2;
  }
  // @End [shGBSE7u]

  if (K % 2 == 1) {
    cout << "No\n";
    return 0;
  }

  /*
  unordered_map<ll, unordered_map<ll, ll>> mp;
  REP(i, 0, N) REP(j, 0, N) mp[U[i]][V[i]] = i;
  */
  
  vector<vector<pll>> nbr(N);
  REP(i, 0, M) {
    nbr[U[i]].emplace_back(V[i], i);
    nbr[V[i]].emplace_back(U[i], i);
  }

  vector<ll> ans;
  vector<bool> visited(N, false);
  ll rem = K;
  
  auto func = [&](auto rF, ll nd) -> bool {
    bool status = false;
    visited[nd] = true;
    for (auto [peer, idx] : nbr[nd]) {
      if (visited[peer]) continue;
      auto cv = rF(rF, peer);
      if (rem == 0) return status;
      if (not cv) {
        ans.push_back(idx);
        if (not status) rem -= 2;
        status = not status;
      }
      if (rem == 0) return status;
    }
    return status;
  };

  REP(nd, 0, N) {
    if (not visited[nd]) {
      func(func, nd);
      if (rem == 0) {
        cout << "Yes\n";
        cout << ssize(ans) << "\n";
        REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}

