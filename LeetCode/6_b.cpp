// https://leetcode.com/problems/zigzag-conversion/
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
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return move(s);
        }
        const size_t cycle = numRows * 2 - 2;
        const size_t len = s.length();
        string ret = "";
        for (size_t i = 0; i < len; i += cycle) {
            ret += s[i];
        }
        for (size_t i = 1; i < numRows - 1; ++i) {
            size_t j = i, k = cycle - i;
            for (; k < len; j += cycle, k += cycle) {
                ret += s[j];
                ret += s[k];
            }
            if (j < len) {
                ret += s[j];
            }
        }
        for (size_t i = numRows - 1; i < len; i += cycle) {
            ret += s[i];
        }
        return move(ret);
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("6.in");
    cin.rdbuf(fin.rdbuf());
#endif
    string s;
    int numRows;
    cin >> s >> numRows;
    cout << Solution().convert(s, numRows) << endl;
    return EXIT_SUCCESS;
}
