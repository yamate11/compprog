#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  *NOTE* This implementation is slow O(N(logN)^2).
         Use ac-library O(N) instead.

  Suffix Array

    SuffixArray sa("abcabc");         // let N = "abcabc".size()
    const auto& arr = sa.arr;         // vector<int>, size N+1
    const auto& rank = sa.rank;       // vector<int>, size N+1
    const auto& lcp = sa.getLcp();    // vector<int>, size N

  string:
    0123456
    abcabc    

  sorted suffixes

    i  arr[i]  str[arr[i]:]  lcp[i]
    0  6       (empty)       0
    1  3       abc           3
    2  0       abcabc        0
    3  4       bc            2
    4  1       bcabc         0
    5  5       c             1
    6  2       cabc          ---

    arr  ==> [6, 3, 0, 4, 1, 5, 2]
    rank ==> [2, 4, 6, 1, 3, 5, 0]
         arr[rank[i]] = i,  rank[arr[x]] = x
         str[i:] < str[j:] <=> rank[i] < rank[j]

    lcp[i] is the length of common prefix of str[arr[i]:] and str[arr[i+1]:]

    Note: for i < j, the length of common prefix of str[arr[i]:] and
          str[arr[j]:] is min { lcp[i], ..., lcp[j-1] }
 */


// @@ !! LIM()


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- suffixArray.cc

struct SuffixArray {
private:
  string str;

  /* arr and rank is automatically built, but lcp is not.
     Therefore, we make lcp private so that the user does not accidentally
     access unbuilt empty vector.
   */
  vector<int> lcp;  // lcp.size() == str.size()
  bool lcp_built;

public:
  vector<int> arr;  // arr.size() == str.size() + 1
  vector<int> rank; // rank.size() == str.size() + 1

  void init(string s) {
    str = s;
    lcp_built = false;
    int N = str.size();
    arr.resize(N + 1);
    rank.resize(N + 1);
    if (N == 0) return;
    if (N == 1) {
      arr.at(0) = rank.at(0) = 1;
      return;
    }
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

  SuffixArray(string s) { init(s); }

  int at(int i) { return arr.at(i); }

  const vector<int>& getLcp() {
    if (lcp_built) return lcp;
    lcp_built = true;
    int N = str.size();
    lcp.resize(N);
    if (N <= 1)  return lcp;
    int h = 0;
    for (int i = 0; i < N; i++) {
      int ri = rank.at(i);
      assert(ri - 1 >= 0);
      int j = arr.at(ri - 1);
      if (h > 0) h--;
      while (j + h < N && i + h < N && str.at(j + h) == str.at(i + h)) h++;
      lcp.at(ri - 1) = h;
    }
    return lcp;
  }

};

// @@ !! END ---- suffixArray.cc

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  
  string str01 = "abracadabra";
  SuffixArray sa01(str01);
  const auto& arr01 = sa01.arr;
  assert(arr01 == vector<int>({11,10,7,0,3,5,8,1,4,6,9,2}));
  assert(sa01.at(0) == 11 && sa01.at(1) == 10 && sa01.at(11) == 2);
  assert(str01.substr(sa01.at(1)) == "a");
  assert(str01.substr(sa01.at(6)) == "bra");
  assert(sa01.getLcp() == vector<int>({0,1,4,1,1,0,3,0,0,0,2}));

  SuffixArray sa02("cat");
  assert(sa02.arr == vector<int>({3,1,0,2}));
  assert(sa02.getLcp() == vector<int>({0,0,0}));

  SuffixArray sa03("ccat");
  assert(sa03.arr == vector<int>({4,2,1,0,3}));
  assert(sa03.getLcp() == vector<int>({0,0,1,0}));

  SuffixArray sa04("catcat");
  assert(sa04.arr == vector<int>({6,4,1,3,0,5,2}));
  assert(sa04.getLcp() == vector<int>({0,2,0,3,0,1}));
  
  SuffixArray sa05("a");
  assert(sa05.arr == vector<int>({1,0}));
  assert(sa05.getLcp() == vector<int>({0}));
	 
  SuffixArray sa06("");
  assert(sa06.arr == vector<int>({0}));
  assert(sa06.getLcp() == vector<int>());
	 

  cout << "Test done." << endl;

}
