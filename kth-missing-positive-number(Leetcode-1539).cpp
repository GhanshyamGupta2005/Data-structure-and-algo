class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //o(n)
        int n = arr.size();
        int j = 1;
        int i = 0;
        while (k > 0) {
            if (i < n && arr[i] == j) {
                i++;
            } 
            else {
                k--;
            }
            j++;
        }
        return j - 1;
    }
};
