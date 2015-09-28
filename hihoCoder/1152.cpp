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

template <class C>
struct node {
public:
    node(): value_(NULL) {}
    node(const C &v): value_(v) {}
    node(const node &another) {
        *this = another;
    }
    node(node &&another) {
        *this = another;
    }
public:
    void insert(const C *s) {
        ++size_;
        if (*s == '\0') {
            word_ = true;
            return;
        }
        auto result = find(*s);
        auto found = result.first;
        auto index = result.second;
        if (!found) {
            children_.insert(children_.begin() + index, *s);
        }
        children_[index].insert(s + 1);
    }
    const size_t &size() const {
        return size_;
    }
    node *children(const C *s) {
        auto i = s;
        node *n = this;
        while (*s != '\0' && n != nullptr) {
            n = n->children(*s);
            ++s;
        }
        return n;
    }
    node *children(const C &c) {
        auto result = find(c);
        if (result.first) {
            return &children_[find(c).second];
        } else {
            return nullptr;
        }
    }
    void dump(string s = "") {
        if (value_ != NULL) {
            s += value_;
        }
        if (word_) {
            cout << s << endl;
        }
        for (auto &&c : children_) {
            c.dump(s);
        }
    }
private:
    pair<bool, size_t> find(const C &c) const {
        return find(c, 0, children_.size());
    }
    pair<bool, size_t> find(const C &c, const size_t &left, const size_t &right) const {
        if (left == right) {
            return make_pair(false, left);
        }
        auto i = (left + right) / 2;
        auto value = children_[i].value_;
        if (c < value) {
            return find(c, left, i);
        } else if (c > value) {
            return find(c, i + 1, right);
        } else {
            return make_pair(true, i);
        }
    }
public:
    node &operator=(const node &another) {
        value_ = another.value_;
        size_ = another.size_;
        word_ = another.word_;
        children_ = another.children_;
        return *this;
    }
    node &operator=(node &&another) {
        value_ = move(another.value_);
        size_ = move(another.size_);
        word_ = move(another.word_);
        children_ = move(another.children_);
        return *this;
    }
private:
    C value_;
    size_t size_ = 0;
public:
    bool word_ = false;
    vector<node> children_;
};

template <class T, size_t N>
bool contains(const T(&c)[N], const T &e) {
    return any_of(c, c + N, [e](const T &v) {
        return e == v;
    });
}

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("1152.in");
    cin.rdbuf(fin.rdbuf());
#endif
    string s;
    cin >> s;
    size_t l = s.length();
    const size_t sizes[] = {1, 2, 3, 5, 8, 13, 21};
    size_t letters[26];
    node<char> root;
    auto nodcs = [&]() {
        size_t n = 0;
        for (auto &&c : letters) {
            if (c) {
                ++n;
            }
        }
        return n;
    };
    for (size_t i = 1; i <= l; ++i) {
        memset(letters, 0, sizeof(letters));
        for (size_t j = 0; j < i; ++j) {
            ++letters[s[j] - 'a'];
        }
#if MSR_DEBUG
        cout << s.substr(0, i).c_str() << ": " << nodcs() << endl;
#endif
        if (contains(sizes, nodcs())) {
            root.insert(s.substr(0, i).c_str());
        }
        for (size_t j = 1; j <= l - i; ++j) {
            --letters[s[j - 1] - 'a'];
            ++letters[s[j + i - 1] - 'a'];
#if MSR_DEBUG
            cout << s.substr(j, i).c_str() << ": " << nodcs() << endl;
#endif
            if (contains(sizes, nodcs())) {
                root.insert(s.substr(j, i).c_str());
            }
        }
    }
#if MSR_DEBUG
    cout << root.size() << endl;
#endif
    root.dump();
#if MSR_DEBUG
    system("pause");
#endif
    return EXIT_SUCCESS;
}
