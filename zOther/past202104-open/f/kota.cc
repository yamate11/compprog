#include<iostream>
using namespace std;
int N,L,T,X;
int A[100],B[100];
main()
{
	cin>>N>>L>>T>>X;
	for(int i=0;i<N;i++)cin>>A[i]>>B[i];
	int now=0;
	int ans=0;
	for(int i=0;i<N;i++)
	{
		if(L>B[i])
		{
			ans+=A[i];
			now=0;
		}
		else
		{
			if(A[i]>T)
			{
				cout<<"forever"<<endl;
				return 0;
			}
			if(now+A[i]>T)
			{
				ans+=T-now;
				ans+=X;
				now=0;
			}
			ans+=A[i];
			now+=A[i];
			if(now==T)
			{
				ans+=X;
				now=0;
			}
		}
	}
	cout<<ans<<endl;
}
