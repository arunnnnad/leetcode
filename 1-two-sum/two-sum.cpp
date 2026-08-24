#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexOf;  // value -> index we've seen it at

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            // have we already seen the number that completes the pair?
            if (indexOf.find(need) != indexOf.end()) {
                return {indexOf[need], i};
            }

            // haven't found a match yet, remember this number for later
            indexOf[nums[i]] = i;
        }

        // problem guarantees a solution, so we should never actually get here
        return {};
    }
};