#include<bits/stdc++.h>

using namespace std;
using ll=long long;
using i128=__int128;

struct frac{
  i128 p;
  i128 q;
  friend frac operator+(frac a, frac b) {
    frac res={a.p*b.q+a.q*b.p, a.q*b.q};
    if(res.q<0){res.p*=-1; res.q*=-1;}
    return res;
  }
  friend frac operator-(frac a, frac b) {
    frac res={a.p*b.q-a.q*b.p, a.q*b.q};
    if(res.q<0){res.p*=-1; res.q*=-1;}
    return res;
  }
  friend frac operator*(frac a, frac b) {
    frac res={a.p*b.p, a.q*b.q};
    if(res.q<0){res.p*=-1; res.q*=-1;}
    return res;
  }
  friend frac operator/(frac a, frac b) {
    frac res={a.p*b.q, a.q*b.p};
    if(res.q<0){res.p*=-1; res.q*=-1;}
    return res;
  }
  bool operator ==(const frac &r){
    return (((this->p)*r.q) == ((this->q)*r.p));
  }
  bool operator <(const frac &r){
    return (((this->p)*r.q) < ((this->q)*r.p));
  }
  bool operator <=(const frac &r){
    return (((this->p)*r.q) <= ((this->q)*r.p));
  }
};

struct pnt{
  frac x;
  frac y;
};

bool check(frac tg,frac D,pnt vec){
  tg=tg*tg;
  D=D*D;
  frac lef=vec.x*vec.x;
  frac rig=vec.y*vec.y;
  D=D/lef;
  D=D*(lef+rig);
  return (tg<=D);
}

ll solve(ll N,frac D,vector<pnt> X){
  ll res=1;
  {
    // dummy
    pnt del={{1ll,1ll},{1ll,1ll}};
    vector<frac> fv;
    for(ll k=0;k<N;k++){
      frac gap=(X[k].x/del.x)*del.y;
      fv.push_back(X[k].y-gap);
    }
    sort(fv.begin(),fv.end());
    ll r=0;
    for(ll l=0;l<N;l++){
      while(r<N && check(fv[r]-fv[l],D,del)){
        r++;
      }
      res=max(res,r-l);
    }
  }
  for(ll i=0;i<N;i++){
    for(ll j=i+1;j<N;j++){
      if(X[i].x==X[j].x){continue;}
      pnt del={X[j].x-X[i].x,X[j].y-X[i].y};
      vector<frac> fv;
      for(ll k=0;k<N;k++){
        frac gap=(X[k].x/del.x)*del.y;
        fv.push_back(X[k].y-gap);
      }
      sort(fv.begin(),fv.end());
      ll r=0;
      for(ll l=0;l<N;l++){
        while(r<N && check(fv[r]-fv[l],D,del)){
          r++;
        }
        res=max(res,r-l);
      }
    }
  }
  return res;
}

int main(){
  ll N,D;
  cin >> N >> D;
  vector<pnt> X(N);
  for(auto &nx : X){
    ll rx,ry;
    cin >> rx >> ry;
    nx.x.p=rx;
    nx.y.p=ry;
    nx.x.q=1; nx.y.q=1;
  }
  ll res=solve(N,frac{2*D,1},X);
  for(auto &nx : X){
    swap(nx.x,nx.y);
  }
  res=max(res,solve(N,frac{2*D,1},X));
  cout << res << "\n";
  return 0;
}
