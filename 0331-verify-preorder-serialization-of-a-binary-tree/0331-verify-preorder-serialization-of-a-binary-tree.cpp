class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<int> arr;
        int n=preorder.size();
        string node="";
        stack<string> st;
        for(int i=0;i<n;i++){
            if(preorder[i]==','){
                st.push(node);
                while (st.size() >= 3) {
                    string a = st.top(); st.pop();   
                    string b = st.top(); st.pop();
                    string c = st.top(); st.pop();

                    if (a == "#" && b == "#" && c != "#") {
                        
                        st.push("#");
                    } else {
                        st.push(c);
                        st.push(b);
                        st.push(a);
                        break;
                    }
                }
            if (node != "#")
                arr.push_back(stoi(node));

            node = "";
            continue;
            }
            node+=preorder[i];
        }
        if (!node.empty()) {
            st.push(node);
            while (st.size() >= 3) {
                    string a = st.top(); st.pop();   
                    string b = st.top(); st.pop();
                    string c = st.top(); st.pop();

                    if (a == "#" && b == "#" && c != "#") {
                        
                        st.push("#");
                    } else {
                        st.push(c);
                        st.push(b);
                        st.push(a);
                        break;
                    }
            }
            if (node != "#")
                arr.push_back(stoi(node));
        }
        
        return st.size()==1 && st.top()=="#";
    }
};