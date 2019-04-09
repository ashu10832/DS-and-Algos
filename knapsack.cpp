//Correct Answer.Correct Answer
//Execution Time:0.13



#include <iostream>
using namespace std;


int knapsack(int capacity,int values[], int weights[], int n){
    int DP[1001][1001];

    for(int i = 0;i<=n;i++){
        for(int w = 0;w<=capacity;w++){
            
            if(i == 0 || w == 0){
                DP[i][w] = 0;
            }
            else if(weights[i-1]<=w){
                DP[i][w] = max(values[i-1] + DP[i-1][w-weights[i-1]],DP[i-1][w]);
            }
            else{
                DP[i][w] = DP[i-1][w];

            }
        }
        
    }
    return DP[n][capacity];
}




int main() {
	int T;
	cin>>T;
	for(int t = 0;t<T;t++){
	    int n;
	    cin>>n;
	    int w;
	    cin>>w;
	  
	    int *val = new int[n+1];
	    int *weight = new int[n+1];
	    for(int i = 0;i<n;i++){
	        cin>>val[i];
	    }
	    for(int i = 0;i<n;i++){
	        cin>>weight[i];
	    }
	    cout<<knapsack(w,val,weight,n)<<endl;
	   
	}
	return 0;
}