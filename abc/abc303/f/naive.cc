#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

long long sum(long long n){
	return n*(n+1)/2;
}

long long get(long long l,long long r){
	return sum(r) - sum(l-1);
}

int main() {
    
	int N;
	long long H;
	cin>>N>>H;
	
	vector<pair<long long,long long>> td(N);
	rep(i,N){
		cin>>td[i].first>>td[i].second;
	}
	
	sort(td.begin(),td.end());
	
	{
		auto t = td;
		t.resize(0);
		rep(i,N){
			while(t.size()!=0 && t.back().second<=td[i].second)t.pop_back();
			t.push_back(td[i]);
		}
		td = t;
	}
	
	long long ma = 0;
	long long cur = 0;
	rep(i,td.size()){
		long long t = td[i].first,d = td[i].second;
		long long x = ma/d;
		x = min(x,t);
		long long y = x-cur;
		if(ma!=0)y = min(y,(H+ma-1)/ma);
		H -= ma*y;
		cur += y;
		if(H<=0){
			cout<<cur<<endl;
			return 0;
		}
		if(cur!=t){
			long long ng = cur,ok = t;
			long long r = (H+d-1)/d;
			while(ok-ng>1LL){
				long long mid = (ok+ng)/2;
				if(get(cur+1,mid)>=r)ok = mid;
				else ng = mid;
			}
			H -= get(cur+1,ok) * d;
			cur = ok;
			if(H<=0){
				cout<<cur<<endl;
				return 0;
			}
		}
		ma = max(ma,t*d);
		
	}
	cout<<cur + (H+ma-1)/ma<<endl;
	
	return 0;
}
