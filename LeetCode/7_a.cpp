// https://leetcode.com/problems/reverse-integer/
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
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }
        bool signed_ = x < 0;
        x = abs(x);
        int ret = 0;
        while (x) {
            int c = x % 10;
            x /= 10;
            if ((INT_MAX - c) / 10 < ret) {
                return 0;
            }
            ret = ret * 10 + c;
        }
        return signed_ ? -ret : ret;
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("7.in");
    cin.rdbuf(fin.rdbuf());
#endif
    int x;
    cin >> x;
    cout << Solution().reverse(x) << endl;
    return EXIT_SUCCESS;
}
