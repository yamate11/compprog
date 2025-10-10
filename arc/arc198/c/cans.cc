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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [yyyNvnMK]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [yyyNvnMK]
  // @InpVec(N, B) [f6TAwPH9]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [f6TAwPH9]

  ll totA = accumulate(ALL(A), 0LL);
  ll totB = accumulate(ALL(B), 0LL);
  if (totA != totB) {
    cout << "No\n";
    return 0;
  }
  if (N == 2) {
    if (A[0] == B[0]) {
      cout << "Yes\n0\n";
      return 0;
    }else if (B[0] == A[1] - 1) {
      cout << "Yes\n1\n1 2\n";
      return 0;
    }
  }

  vector<pll> ans;
  auto op = [&](ll i, ll j) -> void {
    assert(i < j);
    ans.emplace_back(i, j);
    swap(A[i], A[j]);
    A[i]--;
    A[j]++;
  };
  auto swap01 = [&]() -> void {
    op(1, 2); op(0, 2); op(1, 2);
  };
  auto swap12 = [&]() -> void {
    op(0, 1); op(0, 2); op(0, 1);
  };
  auto swap02 = [&]() -> void {
    swap01(); swap12(); swap01();
  };
  REPrev(i, N - 1, 3) {
    while (A[i] < B[i]) {
      ll i0;
      if (A[i] + (i + 1 - 2) <= B[i]) i0 = 0;
      else i0 = A[i] + (i + 1 - 2) - B[i];
      op(i0, i);
      REP(j, i0, i) op(j, j + 1);
    }
    while (A[i] > B[i]) {
      ll i0;
      if (B[i] + (i + 1 - 2) <= A[i]) i0 = 0;
      else i0 = B[i] + (i + 1 - 2) - A[i];
      REPrev(j, i - 1, i0) op(j, j + 1);
      op(i0, i);
    }
  }
  if (A[0] < B[1]) {
    while (A[0] < B[1]) {
      op(0, 1); op(1, 2); op(0, 2);
    }
    swap01();
  }else if (A[0] > B[1]) {
    swap02();
    while (A[2] > B[1]) {
      op(1, 2); op(0, 1); op(0, 2);
    }
    swap12();
  }
  if (A[0] < B[0]) {
    while (A[0] < B[0]) {
      op(0, 1); op(1, 2); op(0, 2); swap12();
    }
  }else {
    swap02();
    while (A[2] > B[0]) {
      op(1, 2); op(0, 1); op(0, 2); swap01();
    }
    swap02();
  }



  cout << "Yes\n";
  cout << ssize(ans) << "\n";
  for (auto [i, j] : ans) {
    cout << i + 1 << " " << j + 1 << "\n";
  }
  return 0;
}

