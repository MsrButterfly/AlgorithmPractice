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
        size_t v[256];
        size_t v_count = 0;
        memset(v, 0, sizeof(v));
        ++v[s[0]];
        size_t i = 0, j = 1;
        while (j < s.length()) {
            ++v[s[j]];
            if (v[s[j]] == 2) {
                ++v_count;
            }
            if (v_count) {
                --v[s[i]];
                if (v[s[i]] == 1) {
                    --v_count;
                }
                ++i;
            }
            ++j;
        }
        return j - i;
    }
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
