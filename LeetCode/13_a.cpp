// https://leetcode.com/problems/roman-to-integer/
// runtime: O(DigitCount), space: O(DigitCount)

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
    int romanToInt(string s) {
        int ret = 0;
        char atom = 0;
        size_t atomCount = 0;
        auto flush = [&ret, &atom, &atomCount] {
            static const map<char, int> atomValue = {
                {0, 0},
                {'I', 1},
                {'X', 10},
                {'C', 100},
                {'M', 1000}
            };
            ret += atomValue.at(atom) * atomCount;
            atom = 0;
            atomCount = 0;
        };
        for (const auto &c : s) {
            if (c == 'I' || c == 'X' || c == 'C' || c == 'M') {
                static const map<char, char> nextAtom = {
                    {'I', 0},
                    {'X', 'I'},
                    {'C', 'X'},
                    {'M', 'C'}
                };
                auto next = nextAtom.at(c);
                if (next && atom == next) {
                    atomCount = 10 - atomCount;
                    flush();
                } else if (atom == c) {
                    ++atomCount;
                } else {
                    flush();
                    atom = c;
                    atomCount = 1;
                }
            } else { // c == 'V' || c == 'L' || c == 'D'
                static const map<char, char> toAtom = {
                    {'V', 'I'},
                    {'L', 'X'},
                    {'D', 'C'}
                };
                auto to = toAtom.at(c);
                if (atom == to) {
                    atomCount = 5 - atomCount;
                } else {
                    flush();
                    atom = to;
                    atomCount = 5;
                }
            }
        }
        flush();
        return ret;
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("13.in");
    cin.rdbuf(fin.rdbuf());
#endif
    string s;
    cin >> s;
    cout << Solution().romanToInt(s) << endl;
    return EXIT_SUCCESS;
}
