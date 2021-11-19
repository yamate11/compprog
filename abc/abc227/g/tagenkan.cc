#define MOD 998244353
#include <bits/stdc++.h>
using namespace std;

long long sqrtint(long long N){
  long long n0,n1;
  if(N<2) return N;
  n0=N;
  n1=(n0+N/n0)/2;
  while(n0>n1){
    n0=n1;
    n1=(n0+N/n0)/2;
  }
  return n0;
}

vector<int> primes(int N){
  vector<int> prime;
  vector<bool> sieve(N,1);
  for(long long i=2;i<=sqrtint(N);i++)
    if(sieve[i-1])
      for(long long j=i*i;j<=N;j+=i)
        sieve[j-1]=0;
  for(long long i=2;i<=N;i++)
    if(sieve[i-1])
      prime.push_back(i);
  return prime;
}

long long modPow(long long x,long long a){
  if (a==0) return 1;
  long long t=modPow(x,a>>1);
  t=(t*t)%MOD;
  if (a&1)
    t=(x*t)%MOD;
  return t;
}

int main(){
  long long N,K;
  cin >> N >> K;
  vector<int> prime=primes(max(sqrtint(N),K));
  vector<long long> d(K,1);
  long long ans=1,L=N-K+1;
  for(int p:prime){
    long long q=p,f=0;
    while(1){
      long long M=L%q;
      if(M) M=q-M;
      if(M>=K) break;
      for(long long i=M;i<K;i+=q){
        f++;
        d[i]*=p;
      }
      q*=p;
    }
    long long l=K;
    while(l){
      l/=p;
      f-=l;
    }
    ans=((f+1)*ans)%MOD;
  }
  long long pr=0;
  for(int i=0;i<K;i++)
    if(d[i]<L+i)
      pr++;
  ans=modPow(2,pr)*ans%MOD;
  cout << ans << endl;
}
