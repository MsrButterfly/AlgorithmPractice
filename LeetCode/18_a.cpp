// https://leetcode.com/problems/4sum/
// runtime: O(nums.size ^ 3), space: O(nums.size ^ 3)

#include <cassert>
#include <cstdint>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <memory>
#include <numeric>
#include <random>
#include <regex>
#include <string>
#include <tuple>
#include <typeindex>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
		vector<vector<int>> ret;
        if (nums.size() < 4) {
            return move(ret);
        }
        sort(begin(nums), end(nums), less<int>());
        for (size_t i = 0; i < nums.size();) {
            const int a = nums[i];
            for (size_t j = i + 1; j < nums.size();) {
                const int b = nums[j];
                size_t k = j + 1, l = nums.size() - 1;
                while (k < l) {
                    const int c = nums[k], d = nums[l];
                    const int diff = a + b + c + d - target;
                    if (diff == 0) ret.push_back({a, b, c, d});
                    if (diff <= 0) while (k < l && nums[k] == c) ++k;
                    if (diff >= 0) while (k < l && nums[l] == d) --l;
                }
                while (j < nums.size() && nums[j] == b) ++j;
            }
            while (i < nums.size() && nums[i] == a) ++i;
        }
        return move(ret);
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("18.in");
    cin.rdbuf(fin.rdbuf());
#endif
    vector<int> nums;
    size_t size;
    int num, target;
    cin >> size >> target;
    for (size_t i = 0; i < size; ++i) {
        cin >> num;
        nums.push_back(num);
    }
    auto ret = Solution().fourSum(nums, target);
    for (const auto &v : ret) {
        copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return EXIT_SUCCESS;
}
