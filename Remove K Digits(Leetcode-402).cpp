class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size())return "0";

        stack<int>st;

     for(int i=0;i<num.size();i++)
       { 
        while(!st.empty()&&k>0 &&st.top()>num[i])
        {
            st.pop();
            k--;
        }

        st.push(num[i]);
        }
 while(!st.empty()&&k>0 )
 {
    st.pop();
    k--;
 }

 string ans;
 while(!st.empty())
 {
    ans+=st.top();st.pop();
 }

 reverse(ans.begin(),ans.end());

int pos=0;// leading zeros
 while (pos < ans.size() && ans[pos] == '0') {
            pos++;
        }
        if (pos == ans.size()) return "0"; // If the result is all zeros, return "0"
        return ans.substr(pos);
          
    }
};
