#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;cin>>N;
	map<long long,long long> mp;
	priority_queue<long long,vector<long long>,greater<long long>> pq;
	for(int i=0;i<N;i++){
		int s,c;
		cin>>s>>c;
		mp[s]=c;
		pq.push(s);
	}
	long long ans=0ll;
	while(pq.size()){
		long long s=pq.top();pq.pop();
		long long c=mp[s];
                mp.erase(s);
		if(!mp.count(s*2) and 2<=c){
			mp[s*2]=c/2;
			pq.push(2*s);
		}
		else mp[2*s]+=c/2;
		ans+=c%2;
		//cout<<s<<" "<<c<<"\n";
	}
	cout<<ans<<"\n";
}
