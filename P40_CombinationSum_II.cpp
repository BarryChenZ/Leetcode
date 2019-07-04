class Solution {
public:
    int k = 0;
    vector<int> temp;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result(1000);
        sort(candidates.begin(),candidates.end());   
        for(int i = 0; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            target = target - candidates[i];
            if(target == 0){
                result[k] = temp;
                ++k;
                target = target + candidates[i];
            }
            else{
                search(result, candidates, target, i+1);
                target = target + candidates[i];
            }
            while(i < candidates.size()-1){
                if(candidates[i] == candidates[i+1]) i++;
                else break;
            }
            temp.clear();
        }
        
        result.resize(k);
        return result;
    }
    void search(vector<vector<int>>& result, vector<int>& candidates, int target, int i){
        for(int j = i; j < candidates.size(); j++){
            if(target == 0){
                result[k] = temp;
                k++;
                if(temp.size() > 0) temp.pop_back();
                break;
            }
            temp.push_back(candidates[j]);
            target = target - candidates[j];
            cout << target << endl;
            if(target == 0){
                result[k] = temp;
                k++;
                if(temp.size() > 0) temp.pop_back();
                break;
            }
            else if(target < 0){
                //cout << temp[temp.size()-1] << endl;
                if(temp.size() > 0) temp.pop_back();
                break;
            }
            else{
                cout << target << endl;
                search(result, candidates, target, j+1);
                target = target + candidates[j];
            }
            while(j< candidates.size()-1){
                if(candidates[j] == candidates[j+1]) j++;
                else break;
            }
        }
        if(temp.size() > 0) temp.pop_back();
    }
};
