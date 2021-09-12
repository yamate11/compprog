#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int bs=2714;
struct query{
    int l,r,t,idx;
    bool operator<(query b){
        if(l/bs==b.l/bs){
            if(r/bs==b.r/bs)return t<b.t;
            return r<b.r;
        }return l<b.l;
    }
}qq[100'010];
struct update{
    int idx,pre,now;
}upd[100'010];
int ans[100'010];
int arr[100'010];
int cnt[100'010];
int aCnt[200'010];
void pl(int k){
    cnt[aCnt[k]]--;
    aCnt[k]++;
    cnt[aCnt[k]]++;
}
void mi(int k){
    cnt[aCnt[k]]--;
    aCnt[k]--;
    cnt[aCnt[k]]++;
}
map<int,int>mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,a,b,c;
    cin>>n>>m;
    int ud=-1,que=0,dif=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(mp[arr[i]]==0){
            mp[arr[i]]=++dif;
            arr[i]=dif;
        }else arr[i]=mp[arr[i]];
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(a==1){
            qq[que]={b,c,ud,que};
            que++;
        }else{
            if(mp[c]==0){
                mp[c]=++dif;
                c=dif;
            }else c=mp[c];
            upd[++ud]={b,arr[b],c};
            arr[b]=c;
        }
    }
    cnt[0]=n+ud+100;
    sort(qq,qq+que);
    int s=1,e=0,now=ud;
    long long op_count = 0;
    for(int i=0;i<que;i++){
      while(e<qq[i].r) {
        pl(arr[++e]);
        op_count++;
      }
      while(qq[i].l<s) {
        pl(arr[--s]);
        op_count++;
      }
      while(qq[i].r<e) {
        mi(arr[e--]);
        op_count++;
      }
      while(s<qq[i].l) {
        mi(arr[s++]);
        op_count++;
      }
      while(now<qq[i].t){
        now++;a=upd[now].idx;b=upd[now].pre,c=upd[now].now;
        arr[a]=c;
        if(s<=a&&a<=e){
          mi(b);pl(c);
        }
        op_count++;
      }
      while(qq[i].t<now){
        a=upd[now].idx;b=upd[now].pre,c=upd[now].now;
        arr[a]=b;
        if(s<=a&&a<=e){
          mi(c);pl(b);
        }
        now--;
        op_count++;
      }
      int k=1;
      while(cnt[k++]);
      ans[qq[i].idx]=k-1;
    }
    for(int i=0;i<que;i++){
        cout<<ans[i]<<'\n';
    }
    cerr << "op_count = " << op_count << endl;
}
