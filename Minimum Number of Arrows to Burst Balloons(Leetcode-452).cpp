class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // Sort balloons based on their ending points
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int end = points[0][1];

        // Iterate through balloons and count arrows
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > end) { // Current balloon doesn't overlap with previous one
                ++arrows;
                end = points[i][1];
            }
        }

        return arrows;
    }
};
