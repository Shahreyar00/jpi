#include<bits/stdc++.h>
using namespace std;


vector<int>a[1000002];
int v[1000002]={0},b[1000002]={0},coun[1000002]={0},c=0;

void dfs(int s){
    v[s]=1;
    for(int i=0;i<a[s].size();i++){
        if(v[a[s][i]]==0){
            coun[b[a[s][i]]]++;
            if(coun[b[a[s][i]]]==2){
                coun[b[a[s][i]]]--;
                v[a[s][i]]=1;
                continue;
            }
            else{
                c++;
                dfs(a[s][i]);
            }
        }
    }
    if(coun[b[s]]>0)
        coun[b[s]]--;
}

int main()

{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin>>n;
    int i;
    for(i=1;i<=n;i++)
        cin>>b[i];

    for(i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    coun[b[1]]=1;
    dfs(1);
    cout<<c+1;
    return 0;
}