#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const double eps = 1e-8;
const int NINF = 0xc0c0c0c0;
const int INF  = 0x3f3f3f3f;
const ll  mod  = 1e9 + 7;
const ll  maxn = 10;

ll n,m,k,a[maxn],st[maxn][21],pre[maxn],ans[maxn];

void getst(){
    for(int i=1;i<=n;i++)
        st[i][0]=upper_bound(pre+1,pre+1+n,pre[i-1]+k)-pre;
    for(int i=1;(1<<i)<n;i++)
        for(int j=1;j+(1<<i)<=n;j++)
            st[j][i]=st[st[j][i-1]][i-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
        ans[i]=ans[i-1]+(a[i]>k);
    }
    getst();
    while(m--){
        int L,R,res=1;
        cin>>L>>R;
        if(ans[R]-ans[L-1]>0){
            cout<<"Chtholly\n";
        }else{
        //这里注意要从大的开始跳，一个数总能从大的开始表示二进制，从小的开始可能会出现回溯
        //例如5=4+1如果从小的开始找就会出现5!=1+2+4然后回溯在到5=1+4所以要倒着来
            for(int i=20;st[L][0]<=R;i--)
                if(st[L][i]&&st[L][i]<=R)//这里之所以st[L][i]要非0，是因为如果从L跳2^i超过了R，则st[L][i]却为0的情况
                    L=st[L][i],res+=(1<<i);
            cout<<res<<'\n';
        }
    }
    return 0;
}