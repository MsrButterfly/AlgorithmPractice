// https://leetcode.com/problems/integer-to-roman/
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
    string intToRoman(int num) {
        string ss[4];
        for (size_t i = 0; i < 4; ++i) {
            const int n = num % 10;
            string &s = ss[3 - i];
            num /= 10;
            if (n >= 9) {
                s = string(10 - n, atom[i]) + atom[i + 1];
            } else if (n >= 6) {
                s = half[i] + string(n - 5, atom[i]);
            } else if (n >= 4) {
                s = string(5 - n, atom[i]) + half[i];
            } else {
                s = string(n, atom[i]);
            }
        }
        string ret = "";
        for (const auto &s : ss) {
            ret += s;
        }
        return ret;
    }
private:
    static const char atom[4];
    static const char half[4];
};

const char Solution::atom[4] = {'I', 'X', 'C', 'M'};
const char Solution::half[4] = {'V', 'L', 'D', '?'};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("12.in");
    cin.rdbuf(fin.rdbuf());
#endif
    int num;
    cin >> num;
    cout << Solution().intToRoman(num) << endl;
    return EXIT_SUCCESS;
}
