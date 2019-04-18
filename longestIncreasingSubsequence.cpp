#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int DP[1000];

int getLIS(int n,int a[]){
    int supermax = 0;
    for(int i = 1;i<n;i++){
        int max = DP[i];
        for(int j = 0;j<i;j++){
            if(a[i]>a[j]){
                if(DP[j]+1>max){
                    max = DP[j]+1;
                }
            }
            DP[i] = max;
            if(max>supermax){
                supermax = max;
            }
            
        }
    }
    return supermax;
    
  
    
}

int main() {
    int test;
    cin>>test;
    for(int t = 0;t<test;t++){
        int n;
        cin>>n;
        int *a = new int[n];
        for(int i = 0;i<n;i++){
            cin>>a[i];
            DP[i] = 1;
        }
        int h = getLIS(n,a);
        cout<<h<<endl;

    }
	return 0;
}