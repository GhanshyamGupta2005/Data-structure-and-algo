class Solution {
public:
    bool isPalindrome(int x) {
        
    //     string s=to_string(x);
    
    // for(int i=0,j=s.size()-1;i<=j;i++,j--)
    // {
    //     if(s[i]!=s[j])
    //     {
    //         return false;
    //     }
    // }
    //      return true;
    // }


long long y=0;
long long z=x;

while(x>0)
{
y=y*10+x%10;
x/=10;
}
return (y==z)?true:false;}
};
