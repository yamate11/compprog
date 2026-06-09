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

// @@ !! LIM(rle f:updMaxMin)

// ---- inserted library file rle.cc

template<class InputIt, class OutputIt>
OutputIt rle_iter(InputIt first, InputIt last, OutputIt d_first) {
  InputIt itA = first;
  OutputIt oit = d_first;
  while (itA != last) {
    InputIt itB = next(itA);
    for (; itB != last and *itA == *itB; itB++);
    *oit = make_pair(*itA, itB - itA);
    itA = itB;
    oit++;
  }
  return oit;
}

template<class V>
auto rle(V vec) {
  vector<pair<typename V::value_type, ll>> ret;
  rle_iter(vec.begin(), vec.end(), back_inserter(ret));
  return ret;
}

// ---- end rle.cc

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll big = 2e12;

  auto solve = [&]() -> void {
    ll N, K; cin >> N >> K;
    vector<ll> SN(N + 2);
    {
      string S; cin >> S;
      REP(i, 0, N) SN[i + 1] = S[i] - '0';
    }
    SN[0] = 1; SN[N + 1] = 1;
    vector<ll> A(N + 2, 0LL);
    REP(i, 0, N) {
      ll a; cin >> a;
      A[i + 1] = a;
    }

    N += 2;

    vector<ll> B(N + 1, 0LL);
    REP(i, 0, N) B[i + 1] = B[i] + A[i];
    
    auto enc = rle(SN);
    vector<ll> pos0;
    vector<ll> pos1;
    vector<ll> len0;
    vector<ll> len1;
    {
      ll idx = 0;
      for (auto [val, len] : enc) {
        if (val == 0) {
          pos0.push_back(idx);
          len0.push_back(len);
        }else {
          pos1.push_back(idx);
          len1.push_back(len);
        }
        idx += len;
      }
    }
    ll num1 = ssize(pos1);
    ll num0 = ssize(pos0);
    vector samax(num1, 0LL);
    ll maxsam = -big;
    REP(i, 0, num1) {
      ll lo = pos1[i];
      ll hi = lo + len1[i];
      ll vmin = B[lo];
      ll sam = 0;
      REP(j, lo, hi) {
        ll val = B[j + 1] - vmin;
        updMax(sam, val);
        updMin(vmin, B[j + 1]);
      }
      samax[i] = sam;
      updMax(maxsam, sam);
    }
    auto ans = A;
    if (num0 == 0) {
      if (maxsam != K) {
        cout << "No\n";
        return;
      }
    }else {
      if (maxsam > K) {
        cout << "No\n";
        return ;
      }
      if (maxsam == K) {
        REP(i, 0, num0) {
          REP(j, pos0[i], pos0[i] + len0[i]) A[j] = -big;
        }
      }else {
        REP(i, 1, num0) {
          REP(j, pos0[i], pos0[i] + len0[i]) A[j] = -big;
        }
        ll y0 = 0;
        ll w = 0;
        REPrev(i, len1[0] - 1, 0) {
          w += A[i];
          updMax(y0, w);
        }
        ll y1 = 0;
        w = 0;
        REP(i, pos1[1], pos1[1] + len1[1]) {
          w += A[i];
          updMax(y1, w);
        }
        ll z = K - (y0 + y1);
        A[pos0[0]] = z;
      }
    }
    cout << "Yes\n";
    REPOUT(i, 1, N - 1, A[i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

