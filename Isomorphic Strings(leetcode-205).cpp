class Solution {
public:
bool isomorophic(string s1,string s2)
{   vector<int> a1(128,-1);
    vector<int> a2(128,-1);
   if(s1.size()!=s2.size())
   return false;
  
  for(int i=0;i<s1.size();i++)
  {
     if(a1[s1[i]]!=a2[s2[i]])
    return false;
  
    a1[s1[i]]=i;
    a2[s2[i]]=i;
  }
   return true;
  }
    bool isIsomorphic(string s, string t) {
        if(isomorophic(s,t))
    return true;
    else
     return false;
    }
};
