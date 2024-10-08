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

// @@ !! LIM(f:intDiv cmpNaive sqrtDecomp)

// ---- inserted function f:intDiv from util.cc
// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}
//   Just a note.  For d \in Z and t \in R,
//       d < t <=> d < ceil(t),     d <= t <=> d <= floor(t),
//       d > t <=> d > floor(t),    d >= t <=> d >= ceil(t).

// ---- end f:intDiv

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

// ---- inserted library file sqrtDecomp.cc

template<typename B>
struct SRD { // square root decomposition
  int tot_size;  // total number of elements
  int bsize;  // block size
  int numb;  // number of blocks
  vector<B> _data;
  SRD() : tot_size(0), bsize(0), numb(0), _data(0) {}
  SRD(int tot_size_, int bsize_ = 0) : tot_size(tot_size_) {
    if (bsize_ > 0) bsize = bsize_;
    else            bsize = lround(sqrt(tot_size));
    numb = (tot_size + bsize - 1) / bsize;
    _data = vector<B>(numb);
  }
  pair<int, int> idx2pos(int x) { return {x / bsize, x % bsize}; }
  int pos2idx(int p, int r) { return p * bsize + r; }
  tuple<int, int, int, int, int, int> range_pos(int lo, int hi) {
    auto [lo_p, lo_r] = idx2pos(lo);
    auto [hi_p, hi_r] = idx2pos(hi - 1);
    if (lo_p == hi_p) return {lo_p, lo_r, hi_r + 1, hi_p, 0, 0};
    else              return {lo_p, lo_r, bsize,    hi_p, 0, hi_r + 1};
  }
  B& data(int i) { return _data[i]; }
  int block_size(int i) {
    if (i < numb - 1) return bsize;
    else return tot_size - (numb - 1) * bsize;
  }
  /*
  void exec_general(int lo, int hi, auto f_edge, auto f_body) {
    auto [b_f, lo_f, hi_f, b_l, lo_l, hi_l] = range_pos(lo, hi);
    f_edge(b_f, lo_f, hi_f);
    if (b_f + 1 < b_l) f_body(b_f + 1, b_l);
    if (b_f < b_l) f_edge(b_l, lo_l, hi_l);
  }
  void exec(int lo, int hi, auto inloop_edge, auto inloop_body) {
    auto f_edge = [&](int b, int lo_b, int hi_b) {
      for (int i = lo_b; i < hi_b; i++) inloop_edge(b, data(b), i, pos2idx(b, i));
    };
    auto f_body = [&](int b0, int b1) {
      for (int b = b0; b < b1; b++) inloop_body(b, data(b));
    };
    exec_general(lo, hi, f_edge, f_body);
  }
  */
  template<typename F0e = nullptr_t, typename F0c = nullptr_t, typename F1e = nullptr_t, typename F1c = nullptr_t>
  void exec(int lo, int hi, auto edge_body, auto core_body,
            F0e edge_pre = nullptr, F0c core_pre = nullptr, F1e edge_post = nullptr, F1c core_post = nullptr) {
    auto do_edge = [&](int b, int lo_e, int hi_e) -> void {
      if constexpr (not is_same_v<F0e, nullptr_t>) { edge_pre(b, data(b)); }
      if constexpr (not is_same_v<decltype(edge_body), nullptr_t>) {
        for (int i = lo_e; i < hi_e; i++) { edge_body(b, data(b), i, pos2idx(b, i)); }
      }
      if constexpr (not is_same_v<F1e, nullptr_t>) { edge_post(b, data(b)); }
    };

    auto [b_f, lo_f, hi_f, b_l, lo_l, hi_l] = range_pos(lo, hi);
    do_edge(b_f, lo_f, hi_f);
    if (b_f + 1 < b_l) {
      if constexpr (not is_same_v<F0c, nullptr_t>) { core_pre(); }
      if constexpr (not is_same_v<decltype(core_body), nullptr_t>) {
        for (int b = b_f + 1; b < b_l; b++) { core_body(b, data(b)); }
      }
      if constexpr (not is_same_v<F1c, nullptr_t>) { core_post(); }
    }
    if (b_f < b_l) do_edge(b_l, lo_l, hi_l);
  }


};


// ---- end sqrtDecomp.cc

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A) [3hhQNcCT]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [3hhQNcCT]
  
  REP(_q, 0, Q) {
    ll C, L, R; cin >> C >> L >> R; L--;
    if (C == 1) {
      sort(A.begin() + L, A.begin() + R);
    }else if (C == 2) {
      sort(A.begin() + L, A.begin() + R, greater<ll>());
    }else if (C == 3) {
      ll s = 0;
      REP(i, L, R) s += A[i];
      cout << s << endl;
    }
  }

  return 0;
}

enum mymode_t { INDIV, ASC, DESC };

ll a_lim = 11;

struct block_t {
  mymode_t mode;
  vector<int> cnt;
  block_t() : mode(INDIV), cnt(a_lim) {}
};

int body(istream& cin, ostream& cout) {

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A) [3hhQNcCT]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [3hhQNcCT]

  SRD<block_t> srd(N);

  REP(idx, 0, N) {
    auto [b, i] = srd.idx2pos(idx);
    srd.data(b).cnt[A[idx]]++;
  }

  auto indiv = [&](int b, block_t& block) -> void {
    if (block.mode == INDIV) return;
    ll j = 0;
    REP(dd, 0, a_lim) {
      ll d = (block.mode == ASC) ? dd : a_lim - 1 - dd;
      REP(k, 0, block.cnt[d]) A[srd.pos2idx(b, j++)] = d;
    }
    block.mode = INDIV;
  };

  auto mysort = [&](ll L, ll R, bool desc) -> void {
    vector vec(a_lim, 0LL);
    auto fe1 = [&](ll b, block_t& block, ll i, ll idx) { vec[A[idx]]++; };
    auto fb1 = [&](ll b, block_t& block) { REP(d, 0, a_lim) vec[d] += block.cnt[d]; };
    srd.exec(L, R, fe1, fb1, indiv);

    ll cur_d = desc ? a_lim - 1 : 0;
    ll step = desc ? -1 : +1;

    auto fe2 = [&](ll b, block_t& block, ll i, ll idx) {
      while (vec[cur_d] == 0) cur_d += step;
      ll old_val = A[idx];
      A[idx] = cur_d;
      block.cnt[old_val]--;
      block.cnt[cur_d]++;
      vec[cur_d]--;
    };
    auto fb2 = [&](ll b, block_t& block) {
      block.mode = desc ? DESC : ASC;
      REP(dd, 0, a_lim) block.cnt[dd] = 0;
      ll rem = srd.block_size(b);
      while (true) {
        ll y = min(rem, vec[cur_d]);
        block.cnt[cur_d] = y;
        vec[cur_d] -= y;
        rem -= y;
        if (rem == 0) break;
        cur_d += step;
      }
    };
    srd.exec(L, R, fe2, fb2);
  };


  REP(_q, 0, Q) {
    ll C, L, R; cin >> C >> L >> R; L--;
    if (C == 1) {  
      mysort(L, R, false);
    }else if (C == 2) {
      mysort(L, R, true);
    }else if (C == 3) {
      ll ans = 0;
      auto fe = [&](ll b, block_t& block, ll i, ll idx) { ans += A[idx]; };
      auto fb = [&](ll b, block_t& block) { REP(d, 0, a_lim) ans += d * block.cnt[d]; };
      srd.exec(L, R, fe, fb, indiv);
      cout << ans << "\n";
    }
  }

  return 0;
}

