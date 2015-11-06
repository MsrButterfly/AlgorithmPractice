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

struct tuple_hash {
    using argument_type = tuple<int, int, int>;
    using result_type = size_t;
    result_type operator()(const argument_type &key) const {
        size_t a = get<0>(key);
        size_t b = get<1>(key);
        size_t c = get<2>(key);
        a <<= 16;
        b <<= 8;
        return a + b + c;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.size() < 3) {
            return vector<vector<int>>();
        }
        sort(begin(nums), end(nums), less<int>());
        unordered_set<tuple<int, int, int>, tuple_hash> retSet;
        for (size_t i = 1; i < nums.size() - 1; ++i) {
            if (i > 1 && nums[i - 1] == nums[i]) {
                continue;
            }
            size_t j = 0, k = nums.size() - 1;
            while (j < k) {
                auto a = nums[i];
                auto b = nums[j];
                auto c = nums[k];
                if (a + b + c == 0) {
                    if (a > b) {
                        swap(a, b);
                    }
                    if (a > c) {
                        swap(a, c);
                    }
                    if (b > c) {
                        swap(b, c);
                    }
                    retSet.insert(make_tuple(a, b, c));
                    ++j;
                    if (i == j) {
                        ++j;
                    }
                } else if (a + b + c < 0) {
                    ++j;
                    if (i == j) {
                        ++j;
                    }
                } else {
                    --k;
                    if (i == k) {
                        --k;
                    }
                }
            }
        }
        vector<vector<int>> ret;
        for (const auto &t : retSet) {
            ret.push_back({get<0>(t), get<1>(t), get<2>(t)});
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
