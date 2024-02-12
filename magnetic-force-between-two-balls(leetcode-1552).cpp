
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int low = 1, high = position[position.size() - 1] - position[0];
    int result ;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int placed = 1;
        int lastPlaced = position[0];

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPlaced >= mid) {
                placed++;
                lastPlaced = position[i];
                if (placed >= m) {
                    result = mid;
                    low = mid + 1;
                    break; // Break from the loop as we've found a possible solution
                }
            }
        }

        if (placed < m) {
            high = mid - 1;
        }
    }

    return result;
}

};
