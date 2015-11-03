// https://leetcode.com/problems/container-with-most-water/
// runtime: O(n), space: O(1)

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
#include <utility>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxValue = 0;
        size_t i = 0, j = height.size() - 1;
        while (i < j) {
            int a = height[i];
            int b = height[j];
            int value = (int)(j - i) * min(a, b);
            if (value > maxValue) {
                maxValue = value;
            }
            a < b ? ++i : --j;
        }
        return maxValue;
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("11.in");
    cin.rdbuf(fin.rdbuf());
#endif
    vector<int> heights;
    int height;
    while (cin >> height) {
        heights.push_back(height);
    }
    cout << Solution().maxArea(heights) << endl;
    return EXIT_SUCCESS;
}
