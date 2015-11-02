// https://leetcode.com/problems/zigzag-conversion/
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
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return move(s);
        }
        vector<string> ss(numRows, "");
        bool up = true;
        for (size_t i = 0, j = 0; i < s.length(); ++i) {
            ss[j] += s[i];
            up ? ++j : --j;
            if (j == 0) {
                up = true;
            }
            if (j == numRows - 1) {
                up = false;
            }
        }
        string ret = "";
        for (const auto &e : ss) {
            ret += e;
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
