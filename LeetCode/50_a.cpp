// https://leetcode.com/problems/powx-n/
// runtime: O(log(n)), space: O(1)

#include <array>
#include <bitset>
#include <cassert>
#include <cstdint>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1.0 / x; // x: 0 => inf
            n = -n;
        }
        const bitset<numeric_limits<int>::digits> bits(n);
        double ret = 1;
        double mul = x;
        for (size_t i = 0; i < bits.size(); ++i) {
            if (bits[i]) {
                ret *= mul;
            }
            mul *= mul;
        }
        return ret;
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("50.in");
    cin.rdbuf(fin.rdbuf());
#endif
    double x;
    int n;
    cin >> x >> n;
    cout << Solution().myPow(x, n) << endl;
    return EXIT_SUCCESS;
}
