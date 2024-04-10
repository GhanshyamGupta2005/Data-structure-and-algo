class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());

        queue<int>q;
        q.push(deck[deck.size()-1]);
        
        for(int i=deck.size()-2;i>=0;i--)
        {
                if(q.size()==1&&q.size()==2)
                q.push(deck[i]);

                else
                {
                    int x=q.front();
                    q.pop();
                    q.push(x);
                    q.push(deck[i]);
                }


        }

        vector<int>v;
        while(!q.empty())
        {
            v.push_back(q.front());
            q.pop();
        }
reverse(v.begin(),v.end());
        return v;
    }
};
