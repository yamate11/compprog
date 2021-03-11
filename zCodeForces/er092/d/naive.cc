#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin>>T;
  while(T--)
    {
      int n;
      ll k;
      cin>>n>>k;
      ll l1,l2,r1,r2;
      cin>>l1>>r1>>l2>>r2;
      if(max(l1,l2)<=min(r1,r2)){
	ll cnt=n*(min(r1,r2)-max(l1,l2));
	if(cnt>=k){
	  cout<<"0\n";
	}
	else{
	  ll rem=k-cnt;
	  ll more=n*(max(l1,l2)-min(l1,l2)+max(r1,r2)-min(r1,r2));
	  if(more>=rem){
	    cout<<rem<<"\n";
	  }
	  else{
	    ll ans=more+2*(rem-more);
	    cout<<ans<<"\n";
	  }
	}
      }
      else{
	ll ans=1e18;
	for(int i=1; i<=n; i++){
	  ll steps=i*(max(l1,l2)-min(r1,r2));
	  ll more=i*(max(r1,r2)-min(l1,l2));
	  if(more>=k){
	    ans=min(ans,steps+k);
	  }
	  else{
	    ans=min(ans,steps+more+2*(k-more));
	  }
	}
	cout<<ans<<"\n";

      }
    }
  return 0;
}
