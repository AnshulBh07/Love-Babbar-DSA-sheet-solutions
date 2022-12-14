#include<iostream>
#include<algorithm>
using namespace std;

string SCS(string X,string Y,int n,int m){
    int t[n+1][m+1];

    //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0)
            t[i][j] = 0;
        }
    }

    //choice diagram for LCS
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(X[i-1]==Y[j-1])
            t[i][j] = 1 + t[i-1][j-1];
            else
            t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    }

    //printing SCS
    int i=n,j=m;
    string s="";
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            s.push_back(X[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                s.push_back(Y[j-1]);
                j--;
            }
            else{
                s.push_back(X[i-1]);
                i--;
            }
        }
    }
    //if one of the string is still left
    while(i>0){
        s.push_back(X[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(Y[j-1]);
        j--;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main()
{
    string X = "acbcf", Y = "abcdaf";
    int n = X.length(), m = Y.length();

    string ans;
    ans = SCS(X,Y,n,m);
    cout<<ans;
    return 0;
}