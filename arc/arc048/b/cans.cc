#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int rMax = 100000;
  vector<int> rate(rMax), cumR(rMax+1);
  vector<vector<int>> hand(rMax, vector<int>(3));
  int N; cin >> N;
  vector<int> pRate(N), pHand(N);
  for (int i = 0; i < N; i++) {
    int r, h; cin >> r >> h; r--; h--;
    pRate.at(i) = r;
    pHand.at(i) = h;
    rate.at(r)++;
    hand.at(r).at(h)++;
  }
  for (int i = 1; i < rMax+1; i++) cumR.at(i) = cumR.at(i-1) + rate.at(i-1);
  assert(cumR.at(rMax) == N);
  for (int i = 0; i < N; i++) {
    int r = pRate.at(i);
    int h = pHand.at(i);
    int win = cumR.at(r);
    int lose = N - cumR.at(r + 1);
    win += hand.at(r).at((h + 1) % 3);
    lose += hand.at(r).at((h + 2) % 3);
    int draw = (N - 1) - (win + lose);
    cout << win << " " << lose << " " << draw << "\n";
  }

  return 0;
}

