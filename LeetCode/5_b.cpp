// https://leetcode.com/problems/longest-palindromic-substring/
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
    string longestPalindrome(string s) {
        const size_t l = s.length();
        if (l == 0) {
            return "";
        }
        const size_t nl = 2 * l + 1;
        s.resize(nl);
        for (size_t i = l; i > 0; --i) {
            s[2 * i - 1] = s[i - 1];
            s[2 * i] = ',';
        }
        s[0] = '[';
        vector<size_t> r(nl, 0);
        size_t id = 0, mx = 0, mr_i = 1;
        for (size_t i = 1; i < nl; ++i) {
            if (i <= mx) {
                r[i] = min(mx - i, r[2 * id - i]);
            }
            while (s[i - r[i] - 1] == s[i + r[i] + 1]) {
                ++r[i];
            }
            if (r[i] + i > mx) {
                id = i;
                mx = r[i] + i;
            }
            if (r[i] > r[mr_i]) {
                mr_i = i;
            }
        }
        const size_t a = mr_i - r[mr_i];
        const size_t b = mr_i + r[mr_i] + 1;
        string ret = "";
        for (size_t i = a; i < b; ++i) {
            if (s[i] != ',') {
                ret += s[i];
            }
        }
        return move(ret);
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("5.in");
    cin.rdbuf(fin.rdbuf());
#endif
    string s;
    cin >> s;
    cout << Solution().longestPalindrome(s) << endl;
    return EXIT_SUCCESS;
}
