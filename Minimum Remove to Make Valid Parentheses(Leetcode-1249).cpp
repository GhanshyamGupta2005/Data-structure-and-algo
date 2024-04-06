// class Solution {
// public:
//     string minRemoveToMakeValid(string s) {
//       vector<int>vis(s.size(),0);// forr invalid paranthisis

//       stack<int>st;
//       for(int i=0;i<s.size();i++)
//       {
//          if(s[i]>='a'&&s[i]<='z')continue;
//         if(s[i]=='(')
//         st.push(i);

//         else
//         {
//             if(!st.empty())
//             st.pop();

//             else
//             vis[i]=1;
//         }
//       }

//       while(!st.empty())
//       {
//             vis[st.top()]=1;
//             st.pop();
//       }

//       string ans="";
//       for(int i=0;i<s.size();i++)
//       {
//           if(vis[i]==0)
//           ans+=s[i];
//       }
//       return ans;
//     }
// };



// <--------------Approach2------------------>

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, close = 0;
        string ans;
        //traverse from start to end 
        for (const char& c : s) {
            if (c != '(' && c != ')') {
                ans += c;
            } else if (c == '(') {
                open++;
                ans += c;
            } else if (open > 0) {
                ans += c;
                open--;
            }
        }

       //traverse from right to left 
        if (open > 0) {
             int n = ans.length();
            s = ans;
            ans = "";
            open = 0, close = 0;
            for (int i = n - 1; i >= 0; i--) {
                char c = s[i];
                if (c != '(' && c != ')') {
                    ans += c;
                } else if (c == ')') {
                    close++;
                    ans += c;
                } else if (close > 0) {
                    ans += c;
                    close--;
                }
            }
        }
        else{
            return ans;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
