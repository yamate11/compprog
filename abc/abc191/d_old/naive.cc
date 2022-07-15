#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar_unlocked(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread_unlocked(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(double &x){
  int k;
  int m=0;
  int p=0;
  double r = 1;
  x = 0;
  for(;;){
    k = my_getchar_unlocked();
    if(k=='-'){
      m = 1;
      break;
    }
    if(k=='.'){
      p = 1;
      break;
    }
    if('0'<=k&&k<='9'){
      x = k - '0';
      break;
    }
  }
  for(;;){
    k = my_getchar_unlocked();
    if(k=='.'){
      p = 1;
      continue;
    }
    if(k<'0'||k>'9'){
      break;
    }
    if(p){
      r *= 0.1;
      x += r * (k - '0');
    }
    else{
      x = x * 10 + k - '0';
    }
  }
  if(m){
    x = -x;
  }
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite_unlocked(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar_unlocked(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite_unlocked(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar_unlocked(a);
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    my_putchar_unlocked('-');
  }
  while(s--){
    my_putchar_unlocked(f[s]+'0');
  }
}
template<class T> inline T pow2_L(T a){
  return a*a;
}
template<class T, class S> T inline fDiv(T a, S b){
  T m;
  if(b < 0){
    a = -a;
    b = -b;
  }
  m = a % b;
  if(m == 0){
    return a / b;
  }
  if(m < 0){
    m += b;
  }
  return (a - m) / b;
}
template<class T, class S> T inline cDiv(T a, S b){
  T m;
  if(b < 0){
    a = -a;
    b = -b;
  }
  m = a % b;
  if(m == 0){
    return a / b;
  }
  if(m < 0){
    m += b;
  }
  return (a + b - m) / b;
}
double X;
double Y;
double R;
long long res;
int main(){
  int k;
  __int128_t x1;
  __int128_t x2;
  __int128_t x;
  __int128_t dy;
  __int128_t r;
  rd(X);
  rd(Y);
  rd(R);
  x = round(X * 10000);
  r = round(R * 10000);
  for(k=(-200000);k<(200000+1);k++){
    dy = abs(round((Y-k) * 10000));
    if(dy > r){
      continue;
    }
    __int128_t Q5VJL1cS;
    __int128_t e98WHCEY;
    __int128_t cTE1_r3A;
    Q5VJL1cS = -10000000000LL;
    e98WHCEY = x;
    while(Q5VJL1cS < e98WHCEY){
      if((Q5VJL1cS + e98WHCEY)%2==0){
        cTE1_r3A = (Q5VJL1cS + e98WHCEY) / 2;
      }
      else{
        cTE1_r3A = (Q5VJL1cS + e98WHCEY - 1) / 2;
      }
      if((pow2_L((cTE1_r3A-x)))+(pow2_L(dy))<=(pow2_L(r))){
        e98WHCEY = cTE1_r3A;
      }
      else{
        Q5VJL1cS = cTE1_r3A + 1;
      }
    }
    x1 =e98WHCEY;
    __int128_t xr20shxY;
    __int128_t WYIGIcGE;
    __int128_t t_ynMSdg;
    xr20shxY = x;
    WYIGIcGE = 10000000000LL;
    while(xr20shxY < WYIGIcGE){
      if((xr20shxY + WYIGIcGE)%2==0){
        t_ynMSdg = (xr20shxY + WYIGIcGE) / 2;
      }
      else{
        t_ynMSdg = (xr20shxY + WYIGIcGE + 1) / 2;
      }
      if((pow2_L((t_ynMSdg-x)))+(pow2_L(dy))<=(pow2_L(r))){
        xr20shxY = t_ynMSdg;
      }
      else{
        WYIGIcGE = t_ynMSdg - 1;
      }
    }
    x2 =WYIGIcGE;
    res += fDiv(x2, 10000) - cDiv(x1, 10000) + 1;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210103-1 [bug fixed 2]

// --- original code ---
// double X, Y, R;
// ll res;
// {
//   __int128_t x1, x2, x, dy, r;
//   rd(X,Y,R);
//   x = round(X * 10000);
//   r = round(R * 10000);
//   rep(k,-2d5,2d5+1){
//     dy = abs(round((Y-k) * 10000));
//     if(dy > r) continue;
//     x1 = bsearch_min[__int128_t,z,-1d10,x]( (z-x)**2 + dy**2 <= r**2 );
//     x2 = bsearch_max[__int128_t,z,x,1d10]( (z-x)**2 + dy**2 <= r**2 );
//     res += fDiv(x2, 10000) - cDiv(x1, 10000) + 1;
//   }
//   wt(res);
// }
