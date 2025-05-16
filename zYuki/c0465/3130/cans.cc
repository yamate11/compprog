// #include <bits/stdc++.h>
// #include <cassert>
// using namespace std;
// using ll = long long int;
// using u64 = unsigned long long;
// using pll = pair<ll, ll>;
// // #include <atcoder/all>
// // using namespace atcoder;
// #define REP(i, a, b) for (ll i = (a); i < (b); i++)
// #define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
// #define ALL(coll) (coll).begin(), (coll).end()
// #define SIZE(v) ((ll)((v).size()))
// #define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// // @@ !! LIM(binsearch cmpNaive)

// // ---- inserted library file binsearch.cc

// template <typename T>
// requires integral<T>
// T binsearch(auto check, T yes, T no) {
//   while (abs(no - yes) > 1) {
//     T mid = yes + (no - yes) / 2;  // avoiding unnecessary overflow
//     if (check(mid)) yes = mid;
//     else            no  = mid;
//   }
//   return yes;
// }

// template <typename T>
// requires floating_point<T>
// T binsearch(auto check, T yes, T no, T err, const bool abs_only = false) {
//   T rep_in_t = ceil(log(abs(yes - no) / err) / log(2.0));
//   constexpr int lim = INT_MAX - 10;
//   int rep = rep_in_t > (T)lim ? lim : llround(rep_in_t) + 1;
//   for (int r = 0; r < rep; r++) {
//     T mid = (yes + no) / 2.0;
//     if (not abs_only) {
//       if (abs(yes - mid) < err * min(abs(mid), abs(yes))) return mid;
//     }
//     if (check(mid)) yes = mid;
//     else            no  = mid;
//   }
//   return yes;
// }

// // ---- end binsearch.cc

// // ---- inserted library file cmpNaive.cc

// const string end_mark("^__=end=__^");

// int naive(istream& cin, ostream& cout);
// int body(istream& cin, ostream& cout);

// void cmpNaive() {
//   while (true) {
//     string s;
//     getline(cin, s);
//     bool run_body;
//     if (s.at(0) == 'Q') {
//       return;
//     }else if (s.at(0) == 'B') {
//       run_body = true;
//     }else if (s.at(0) == 'N') {
//       run_body = false;
//     }else {
//       cerr << "Unknown body/naive specifier.\n";
//       exit(1);
//     }
//     string input_s;
//     while (true) {
//       getline(cin, s);
//       if (s == end_mark) break;
//       input_s += s;
//       input_s += "\n";
//     }
//     stringstream ss_in(move(input_s));
//     stringstream ss_out;
//     ss_out << setprecision(20);
//     if (run_body) {
//       body(ss_in, ss_out);
//     }else {
//       naive(ss_in, ss_out);
//     }
//     cout << ss_out.str() << end_mark << endl;
//   }
// }

// int main(int argc, char *argv[]) {
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout << setprecision(20);

// #if CMPNAIVE
//   if (argc == 2) {
//     if (strcmp(argv[1], "cmpNaive") == 0) {
//       cmpNaive();
//     }else if (strcmp(argv[1], "naive") == 0) {
//       naive(cin, cout);
//     }else if (strcmp(argv[1], "skip") == 0) {
//       exit(0);
//     }else {
//       cerr << "Unknown argument.\n";
//       exit(1);
//     }
//   }else {
// #endif
//     body(cin, cout);
// #if CMPNAIVE
//   }
// #endif
//   return 0;
// }

// /*
// */

// // ---- end cmpNaive.cc

// // @@ !! LIM -- end mark --

// int naive(istream& cin, ostream& cout) {
//   ll N; cin >> N;
//   // @InpVec(N, A) [7Zq19OHl]
//   auto A = vector(N, ll());
//   for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
//   // @End [7Zq19OHl]
//   // @InpVec(N, S, type=string) [4nUiuvuQ]
//   auto S = vector(N, string());
//   for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
//   // @End [4nUiuvuQ]

//   ll x0 = 0;
  
//   auto check = [&](ll a) -> bool {
//     auto f_akane = [&](auto r_akane, auto r_aoi, ll x, const auto& v_akane, const auto& v_aoi) -> bool {
//       bool found = false;
//       REP(i, 0, N) {
//         if (v_akane[i]) {
//           found = true;
//           auto w_akane = v_akane;
//           w_akane[i] = false;
//           if (not r_aoi(r_akane, r_aoi, x, A[i], w_akane, v_aoi)) return true;
//         }
//       }
//       if (found) return false;
//       return x >= a;
//     };

//     auto f_aoi = [&](auto r_akane, auto r_aoi, ll x, ll vala, const auto& v_akane, const auto& v_aoi) -> bool {
//       REP(i, 0, N) {
//         if (v_aoi[i]) {
//           auto w_aoi = v_aoi;
//           w_aoi[i] = false;
//           ll new_x;
//           if (S[i] == "add") new_x = x + vala;
//           else if (S[i] == "min") new_x = min(x, vala);
//           else if (S[i] == "max") new_x = max(x, vala);
//           else assert(0);
//           if (not r_akane(r_akane, r_aoi, new_x, v_akane, w_aoi)) return true;
//         }
//       }
//       return false;
//     };

//     vector<bool> v_akane(N, true);
//     vector<bool> v_aoi(N, true);
//     return f_akane(f_akane, f_aoi, x0, v_akane, v_aoi);
//   };

//   ll a = binsearch<ll>(check, 0, (ll)1e18);
//   cout << a << endl;

//   return 0;
// }
// int body(istream& cin, ostream& cout) {

//   ll N; cin >> N;
//   // @InpVec(N, A) [7Zq19OHl]
//   auto A = vector(N, ll());
//   for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
//   // @End [7Zq19OHl]
//   // @InpVec(N, S, type=string) [4nUiuvuQ]
//   auto S = vector(N, string());
//   for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
//   // @End [4nUiuvuQ]

//   ll n_add = 0, n_min = 0, n_max = 0;
//   REP(i, 0, N) {
//     if (S[i] == "add") n_add++;
//     else if (S[i] == "min") n_min++;
//     else if (S[i] == "max") n_max++;
//     else assert(0);
//   }
//   sort(ALL(A));
//   ll ans = 0;
//   if (n_add == 0) {
//     if (n_max == 0) {
//       ans = 0;
//     }else {
//       ans = A[N - 1 - n_min];
//     }
//   }else {
//     ans = A[N - 1 - n_min];
//     REP(i, 0, n_add - 1) ans += A[i];
//   }
//   if (n_min >= 1) {
//     ans = min(ans, A[N - n_min]);
//   }
//   cout << ans << endl;

//   return 0;
// }

