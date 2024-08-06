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

#if DEBUG
ll bsize = 2;
#else
ll bsize = 700;
#endif
ll a_lim = 11;

enum mymode_t { INDIV, ASC, DESC };

struct block {
  mymode_t mode;
  vector<int> A;
  ll asz;
  vector<int> cnt;
  block() : mode(INDIV), A(), cnt(a_lim) {}
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
int body(istream& cin, ostream& cout) {

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A) [3hhQNcCT]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [3hhQNcCT]

  ll numb = divCeil(N, bsize);
  vector<block> Bl(numb);
  REP(i, 0, numb) {
    Bl[i].asz = bsize;
    if (i == numb - 1) Bl[i].asz = N - bsize * i;
    Bl[i].A = vector<int>(Bl[i].asz);
    REP(j, 0, Bl[i].asz) {
      Bl[i].mode = INDIV;
      ll a = A[i * bsize + j];
      Bl[i].A[j] = a;
      Bl[i].cnt[a]++;
    }
  }
  auto divide = [&](ll a, ll b) -> tuple<ll, ll, ll, ll, ll, ll> {
    ll ap = a / bsize;
    ll ar = a % bsize;
    ll bp = (b - 1) / bsize;
    ll br = (b - 1) % bsize;
    if (ap == bp) return {ap, ar, br + 1, ap, 0, 0};
    return {ap, ar, bsize, bp, 0, br + 1};
  };

  auto indiv = [&](ll i) -> void {
    if (Bl[i].mode == INDIV) return;
    if (Bl[i].mode == ASC) {
      ll j = 0;
      REP(d, 0, a_lim) {
        REP(k, 0, Bl[i].cnt[d]) Bl[i].A[j++] = d;
      }
    }else if (Bl[i].mode == DESC) {
      ll j = Bl[i].asz - 1;
      REP(d, 0, a_lim) {
        REP(k, 0, Bl[i].cnt[d]) Bl[i].A[j--] = d;
      }
    }
    Bl[i].mode = INDIV;
  };

  REP(_q, 0, Q) {
    ll C, L, R; cin >> C >> L >> R; L--;
    auto [b0, i0, i1, b1, i2, i3] = divide(L, R);
    indiv(b0);
    if (b0 < b1) indiv(b1);
    auto& firstB = Bl[b0];
    auto& lastB = Bl[b1];

    auto mysort = [&](bool desc) -> void {
      vector vec(a_lim, 0LL);
      REP(i, i0, i1) vec[firstB.A[i]]++;
      REP(b, b0 + 1, b1) REP(d, 0, a_lim) vec[d] += Bl[b].cnt[d];
      REP(i, i2, i3) vec[lastB.A[i]]++;

      ll d = desc ? a_lim - 1 : 0;
      auto next_d = [&]() -> void {
        if (desc) d--;
        else      d++;
      };

      REP(i, i0, i1) {
        while (vec[d] == 0) next_d();
        firstB.cnt[firstB.A[i]]--;
        firstB.A[i] = d;
        firstB.cnt[d]++;
        vec[d]--;
      }
      REP(b, b0 + 1, b1) {
        Bl[b].mode = desc ? DESC : ASC;
        REP(dd, 0, a_lim) Bl[b].cnt[dd] = 0;
        ll z = Bl[b].asz;
        while (true) {
          ll y = min(z, vec[d]);
          Bl[b].cnt[d] = y;
          vec[d] -= y;
          z -= y;
          if (z == 0) break;
          next_d();
        }
      }
      REP(i, i2, i3) {
        while (vec[d] == 0) next_d();
        lastB.cnt[lastB.A[i]]--;
        lastB.A[i] = d;
        lastB.cnt[d]++;
        vec[d]--;
      }
    };

    if (C == 1) {  
      mysort(false);
    }else if (C == 2) {
      mysort(true);
    }else if (C == 3) {
      ll ans = 0;
      REP(i, i0, i1) ans += firstB.A[i];
      REP(b, b0 + 1, b1) REP(d, 0, a_lim) ans += d * Bl[b].cnt[d];
      REP(i, i2, i3) ans += lastB.A[i];
      cout << ans << "\n";
    }
  }

  return 0;
}

