// https://leetcode.com/problems/string-to-integer-atoi/
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
private:
    enum Status {
        LeadingWhitespaces,
        Sign,
        NumericalDigits,
        TrailingCharactors
    };
public:
    int myAtoi(const string &str) {
        bool isSigned = false;
        int ret = 0;
        Status status = LeadingWhitespaces;
        for (size_t i = 0; i < str.length();) {
            const auto &c = str[i];
            switch (status) {
                case LeadingWhitespaces:
                    if (!isWhitespace(c)) {
                        status = Sign;
                        continue;
                    }
                    ++i;
                    continue;
                case Sign:
                    if (isSign(c)) {
                        isSigned = c == '-';
                        ++i;
                    }
                    status = NumericalDigits;
                    continue;
                case NumericalDigits: {
                    if (!isDigit(c)) {
                        status = TrailingCharactors;
                        continue;
                    }
                    ++i;
                    int n = c - '0';
                    if (isSigned) {
                        if ((INT_MIN + n) / 10 > ret) {
                            return INT_MIN;
                        }
                        ret = ret * 10 - n;
                    } else {
                        if ((INT_MAX - n) / 10 < ret) {
                            return INT_MAX;
                        }
                        ret = ret * 10 + n;
                    }
                    continue;
                }
                case TrailingCharactors:
                    return ret;
                default:
                    assert(false);
            }
        }
        return ret;
    }
    static inline bool isDigit(const char &c) {
        return c >= '0' && c <= '9';
    }
    static inline bool isSign(const char &c) {
        return c == '+' || c == '-';
    }
    static inline bool isWhitespace(const char &c) {
        return c == ' ' || c == '\t';
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("8.in");
    cin.rdbuf(fin.rdbuf());
#endif
    string str;
    getline(cin, str);
    cout << Solution().myAtoi(str) << endl;
    return EXIT_SUCCESS;
}
