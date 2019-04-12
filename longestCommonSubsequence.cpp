/**
 * Given two sequences, find the length of longest subsequence present in both of them. 
 * Both the strings are of uppercase.
 * **/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2, int l1, int l2){
    int DP[101][101] = {};
    
    for(int i = 0;i<l1;i++){
    	for(int j = 0;j<l2;j++){
    		if(i == 0 || j == 0){
    			if(s1[i] == s2[j]){
    				DP[i][j] = 1;
    			}
    			else{
    			    if(i == 0)
    				    DP[i][j] = DP[i][j-1];
    				else
    				    DP[i][j] = DP[i-1][j];
    			}
    		}
    		else{
    			if(s1[i] == s2[j]){
    				DP[i][j] = DP[i-1][j-1] + 1;
    			}
    			else{
    				DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
    			}
    		}
    	}
    }
    return DP[l1-1][l2-1];
    
    
}

int main() {
	//code
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
	    int l1,l2;
	    cin>>l1>>l2;
	    
	    string s1,s2;
	    cin>>s1;
	    cin>>s2;
	    
	  
		//cout<<s1;
		//cout<<s2;
	    int val = lcs(s1,s2,l1,l2);
	    cout<<val<<endl;
	    //cout<<val;
	    
	}
	
	return 0;
}