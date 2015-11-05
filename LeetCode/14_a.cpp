// https://leetcode.com/problems/longest-common-prefix/
// runtime: O(L * N), space: O(L)

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
        string ret = strs[0];
        for (size_t i = 1; i < strs.size(); ++i) {
            const auto &s = strs[i];
            size_t j = 0;
            for (; j < min(ret.length(), s.length()); ++j) {
                if (ret[j] != s[j]) {
                    break;
                }
            }
            if (j < ret.length()) {
                ret.resize(j);
            }
        }
        return ret;
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
