#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int len1=s.length();
    int len2=t.length();
    bool dp[105][105][55];
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=true;
    for(int q=0;q<len1;q++){
        for(int w=0;w<len2;w++){
            for(int e=0;e<len1/2;e++){
                if(dp[q][w][e]){
                    if(e==0&&s[q+1]==t[w+1]) dp[q+1][w+1][0]=true;
                    if(s[q+1]=='(') dp[q+1][w][e+1]=true;
                    else if(e) dp[q+1][w][e-1]=true;
                }
            }
        }
    }
    if(dp[len1][len2][0]) cout<<"Possible"<<endl;
    else    cout<<"Impossible"<<endl;
    return 0;
}