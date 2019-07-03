class Solution {
public:
    int k = 0;
    vector<int> temp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result(1000);
        sort(candidates.begin(),candidates.end());   
        search(result, candidates, target, 0);
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
                search(result, candidates, target, j);
                target = target + candidates[j];
            }
        }
        if(temp.size() > 0) temp.pop_back();
    }
};
