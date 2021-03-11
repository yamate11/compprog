#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int encode(char c) {
  return c >= 'a' ? 26 + c - 'a' : c - 'A';
}

char decode(int x) {
  return x >= 26 ? 'a' + (x - 26) : 'A' + x;
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<int> v1(52);
  vector<vector<int>> v2(52, vector<int>(52));
  vector<vector<vector<int>>>
	 v3(52, vector<vector<int>>(52, vector<int>(52))),
	 cnt(52, vector<vector<int>>(52, vector<int>(52)));

  auto func1 = [&](const string& A, int i) -> void {
    for (int j = 0; j < (int)A.size(); j++) {
      int c = encode(A.at(j));
      for (int p = 0; p < 52; p++) {
	for (int q = 0; q < 52; q++) {
	  if (v2.at(p).at(q) == i && v3.at(p).at(q).at(c) != i) {
	    v3.at(p).at(q).at(c) = i;
	    cnt.at(p).at(q).at(c)++;
	  }
	}
	if (v1.at(p) == i) v2.at(p).at(c) = i;
      }
      v1.at(c) = i;
    }
  };

  auto func2 = [&](const string& A, int i) -> void {
    int len = A.size();
    for (int j = 0; j < len; j++) {
      int p = encode(A.at(j));
      for (int k = j+1; k < len; k++) {
	int q = encode(A.at(k));
	for (int m = k+1; m < len; m++) {
	  int r = encode(A.at(m));
	  if (v3.at(p).at(q).at(r) != i) {
	    v3.at(p).at(q).at(r) = i;
	    cnt.at(p).at(q).at(r)++;
	  }
	}
      }
    }
  };

  for (int i = 1; i <= N; i++) {
    string A; cin >> A;
    /*
    if (A.size() > 52) func1(A, i);
    else               func2(A, i);
    */
    func2(A, i);
  }
  int vmax = 0;
  char buf[4]; buf[3] = 0;
  for (int p = 0; p < 52; p++) {
    for (int q = 0; q < 52; q++) {
      for (int r = 0; r < 52; r++) {
	int x = cnt.at(p).at(q).at(r);
	if (x > vmax) {
	  vmax = x;
	  buf[0] = decode(p);
	  buf[1] = decode(q);
	  buf[2] = decode(r);
	}
      }
    }
  }
  cout << string(buf) << endl;
  return 0;
}

