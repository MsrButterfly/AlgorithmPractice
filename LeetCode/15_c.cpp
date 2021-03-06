// https://leetcode.com/problems/3sum/
// runtime: O(nums.size ^ 2), space: O(nums.size ^ 2)

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
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ret;
        sort(begin(nums), end(nums), less<int>());
        for (size_t i = 0; i < nums.size();) {
            const int a = nums[i];
            size_t j = i + 1, k = nums.size() - 1;
            while (j < k) {
                const int b = nums[j], c = nums[k];
                const int sum = a + b + c;
                if (sum == 0) ret.push_back({a, b, c});
                if (sum <= 0) while (j < k && nums[j] == b) ++j;
                if (sum >= 0) while (j < k && nums[k] == c) --k;
            }
            while (i < nums.size() && nums[i] == a) ++i;
        }
        return move(ret);
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("15.in");
    cin.rdbuf(fin.rdbuf());
#endif
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }
    auto ret = Solution().threeSum(nums);
    for (const auto &v : ret) {
        copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return EXIT_SUCCESS;
}
