#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

#include <stdio.h>

template <class T>
void bitdump(T a){
  char *x = (char*)(&a);
  int count = 0;
  int s = 8;
  int s2 = 12;
  if(sizeof(T)==16){
    s = 10;
    s2 = 16;
  }else if(sizeof(T) == 4){
    s = 4;
    s2 = 9;
  }
  for(int i=0;i<s;i++){
    for(int j=0;j<8;j++){
      if(x[s-i-1] & (1<<(7-j)))printf("1");
      else printf("0");
      count++;
      if(count==1 || count==s2)printf(" ");
    }
  }
  printf("\n");
}

int main() {
  bitdump((long double)(0));
  bitdump((long double)(1));
  bitdump((long double)(2));
  bitdump((long double)(0xf00000000000000f));
  bitdump((long double)((ll)(0xf00000000000000f)));
  bitdump((long double)(ULONG_MAX));
  return 0;
}
