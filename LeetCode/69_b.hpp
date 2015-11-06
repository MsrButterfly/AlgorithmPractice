// https://leetcode.com/problems/sqrtx/
// runtime: O(log(x)), space: O(1)

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
private:
    using ull = unsigned long long;
public:
    int mySqrt(int x) {
        if (x < 0) {
            return INT_MIN;
        }
        const ull target = x;
        ull ret = (target >> 1) + 1;
        while (ret * ret > target) {
            ret = (ret + target / ret) >> 1;
        }
        return (int)ret;
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("69.in");
    cin.rdbuf(fin.rdbuf());
#endif
    int x;
    cin >> x;
    cout << Solution().mySqrt(x) << endl;
    return EXIT_SUCCESS;
}
