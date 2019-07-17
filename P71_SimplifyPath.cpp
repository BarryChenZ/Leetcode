class Solution {
public:
    string simplifyPath(string path) {
        if(path=="") return path;
        stringstream cinstr(path);
        string str;
        stack<string> st;
        while(getline(cinstr,str,'/')) {
            if(str=="..") {
                if(!st.empty())
                    st.pop();
            }
            else if(str!="" && str!=".")
                st.push(str);
        }
        str="";
        while(!st.empty()) {
            cout<<st.top();
            str = '/' + st.top() + str;
            st.pop();
        }
        if(str=="") return "/";
        return str;
    }
};
