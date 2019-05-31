class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        int temp = 0;
        for(int i = 0; i < s.size(); i++){
            int level = 0;
            int next_level = 8;
            switch(s[i]){
                case 'M':
                    level = 1;
                    break;
                case 'D':
                    level = 2;
                    break;
                case 'C':
                    level = 3;
                    break;
                case 'L':
                    level = 4;
                    break;
                case 'X':
                    level = 5;
                    break;
                case 'V':
                    level = 6;
                    break;
                case 'I':
                    level = 7;
                    break;
            }
            if( i !=  s.size()-1){
                switch(s[i+1]){
                case 'M':
                    next_level = 1;
                    break;
                case 'D':
                    next_level = 2;
                    break;
                case 'C':
                    next_level = 3;
                    break;
                case 'L':
                    next_level = 4;
                    break;
                case 'X':
                    next_level = 5;
                    break;
                case 'V':
                    next_level = 6;
                    break;
                case 'I':
                    next_level = 7;
                    break;
            }
            }
            int rule = 1;
            if(next_level < level) rule = -1;
            switch(level){
                case 1:
                    temp = rule*1000;
                    break;
                case 2:
                    temp = rule*500;
                    break;
                case 3:
                    temp = rule*100;
                    break;
                case 4:
                    temp = rule*50;
                    break;
                case 5:
                    temp = rule*10;
                    break;
                case 6:
                    temp = rule*5;
                    break;
                case 7:
                    temp = rule*1;
                    break;
            }
            cout << level << next_level << " " << temp << endl;
            num += temp;
        }
        return num;
    }
};
