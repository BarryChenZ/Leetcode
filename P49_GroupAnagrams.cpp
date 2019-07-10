class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        int n = strs.size();
        for(auto& s : strs){//黑紅樹
            string t = s;
            sort(t.begin(),t.end());
            map[t].push_back(s);
        }
        vector<vector<string>> res(map.size());
        int i = 0;
        for(auto& j : map){
            res[i++] = j.second;
        }
        return res;
    }
};
