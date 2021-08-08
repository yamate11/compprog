#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#include <list>
#include <atcoder/all>
#define popcount __builtin_popcount
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> P;
using mint=modint998244353;
int main()
{
    ll p; cin>>p;
    if(p==2){
        cout<<2<<endl;
        return 0;
    }
    ll m=p-1;
    vector<ll> v;
    for(ll d=1; d*d<=m; d++){
        if(m%d==0){
            v.push_back(d);
            if(d*d<m) v.push_back(m/d);
        }
    }
    sort(v.begin(), v.end());
    int n1=v.size();
    vector<ll> vc(n1);
    mint ans=1;
    for(int i=n1-1; i>=0; i--){
        vc[i]=m/v[i];
        for(int j=i+1; j<n1; j++){
            if(v[j]%v[i]==0) vc[i]-=vc[j];
        }
        cerr << m/v[i] << " " << vc[i] << "\n";
        ans+=mint(m/v[i])*mint(vc[i]);
    }
    cout<<ans.val()<<endl;
    return 0;
}
