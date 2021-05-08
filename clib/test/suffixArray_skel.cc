#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(suffixArray)


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
