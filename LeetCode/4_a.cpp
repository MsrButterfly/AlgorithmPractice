// https://leetcode.com/problems/median-of-two-sorted-arrays/
// runtime: O(n), space: O(1)

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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        auto size = nums1.size() + nums2.size();
        auto mid = size / 2 + 1;
        double pre = 0, cur = 0;
        for (size_t i = 0, j = 0, c = 0; c < mid; ++c) {
            pre = cur;
            if (i == nums1.size()) {
                cur = (double)nums2[j];
                ++j;
            } else if (j == nums2.size()) {
                cur = (double)nums1[i];
                ++i;
            } else if (nums1[i] < nums2[j]) {
                cur = (double)nums1[i];
                ++i;
            } else {
                cur = (double)nums2[j];;
                ++j;
            }
        }
        return size % 2 == 0 ? (pre + cur) / 2.0 : cur;
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("4.in");
    cin.rdbuf(fin.rdbuf());
#endif
    vector<int> nums1, nums2;
    size_t n;
    cin >> n;
    nums1.resize(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> nums1[i];
    }
    cin >> n;
    nums2.resize(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> nums2[i];
    }
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    return EXIT_SUCCESS;
}
