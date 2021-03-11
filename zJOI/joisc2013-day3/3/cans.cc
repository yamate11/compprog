#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int Measure(int RM, int CM);
void Pinpoint(int RP, int CP);


void sub (int TR, int TC, int BR, int BC, int DR, int DC, int X) {
  auto myMeasure = [&](int r, int c) -> int {
    int t = Measure(r, c);
    if (X == t) Pinpoint(r, c);
    return t;
  };

  int Rmin = min(TR, BR), Rmax = max(TR, BR);
  int Cmin = min(TC, BC), Cmax = max(TC, BC);
  int r = TR;
  int c = BC;
  while (true) {
    if (r < Rmin || c < Cmin || r > Rmax || c > Cmax) return;
    ll t = myMeasure(r, c);
    if (X > t) c -= DC;
    else if (X < t) r += DR;
  }
}

void Rescue(int R, int C, int MR, int MC, int X) {
  sub(MR, MC, 1, 1, -1, -1, X);
  if (MR + 1 <= R) sub(MR + 1, MC, R, 1, 1, -1, X);
  if (MC + 1 <= C) sub(MR, MC + 1, 1, C, -1, 1, X);
  if (MR + 1 <= R && MC + 1 <= C) sub(MR + 1, MC + 1, R, C, 1, 1, X);
}

