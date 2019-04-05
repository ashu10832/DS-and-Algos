/*** 
Runtime: 12 ms, faster than 99.84% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 9.3 MB, less than 99.51% of C++ online submissions for Longest Substring Without Repeating Characters.
***/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        vector<bool> used(256,0);
        int superMax = 0,currMax = 0;
        
        
        for(int i = 0;i<=s.length();){
            
            if(s[i] == '\0'){
                return superMax>currMax?superMax:currMax;
            }
            // If this character is already used
            if(used[(int)s[i]]){
                if(currMax>superMax){
                    superMax = currMax;
                }
                used[(int)s[start]] = 0;
                start++;
                currMax--;
            }
            else{
                used[(int)s[i]] = 1;

                i++;
                currMax++;
            }
        }
        return superMax;
        
        
        
    }
};