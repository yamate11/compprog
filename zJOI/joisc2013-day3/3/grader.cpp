#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "grader.h"

#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


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

static int R, C, RS, CS, X, altitude[200][200], call_count;

// void Rescue(int R, int C, int RS, int CS, int X);

int main(int argc, char **argv) {
  FILE *in, *out;
  int result, i, j;

  if(argc == 1) {
    in = stdin;
    out = stdout;
  } else if(argc == 3) {
    in = fopen(argv[1], "r");
    if(!in) {
      fprintf(stderr,
          "mountain grader: error opening input file %s: %s\n",
          argv[1], strerror(errno));
    }

    out = fopen(argv[2], "w");
    if(!out) {
      fprintf(stderr,
          "mountain grader: error opening output file %s: %s\n",
          argv[2], strerror(errno));
    }
  } else {
    fprintf(stderr, "usage: %s [<input> <output>]\n", argv[0]);
    exit(1);
  }

  result = fscanf(in, "%d", &R);
  if(result < 1) {
    fprintf(stderr, "mountain grader: error reading R\n");
    exit(1);
  }

  result = fscanf(in, "%d", &C);
  if(result < 1) {
    fprintf(stderr, "mountain grader: error reading C\n");
    exit(1);
  }

  result = fscanf(in, "%d", &RS);
  if(result < 1) {
    fprintf(stderr, "mountain grader: error reading RS\n");
    exit(1);
  }

  result = fscanf(in, "%d", &CS);
  if(result < 1) {
    fprintf(stderr, "mountain grader: error reading CS\n");
    exit(1);
  }

  result = fscanf(in, "%d", &X);
  if(result < 1) {
    fprintf(stderr, "mountain grader: error reading X\n");
    exit(1);
  }

  for(i = 0; i < R; ++i) {
    for(j = 0; j < C; ++j) {
      result = fscanf(in, "%d", &altitude[i][j]);
      if(result < 1) {
        fprintf(stderr, "mountain grader: error reading altitude[%d][%d]\n",
            i+1, j+1);
        exit(1);
      }
    }
  }

  fclose(in);

  call_count = 0;

  Rescue(R, C, RS, CS, X);

  printf("Wrong Answer [5]\n");

  return 5;
}

int Measure(int RM, int CM) {
  if(RM <= 0 || RM > R || CM <= 0 || CM > C) {
    printf("Wrong Answer [1]\n");
    exit(1);
  }
  if(call_count >= 1000) {
    printf("Wrong Answer [2]\n");
    exit(2);
  }
  ++call_count;
  return altitude[RM-1][CM-1];
}

void Pinpoint(int RP, int CP) {
  if(RP <= 0 || RP > R || CP <= 0 || CP > C) {
    printf("Wrong Answer [3]\n");
    exit(3);
  } else if(altitude[RP-1][CP-1] != X) {
    printf("Wrong Answer [4]\n");
    exit(4);
  } else {
    printf("Accepted\n");
    exit(0);
  }
}
