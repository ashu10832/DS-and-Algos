class Solution {
public:
    
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 0){
            vector<vector<string>> o;
            return o;
        }
        unordered_map<string,vector<string>> map;
        //This is taking O(n) 
        for(int i = 0;i<strs.size();i++){
            string word = strs[i];
            //Taking O(mlog(m)) 
            sort(word.begin(),word.end());
            map[word].push_back(strs[i]);
        }
        
   
        vector<vector<string>> finalOutput;
        
        for (auto& x: map) {
            vector<string> v;
            for(int k = 0;k<x.second.size();k++){
                v.push_back(x.second[k]);
            }
            finalOutput.push_back(v);
         }
       
        return finalOutput;
        
    }
};