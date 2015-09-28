// http://hihocoder.com/problemset/problem/1061
// http://hihocoder.com/contest/hiho58/problem/1

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

struct block {
    char c = '\0';
    size_t count = 0;
};

int main(int argc, const char *argv[]) {
    size_t t;
#if MSR_DEBUG
    freopen("1061.in", "r", stdin);
#endif
    scanf("%zd", &t);
    while (t--) {
        size_t n;
        scanf("%zd", &n);
        getchar();
        vector<block> bs;
        block b;
        char c1 = '\0';
        for (size_t i = 0; i < n; ++i) {
            char c2 = getchar();
            if (i == 0) {
                b.c = c2;
                b.count = 1;
            } else if (c1 != c2) {
                bs.push_back(b);
                b.c = c2;
                b.count = 1;
            } else {
                ++b.count;
            }
            c1 = c2;
        }
        bs.push_back(b);
        getchar();
#if MSR_DEBUG
        for (auto &&b : bs) {
            cout << b.c << ": " << b.count << endl;
        }
#endif
        bool found = false;
        if (bs.size() >= 3) {
            for (size_t i = 0; i < bs.size() - 2; ++i) {
                auto &&a = bs[i];
                auto &&b = bs[i + 1];
                auto &&c = bs[i + 2];
                if (b.c - a.c == 1 && c.c - b.c == 1 && a.count >= b.count && b.count <= c.count) {
                    found = true;
                    break;
                }
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }
    return EXIT_SUCCESS;
}