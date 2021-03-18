// {{{ by WangYenJen
#include <bits/stdc++.h>
using namespace std;
// types
typedef long long ll;
typedef pair<int,int> pii;
// macro
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin() , (x).end()
#define REP(i , n) for(int i = 0; i < int(n); i++)
#define REP1(i , a , b) for(int i = a; i <= int(b); i++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LC o<<1 , l , m
#define RC o<<1|1 , m + 1 , r
#define MS(x , v) memset(x , (v) , sizeof(x));
// input
inline bool SR(int &x) {
	return scanf("%d",&x) == 1;
}
inline bool SR(ll &x) {
	return scanf("%lld",&x) == 1;
}
inline bool SR(double &x) {
	return scanf("%lf",&x) == 1;
}
inline bool SR(char *s) {
	return scanf("%s",s) == 1;
}
inline bool RI() {
	return true;
}
template<typename I , typename... T> inline bool RI(I &x , T&... tail) {
	return SR(x) && RI(tail...);
}
// output
inline void SP(const int x) {
	printf("%d",x);
}
inline void SP(const ll x) {
	printf("%lld",x);
}
inline void SP(const double x) {
	printf("%.16lf",x);
}
inline void SP(const char *s) {
	printf("%s",s);
}
inline void PL() {
	puts("");
}
template<typename I , typename... T> inline void PL(const I x , const T... tail) {
	SP(x);
	if(sizeof...(tail)) putchar(' ');
	PL(tail...);
}
// debug
#define WangYenJen
#ifdef WangYenJen
template<typename I> void _DOING(const char *s , I&& x) {
    cerr << s << " = " << x << endl;
}
template<typename I , typename... T> void _DOING(const char *s , I&& x , T&&... tail) {
    int c = 0;
    while(*s != ',' || c != 0) {
        if(*s == '(' || *s == '[' || *s == '{') c++;
        if(*s == ')' || *s == ']' || *s == '}') c--;
        cerr << *s++;
    }
    cerr << " = " << x << " , ";
    _DOING(s + 1 , tail...);
}
#define debug(...) \
do {\
    fprintf(stderr , "%s:%d - ",__PRETTY_FUNCTION__,__LINE__);\
    _DOING(#__VA_ARGS__ , __VA_ARGS__);\
} while(0);
#else
#define debug(...)
#endif
// random function
inline int RAND() {
	static int x = 880301;
	return (x = x * 0xdefaced + 1) & 0x7fffffff;
}
// }}}

const int MAX_N = 200 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
struct Matrix {
    ll a[MAX_N][MAX_N];
    int r , c;

    Matrix(int _r = 0 , int _c = 0) : r(_r) , c(_c) {
        REP(i , _r) {
            REP(j , _c) if(i == j) a[i][j] = 0; else a[i][j] = -INF;
        }
    }
};
inline Matrix operator * (const Matrix &a , const Matrix &b) {
    Matrix c(a.r , b.c);
    REP(k , a.c) {
        REP(i , a.r) {
            REP(j , b.c) c.a[i][j] = max(c.a[i][j] , a.a[i][k] + b.a[k][j]);
        }
    }
    return c;
}
inline Matrix power(Matrix a , ll n) {
    Matrix x(a.r , a.c);
    while(n) {
        if(n&1) x = x * a;
        a = a * a;
        n >>= 1;
    }
    return x;
}
int id_cnt;
struct Node {
    Node *nxt[26] , *fail;
    int id;
    ll val;
    Node() {
        MS(nxt , 0);
        fail = NULL;
        id = id_cnt++;
        val = 0;
    }
};
Node *root = NULL;
inline void insert(char *s , ll val) {
    Node *p = root;
    while(*s) {
        if(!p->nxt[*s - 'a']) p->nxt[*s - 'a'] = new Node();
        p = p->nxt[*s - 'a'] , s++;
    }
    p->val += val;
}
inline void build_ac() {
    queue<Node*> que;
    que.push(root);
    while(!que.empty()) {
        Node *u = que.front();
        que.pop();
        REP(i , 26) {
            if(u->nxt[i]) {
                if(u == root) u->nxt[i]->fail = root;
                else {
                    Node *p = u->fail;
                    while(p) {
                        if(!p->nxt[i]) p = p->fail;
                        else break;
                    }
                    if(p) u->nxt[i]->fail = p->nxt[i] , u->nxt[i]->val += p->nxt[i]->val;
                    else u->nxt[i]->fail = root;
                }
                que.push(u->nxt[i]);
            }
        }
    }
}
Matrix mat;
inline void build_mat() {
    queue<Node*> que;
    que.push(root);
    mat = Matrix(id_cnt , id_cnt);
    while(!que.empty()) {
        Node *u = que.front();
        que.pop();
        REP(i , 26) {
            if(u->nxt[i]) {
                mat.a[u->id][u->nxt[i]->id] = u->nxt[i]->val;
                que.push(u->nxt[i]);
            }
            else {
                Node *p = u->fail;
                while(p) {
                    if(!p->nxt[i]) p = p->fail;
                    else break;
                }
                if(p) mat.a[u->id][p->nxt[i]->id] = p->nxt[i]->val;
            }
        }
    }
}
ll a[MAX_N];
char str[MAX_N];
int main() {
    root = new Node();
    int n;
    ll l;
    RI(n , l);
    REP(i , n) RI(a[i]);
    REP(i , n) {
        RI(str);
        insert(str , a[i]);
    }
    build_ac();
    build_mat();
    Matrix x = power(mat , l);
    ll ans = 0;
    REP(i , id_cnt) ans = max(ans , x.a[0][i]);
    PL(ans);
    return 0;
}
