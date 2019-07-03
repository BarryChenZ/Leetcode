class Solution {
public:
    string countAndSay(int n) {
        string result;
        result.append("1");
        if(n == 1) return result;
        result.append("1");
        if(n == 2) return result;
        
        for(int i = 3; i < n+1; i++){
            string temp;
            int counter = 0;
            int size = result.size();
            for(int j = 0; j < size; j++){
                counter++;
                if(j < size-1 && result[j] != result[j+1]){
                    cout << counter << endl;
                    temp.append(std::to_string(counter));
                    string A;
                    A.push_back(result[j]);
                    temp.append(A);
                    counter = 0;
                }
                if(j == size-1){
                    cout << counter << endl;
                    temp.append(std::to_string(counter));
                    string A;
                    A.push_back(result[j]);
                    temp.append(A);
                    counter = 0;
                }
            }
            cout << temp << endl;
            result = result.replace(0, temp.size(), temp);
        }
        return result;
    }
};
