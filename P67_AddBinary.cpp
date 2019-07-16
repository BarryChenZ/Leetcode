class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size();
        int n2 = b.size();
        int n = n1 > n2 ? n1 : n2;
        if(n1 == 0) return b;
        if(n2 == 0) return a;
        string res;
        if(n == n1){
            b.insert(b.begin(),n1-n2,'0');
        }
        if(n == n2){
            a.insert(a.begin(),n2-n1,'0');
        }
        int counter = 0;
        for(int i = n - 1; i >= 0; i--){
            int temp1 = a[i] - '0';
            int temp2 = b[i] - '0';
            cout << temp1 << temp2 << endl;
            int temp = temp1 + temp2 + counter;
            switch(temp){
                case 0:
                    counter = 0;
                    res.insert(res.begin(), '0');
                    break;
                case 1:
                    counter = 0;
                    res.insert(res.begin(), '1');
                    break;
                case 2:
                    counter = 1;
                    res.insert(res.begin(), '0');
                    break;
                case 3:
                    counter = 1;
                    res.insert(res.begin(), '1');
                    break;    
            }
        }
        if(counter == 1){
            res.insert(res.begin(), '1');
        }
        return res;
    }
};
