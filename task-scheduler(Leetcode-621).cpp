class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count the frequency of each task
        unordered_map<char, int> taskCount;
        for (char task : tasks) {
            taskCount[task]++;
        }
        
        // Sort tasks by frequency in descending order
        vector<int> frequencies;
        for (auto& pair : taskCount) {
            frequencies.push_back(pair.second);
        }
        sort(frequencies.begin(), frequencies.end(), greater<int>());
        
        // Calculate the idle slots required
        int maxFrequency = frequencies[0];
        int idleSlots = (maxFrequency - 1) * n;
        
        // Fill idle slots with other tasks
        for (int i = 1; i < frequencies.size(); ++i) {
            idleSlots -= min(frequencies[i], maxFrequency - 1);
        }
        
        // If idle slots become negative, set them to zero
        idleSlots = max(0, idleSlots);
        
        // Total intervals required is sum of tasks and idle slots
        return tasks.size() + idleSlots;
    }
};
