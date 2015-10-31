// https://leetcode.com/problems/longest-palindromic-substring/
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
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        size_t a = 0, b = 1;
        for (size_t i = 0; i < s.length(); ++i) {
            size_t range = min(i, s.length() - i - 1);
            for (size_t j = 1; j <= range; ++j) {
                if (s[i - j] != s[i + j]) {
                    break;
                } else if (j * 2 + 1 > b - a) {
                    a = i - j;
                    b = i + j + 1;
                }
            }
        }
        for (size_t i = 0; i < s.length() - 1; ++i) {
            size_t range = min(i + 1, s.length() - i - 1);
            for (size_t j = 0; j < range; ++j) {
                if (s[i - j] != s[i + j + 1]) {
                    break;
                } else if ((j + 1) * 2 > b - a) {
                    a = i - j;
                    b = i + j + 2;
                }
            }
        }
        return s.substr(a, b - a);
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
