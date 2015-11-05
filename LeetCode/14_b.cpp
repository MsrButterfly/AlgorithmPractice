// https://leetcode.com/problems/longest-common-prefix/
// runtime: O(min(L) * N), space: O(1)

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
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        size_t i;
        bool shouldBreak = false;
        for (i = 0; ; ++i) {
            if (i >= strs[0].length()) {
                break;
            }
            for (size_t j = 0; j < strs.size(); ++j) {
                const auto &s = strs[j];
                if (i >= s.length() || s[i] != strs[0][i]) {
                    shouldBreak = true;
                    break;
                }
            }
            if (shouldBreak) {
                break;
            }
        }
        return strs[0].substr(0, i);
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("14.in");
    cin.rdbuf(fin.rdbuf());
#endif
    vector<string> ss;
    string s;
    while (cin >> s) {
        ss.push_back(s);
    }
    cout << Solution().longestCommonPrefix(ss) << endl;
    return EXIT_SUCCESS;
}
