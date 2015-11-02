// https://leetcode.com/problems/palindrome-number/
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
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        size_t size = digitSize(x);
        for (size_t i = 0, j = size - 1; i < j; ++i, --j) {
            if (digitAt(x, i) != digitAt(x, j)) {
                return false;
            }
        }
        return true;
    }
private:
    static int digitAt(int num, size_t i) {
        int pow = 1;
        while (i--) {
            pow *= 10;
        }
        return (num / pow) % 10;
    }
    static size_t digitSize(int num) {
        if (num == 0) {
            return 1;
        }
        size_t size = 0;
        while (num) {
            ++size;
            num /= 10;
        }
        return size;
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("9.in");
    cin.rdbuf(fin.rdbuf());
#endif
    int n;
    cin >> n;
    cout << boolalpha << Solution().isPalindrome(n) << endl;
    return EXIT_SUCCESS;
}
