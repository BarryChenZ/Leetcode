class Solution {
public:
    int myAtoi(string str) {
        smatch temp;
        int result = 0;
        int k1 = -2147483648;
        int k2 = 2147483647;
        regex pattern("^\\s*(([-+]?)0*(\\d+))\\s*");
        if(regex_search(str, temp, pattern)){
            cout << temp.str(3) << endl;
            if(temp.str(3).size() > 10){
                if(temp.str(2)[0] == '-') result = -2147483648;
                else result = 2147483647;
            }
            else if(temp.str(3).size() == 10){
                string temp1 = "2147483648";
                string temp2 = "2147483647";
                if(temp.str(2)[0] == '-'){
                    for(int i = 0; i < 10; ++i){
                        string count;
                        count += temp.str(3)[i];
                        //int k = atoi(count.str())*pow(10,9-i);
                        k1 += atoi(count.c_str())*pow(10,9-i);
                        if( k1 > 0) {
                            result = -2147483648;
                            break;
                        }
                        else if((atoi(count.c_str()) > 2 && i == 0)){
                            result = -2147483648;
                            break;
                        }
                        else{
                        result = atoi(temp.str(1).c_str());
                        }
                    }
                }
                else{
                    for(int i = 0; i < 10; ++i){
                        string count;
                        count += temp.str(3)[i];
                        //char count = temp.str(3)[i];
                        k2 -= atoi(count.c_str())*pow(10,9-i);
                        cout << i << endl;
                        if( k2 < 0) {
                            result = 2147483647;
                            break;
                        }
                        else if(atoi(count.c_str()) > 2 && i == 0){
                            result = 2147483647;
                            break;
                        }
                        else{
                            result = atoi(temp.str(1).c_str());
                        }
                    }
                }
            }
            else
            result = atoi(temp.str(1).c_str());
        }
        return result;
    }
};
