class Solution {
public:
    int k = 0;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res(intervals.size());
        int n = intervals.size();
        if(n == 0) return res;
        sort(intervals.begin(), intervals.end());
        int left_side = intervals[0][0];
        int right_side = intervals[0][1];
        intervals.erase(intervals.begin());
        while(!intervals.empty()){
            if(intervals[0][0] > right_side){
                cout << left_side << right_side << endl;
                res[k].push_back(left_side);
                res[k].push_back(right_side);
                left_side = intervals[0][0];
                right_side = intervals[0][1];
                intervals.erase(intervals.begin());
                k++;
            }
            else{
                if(left_side > intervals[0][0]){
                    left_side = intervals[0][0];
                }
                if(right_side < intervals[0][1]){
                    right_side = intervals[0][1];
                }
                intervals.erase(intervals.begin());
            }
        }
        cout << left_side << right_side << endl;
        res[k].push_back(left_side);
        res[k].push_back(right_side);
        k++;
        res.resize(k);
        return res;
    }
};
