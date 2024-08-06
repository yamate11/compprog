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

// @@ !! LIM(f:intDiv cmpNaive)

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

// @@ !! LIM -- end mark --

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
  void exec_general(int lo, int hi, auto f_edge, auto f_body) {
    auto [b_f, lo_f, hi_f, b_l, lo_l, hi_l] = range_pos(lo, hi);
    f_edge(b_f, lo_f, hi_f);
    if (b_f + 1 < b_l) f_body(b_f + 1, b_l);
    if (b_f < b_l) f_edge(b_l, lo_l, hi_l);
  }
  void exec(int lo, int hi, auto inloop_edge, auto inloop_body) {
    auto f_edge = [&](int b, int lo_b, int hi_b) { for (int i = lo_b; i < hi_b; i++) inloop_edge(b, i); };
    auto f_body = [&](int b0, int b1) { for (int b = b0; b < b1; b++) inloop_body(b); };
    exec_general(lo, hi, f_edge, f_body);
  }

};

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

  auto srd = SRD<block_t>(N);
  REP(i, 0, srd.numb) {
    auto& block = srd.data(i);
    block.mode = INDIV;
    REP(j, 0, srd.block_size(i)) block.cnt[A[srd.pos2idx(i, j)]]++;
  }

  auto indiv = [&](ll i) -> void {
    auto& block = srd.data(i);
    if (block.mode == INDIV) return;
    ll j = 0;
    REP(dd, 0, a_lim) {
      ll d = (block.mode == ASC) ? dd : a_lim - 1 - dd;
      REP(k, 0, block.cnt[d]) A[srd.pos2idx(i, j++)] = d;
    }
    block.mode = INDIV;
  };

  REP(_q, 0, Q) {
    ll C, L, R; cin >> C >> L >> R; L--;
    auto [b0, _x, _y, b1, _z, _w] = srd.range_pos(L, R);
    indiv(b0);
    if (b0 < b1) indiv(b1);

    auto mysort = [&](bool desc) -> void {
      vector vec(a_lim, 0LL);
      auto fe1 = [&](ll b, ll i) { vec[A[srd.pos2idx(b, i)]]++; };
      auto fb1 = [&](ll b) { REP(d, 0, a_lim) vec[d] += srd.data(b).cnt[d]; };
      srd.exec(L, R, fe1, fb1);

      ll cur_d = desc ? a_lim - 1 : 0;
      ll step = desc ? -1 : +1;

      auto fe2 = [&](ll b, ll i) {
        auto& block = srd.data(b);
        while (vec[cur_d] == 0) cur_d += step;
        ll j = srd.pos2idx(b, i);
        ll old_val = A[j];
        A[j] = cur_d;
        block.cnt[old_val]--;
        block.cnt[cur_d]++;
        vec[cur_d]--;
      };
      auto fb2 = [&](ll b) {
        auto& block = srd.data(b);
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

    if (C == 1) {  
      mysort(false);
    }else if (C == 2) {
      mysort(true);
    }else if (C == 3) {
      ll ans = 0;
      auto fe = [&](ll b, ll i) { ans += A[srd.pos2idx(b, i)]; };
      auto fb = [&](ll b) { REP(d, 0, a_lim) ans += d * srd.data(b).cnt[d]; };
      srd.exec(L, R, fe, fb);
      cout << ans << "\n";
    }
  }

  return 0;
}

