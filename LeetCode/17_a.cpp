// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// runtime: O(max(digitsChars.size) ^ digits.length)
// space: O(max(digitsChars.size) ^ digits.length)

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

class Solution {
public:
    vector<string> letterCombinations(const string &digits) {
        auto it = find_if(begin(digits), end(digits),
            [](const char &c) { return c < '2' || c > '9'; });
        if (digits.length() == 0 || it != end(digits)) {
            return vector<string>();
        }
        vector<string> ret;
        string s;
        s.push_back(digitChars[digits[0] - '0'][0]);
        bool after_pop = false;
        while (s.length() > 0) {
            if (!after_pop && s.length() == digits.length()) {
                ret.push_back(s);
                while (s.length() > 0 && s.back() == digitChars[digits[s.length() - 1] - '0'].back()) {
                    s.pop_back();
                }
                after_pop = true;
                continue;
            }
            const auto c = s.back();
            if (after_pop) {
                s.pop_back();
                s.push_back(c + 1);
                after_pop = false;
            } else {
                s.push_back(digitChars[digits[s.length()] - '0'].front());
            }
        }
        return move(ret);
    }
private:
    static const string digitChars[10];
};

const string Solution::digitChars[10] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("17.in");
    cin.rdbuf(fin.rdbuf());
#endif
    string digits;
    cin >> digits;
    auto ret = Solution().letterCombinations(digits);
    for (const auto &s : ret) {
        cout << s << endl;
    }
    return EXIT_SUCCESS;
}
