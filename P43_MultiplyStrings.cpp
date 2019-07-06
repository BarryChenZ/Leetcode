class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() == 0 || num2.size() == 0) return string("0");
        int m = num1.size();
        int n = num2.size();
        vector<int> tmp(m+n);
        for(int i = m-1; i >=0; i--){
			for(int j  = n-1; j>=0; j--){
				int idx = (m-1-i) + (n-1-j);
				tmp[idx] += (num1[i]-'0') * (num2[j]-'0');
			}
		}
        
        for(int i = 0; i<m+n-1; i++){
			int data  = tmp[i]; 
			tmp[i] = data%10;
			int idx = i+1;
			while(data/10){
				data /= 10;
				tmp[idx++] += (data%10);
			}
		}
        
        string res(m+n,'0');
		for(int i = 0; i <m+n;i++){
			int idx = m+n-1-i;
			res[idx] = tmp[i]+'0';
		}
        
        int idx = 0;
		while(idx<m+n && res[idx] =='0') idx++;
		if(idx == m+n) return string("0");
		return res.substr(idx);
    }
};
