#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(suffixArray)
// --> suffixArray
// ---- inserted library file suffixArray.cc

struct SuffixArray {
private:
  string str;
  vector<int> arr;  // arr.size() == str.size() + 1
  bool built_lcp;
  vector<int> lcp;  // lcp.size() == str.size()

  void init() {
    built_lcp = false;
    int N = str.size();
    arr.resize(N + 1);
    vector<int> rank(N + 1);
    copy(str.begin(), str.end(), rank.begin());
    rank.at(N) = 0;
    for (int k = 1; k < N; k *= 2) {
      iota(arr.begin(), arr.end(), 0);
      auto compare = [&](int p, int q) -> bool {
	if (p == q) return false;
	if (rank.at(p) != rank.at(q)) return rank.at(p) < rank.at(q);
	if (p + k > N) return true;
	if (q + k > N) return false;
	return rank.at(p + k) < rank.at(q + k);
      };
      sort(arr.begin(), arr.end(), compare);
      vector<int> tmp(N + 1);
      tmp.at(arr.at(0)) = 0;
      for (int i = 1; i <= N; i++) {
	int prev = arr.at(i-1);
	int cur = arr.at(i);
	tmp.at(cur) = tmp.at(prev) + (compare(prev, cur) ? 1 : 0);
      }
      rank = move(tmp);
    }
  }

public:
  SuffixArray(string s) : str(s) { init(); }

  const vector<int>& getArr() { return arr; }
  int at(int i) { return arr.at(i); }

  const vector<int>& getLcp() {
    int N = str.size();
    if (built_lcp) return lcp;
    built_lcp = true;
    lcp.resize(str.size());
    vector<int> rank(N+1);
    iota(rank.begin(), rank.end(), 0);
    sort(rank.begin(), rank.end(),
	 [&](int p, int q) -> bool { return arr.at(p) < arr.at(q); });
    int h = 0;
    for (int i = 0; i < N; i++) {
      int ri = rank.at(i);
      int j = arr.at(ri - 1);
      if (h > 0) h--;
      while (j + h < N && i + h < N && str.at(j + h) == str.at(i + h)) h++;
      assert(ri - 1 >= 0);
      lcp.at(ri - 1) = h;
    }
    return lcp;
  }

};

// ---- end suffixArray.cc
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  SuffixArray sa(S);
  for (ll i = 1; i <= (ll)S.size(); i++) {
    if (i > 1) cout << " ";
    cout << sa.at(i);
  }
  cout << endl;

}
