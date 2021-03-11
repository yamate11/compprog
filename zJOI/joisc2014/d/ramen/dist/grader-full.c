#include <stdio.h>
#include <stdlib.h>

void Ramen(int);

#define MAX_N 400

static int N, input_type, R[MAX_N], compare_count;
static int min_possibility[MAX_N], max_possibility[MAX_N];
static int min_possible_count, max_possible_count;
static int max_fresh;

static void correct(){
  printf("Accepted\n");
  exit(0);
}

static void wrong(int message){
  printf("Wrong Answer [%d]\n", message);
  exit(message);
}

static int compare_internal(int X, int Y) {
  if(R[X] > R[Y]) return 1;
  if(R[X] < R[Y]) return -1;
  if(X > Y) return 1;
  if(X < Y) return -1;
  return 0;
}

int Compare(int X, int Y) {
  int c;
  if(X < 0 || N <= X || Y < 0 || N <= Y || X == Y) {
    wrong(1);
  }
  ++compare_count;
  if(compare_count > 600) {
    wrong(2);
  }
  c = compare_internal(X, Y);
  if(input_type == 2) {
    int count1 = min_possibility[X] + max_possibility[Y];
    int count2 = min_possibility[Y] + max_possibility[X];
    if(c > 0 && count1 == 2 && count2 < 2) {
      R[Y] = ++max_fresh;
      c = compare_internal(X, Y);
    }
    if(c < 0 && count1 < 2 && count2 == 2) {
      R[X] = ++max_fresh;
      c = compare_internal(X, Y);
    }
  }
  if(c > 0) {
    min_possible_count -= min_possibility[X];
    max_possible_count -= max_possibility[Y];
    min_possibility[X] = 0;
    max_possibility[Y] = 0;
  }
  if(c < 0) {
    min_possible_count -= min_possibility[Y];
    max_possible_count -= max_possibility[X];
    min_possibility[Y] = 0;
    max_possibility[X] = 0;
  }
  return c;
}

void Answer(int X, int Y) {
  if(X < 0 || N <= X || Y < 0 || N <= Y) {
    wrong(4);
  }
  if(min_possible_count > 1 || max_possible_count > 1) {
    wrong(5);
  }
  if(min_possibility[X] && max_possibility[Y]) {
    correct();
  }
  wrong(5);
}

int main() {
  int i;
  if(scanf("%d%d", &N, &input_type) < 2) {
    fprintf(stderr, "error: cannot read N and input_type.\n");
    exit(1);
  }
  if(N <= 0 || MAX_N < N) {
    fprintf(stderr, "error: N is out of bounds.\n");
    exit(1);
  }
  if(input_type == 1 || input_type == 2) {
    for(i = 0; i < N; ++i) {
      if(scanf("%d", &R[i]) < 1) {
        fprintf(stderr, "error: cannot read R[%d].\n", i);
      }
    }
    max_possible_count = N;
    min_possible_count = N;
    max_fresh = R[0];
    for(i = 0; i < N; ++i) {
      min_possibility[i] = 1;
      max_possibility[i] = 1;
      if(max_fresh < R[i]) {
        max_fresh = R[i];
      }
    }
  } else {
    fprintf(stderr, "error: input_type is not 1 nor 2.\n");
    exit(1);
  }
  compare_count = 0;
  Ramen(N);
  wrong(3);
  return 1;
}
