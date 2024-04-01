class Solution {
public:
    int lengthOfLastWord(string s) {
 
vector<string>v;
string temp="";
for(int i=0;i<s.size();i++)
{
    if(s[i]!=' ')temp+=s[i];

    else
    { if(temp!="") v.push_back(temp);
        temp="";
    }
}
if(temp!="") v.push_back(temp);

return v.back().size();

    }
};
