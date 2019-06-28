class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        if (words[0].size() > s.size()) return res;
        // build a hash map of words
        std::unordered_map<string, int> map;
        for (auto w : words) map[w]++;
        
        size_t len = words[0].size();
        // len is the window size, which is also the number of iterations
        // to get all possible sliding windows (substr of size len) we need to start
        // at position of 0, 1,.. len-1
        for (int i = 0; i < len; i++) {
            int l = i; // l : leading position
            int curr = i; // curr : current sliding window front position
            std::unordered_map<string, int> tmap;
            int cnt = 0; // the length of current matching, if cnt == words.size() then we find a right position
            
            while (curr <= s.length() - len) {
                string w = s.substr(curr, len); // current sliding window
                tmap[w]++; // keep tracking the total number of words
                curr += len; // move the sliding window
                cnt++; // if w doesn't qualify, we derease cnt later
                
                while (tmap[w] > map[w]) {
                    // w doesn't qualify, since we don't have enough w in map
                    // then we need to move l (the leading position), update tmap, and decrease cnt
                    string leading = s.substr(l,len);
                    tmap[leading]--;
                    l += len;
                    cnt--;
                }
                
                if (cnt == words.size()) res.push_back(l);
                    
            }
        }
        return res;
    }
};
//參考
