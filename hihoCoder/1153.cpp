// http://hihocoder.com/problemset/problem/1153
// http://hihocoder.com/contest/mstest2015april2/problem/2

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

bool rls[10][10] = {
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
};

char num[501] = "";

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    freopen("1153.in", "r", stdin);
#endif
    size_t t = 0;
    scanf("%zd", &t);
    while (t--) {
        scanf("%s", num);
        size_t l = strlen(num);
        for (size_t i = 1; i < l; ++i) {
            bool changed = false;
            while (!rls[num[i - 1] - '0'][num[i] - '0']) {
                changed = true;
                while (num[i] == '0') {
                    num[i] = '9';
                    --i;
                }
                --num[i];
                if (i == 0) {
                    break;
                }
            }
            if (changed) {
                for (size_t j = i + 1; j < l; ++j) {
                    num[j] = '9';
                }
            }
        }
        printf("%s\n", num);
    }
    return EXIT_SUCCESS;
}