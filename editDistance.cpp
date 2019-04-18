class Solution {
public:
    

int minDistance(string a, string b) {
    int m = a.length();
    int n = b.length();
    
    int **DP = new int*[m+1];
    for(int i = 0; i <= m; ++i) {
        DP[i] = new int[n+1];
    }

    
    for(int i = 0;i<=m;i++){
        for(int j = 0;j<=n;j++){
            if(i == 0){
                DP[i][j] = j;
                continue;
            }
            if(j == 0){
                DP[i][j] = i;
                continue;
            }
            
            if(a[i-1] == b[j-1]){
                DP[i][j] = DP[i-1][j-1];
                continue;
            }
            DP[i][j] = min(min(DP[i-1][j-1],DP[i-1][j]),DP[i][j-1]) + 1;
        }
    }
    return DP[m][n];
    }
};