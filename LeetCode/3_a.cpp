// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// runtime: O(n), space: O(n)

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
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        v = vector<size_t>(256, 0);
        ++v[s[0]];
        size_t i = 0, j = 1;
        while (j < s.length()) {
            ++v[s[j]];
            if (any_of(begin(v), end(v),
                [](const size_t &e) {
                return e > 1;
            })) {
                --v[s[i]];
                ++i;
            }
            ++j;
        }
        return j - i;
    }
    vector<size_t> v;
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("3.in");
    cin.rdbuf(fin.rdbuf());
#endif
    string s;
    cin >> s;
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return EXIT_SUCCESS;
}
