#include <bits/stdc++.h>
using namespace std;
long dp[1001][1001];

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
   
    long k; cin>>k;
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dp[i][j];
        }
    }
    for(int i=1;i<n;i++)
        	dp[i][0]+=dp[i-1][0];
    for(int j=1;j<n;j++)
        	dp[0][j]+=dp[0][j-1];
    for(int i=1;i<n;i++){
        	for(int j=1;j<n;j++){
        		dp[i][j]+=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]);
    		}
    	}
    long s=1,e=n;
   long long sum;
    while(s+1<e){
       
        long m=(s+e)/2;
       
        int flag=0;
        
        for(int i=0;i+m<=n;i++){
            for(int j=0;j+m<=n;j++){
                long long  sum=dp[i+m-1][j+m-1];
    			if(i>0) sum-=dp[i-1][j+m-1];
    			if(j>0) sum-=dp[i+m-1][j-1];
    			if(i>0&&j>0) sum+=dp[i-1][j-1];
    			if(sum<=k) flag=1;
            }
        }
        if(flag) s=m;
        else e=m-1;
    }
   long m=s+1;
    int flag=0;
        for(int i=0;i+m<=n;i++){
            for(int j=0;j+m<=n;j++){
                long long  sum=dp[i+m-1][j+m-1];
    			if(i>0) sum-=dp[i-1][j+m-1];
    			if(j>0) sum-=dp[i+m-1][j-1];
    			if(i>0&&j>0) sum+=dp[i-1][j-1];
    			if(sum<=k) flag=1;
            }
        }
    if(flag==1)
    cout<<s+1<<endl;
    else
    cout<<s<<endl;
}
