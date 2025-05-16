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

struct Node {
  Node* parent;
  Node* left;
  Node* right;
  ll val;
  Node(Node* parent_) : parent(parent_), left(nullptr), right(nullptr), val(-1LL) {};
};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A, dec=1) [htY873nY]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [htY873nY]

  map<ll, Node*> mp;
  Node* root = new Node(nullptr);
  Node* left1 = new Node(root);
  Node* right1 = new Node(root);
  root->left = left1;
  root->right = right1;
  root->val = A[0];
  mp[A[0]] = left1;
  mp[N] = right1;
  REP(i, 1, N) {
    auto it = mp.lower_bound(A[i]);
    Node* ptr = it->second;
    ptr->val = A[i];
    ptr->left = new Node(ptr);
    ptr->right = new Node(ptr);
    it->second = ptr->right;
    mp[A[i]] = ptr->left;
  }
  vector<ll> B(N);
  vector<ll> C(N);
  auto dfs = [&](auto rF, Node* ptr, ll dp) -> ll {
    ll i = ptr->val;
    if (i < 0) return 0;
    B[i] = dp;
    ll dec = 1;
    dec += rF(rF, ptr->left, dp + 1);
    dec += rF(rF, ptr->right, dp + 1);
    C[i] = dec;
    return dec;
  };
  dfs(dfs, root, 0);
  vector<ll> BB(N), CC(N);
  REP(i, 0, N) BB[i] = B[A[i]];
  REP(i, 0, N) CC[i] = C[A[i]];
  REPOUT(i, 0, N, BB[i], " ");
  REPOUT(i, 0, N, CC[i] - 1, " ");

  return 0;
}

