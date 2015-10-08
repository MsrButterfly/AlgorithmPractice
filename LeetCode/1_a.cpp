// https://leetcode.com/problems/two-sum/
// runtime: O(nlog(n)), space: O(n)

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
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        ids.resize(nums.size());
        ids_buffer.resize(nums.size());
        buffer.resize(nums.size());
        for (int i = 0; i < (int)nums.size(); ++i) {
            ids[i] = i + 1;
        }
        sort(nums, 0, nums.size());
        int i = 0, j = nums.size() - 1;
        while (true) {
            auto sub = nums[i] + nums[j] - target;
            if (sub == 0) {
                break;
            } else if (sub > 0) {
                --j;
            } else {
                ++i;
            }
        }
        auto a = ids[i];
        auto b = ids[j];
        if (a > b) {
            swap(a, b);
        }
        return {a, b};
    }
    vector<int> ids;
    vector<int> buffer;
    vector<int> ids_buffer;
    void sort(vector<int> &vec, int begin, int end) {
        if (end - begin <= 1) return;
        auto mid = (begin + end) / 2;
        sort(vec, begin, mid);
        sort(vec, mid, end);
        for (int a = begin, b = mid, i = begin; a < mid || b < end; ++i) {
            if (a == mid) {
                buffer[i] = vec[b];
                ids_buffer[i] = ids[b];
                ++b;
            } else if (b == end) {
                buffer[i] = vec[a];
                ids_buffer[i] = ids[a];
                ++a;
            } else if (vec[a] < vec[b]) {
                buffer[i] = vec[a];
                ids_buffer[i] = ids[a];
                ++a;
            } else {
                buffer[i] = vec[b];
                ids_buffer[i] = ids[b];
                ++b;
            }
        }
        for (int i = begin; i < end; ++i) {
            vec[i] = buffer[i];
            ids[i] = ids_buffer[i];
        }
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("1.in");
    cin.rdbuf(fin.rdbuf());
#endif
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        nums.push_back(c);
    }
    int target;
    cin >> target;
    auto result = Solution().twoSum(nums, target);
    cout << result[0] << ' ' << result[1] << endl;
    return EXIT_SUCCESS;
}
