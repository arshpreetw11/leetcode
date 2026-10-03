class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum=0;
        for(string n:operations){
            if(n=="+"){
                int s=0;
                if(st.size()>=2){
                    int a=st.top();
                    s+=a;
                    st.pop();
                    s+=st.top();
                    st.push(a);
                    st.push(s);
                }
            }
            else if(n=="D"){
                st.push(st.top()*2);
            }
            else if(n=="C"){
                st.pop();
            }
            else{
                st.push(stoi(n));
            }
        }
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};