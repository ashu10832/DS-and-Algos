class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1){
            return s;
        }
        //Base Case for DP - Each element is a palindrome in itself
        int dp[n][n] = {};
        for(int i = 0;i<n;i++){
            dp[i][i] = 1;
        }
        
        int maxLength = 1;
        int maxStart = 0,maxEnd = 0;

        // if length is <=3, and if i,j chars are equal, then it is palindrome,
        // if length is >3, and if i,j chars are equal and i+1,j-1 string is palindrome, then it is                 palindrome
        for(int len = 2;len<=n; len++){
            for(int i = 0,j = len-1;j < n;i++,j++){
                if(s[i] == s[j] && (len<=3 || dp[i+1][j-1]==1)){
                    dp[i][j] = 1;
                    maxStart = i;
                    maxEnd = j;
                    maxLength = len;
                }
            }
        }
  
        return s.substr(maxStart,maxLength);
        
    }
};