// https://leetcode.com/problems/regular-expression-matching/
// runtime: O(main ^ pattern)?, space: O(pattern)

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
    bool isMatch(string s, string p) {
        return RegularExpression::construct(p).matches(s);
    }
private:
    class RegularExpression {
    private:
        struct Element {
            struct Status {
                Status(const bool matched, const char *p): matched(matched), p(p) {}
                static const Status Failed() {
                    return Status(false, nullptr);
                }
                bool matched = false;
                const char *p = nullptr;
            };
            using Ptr = shared_ptr<Element>;
            virtual Status matches(const char *s) = 0;
            Ptr next;
        };
        struct Atom: Element {
            Atom(const char &c): c(c) {}
            virtual Status matches(const char *s) {
#if MSR_DEBUG
                cout << "Matching Atom(" << c << ") with " << *s << endl;
#endif
                if (*s == c) {
                    return next ? next->matches(s + 1) : Status(true, s + 1);
                }
                return Status::Failed();
            }
            char c; // c != '\0'
        };
        struct AnyAtom: Element {
            AnyAtom() {}
            virtual Status matches(const char *s) {
#if MSR_DEBUG
                cout << "Matching AnyAtom with " << *s << endl;
#endif
                if (*s != '\0') {
                    return next ? next->matches(s + 1) : Status(true, s + 1);
                }
                return Status::Failed();
            }
        };
        struct Sequence: Element {
            Sequence() {}
            virtual Status matches(const char *s) {
#if MSR_DEBUG
                cout << "Matching Sequence with " << *s << endl;
#endif
                auto status = next ? next->matches(s) : Status(true, s);
                if (status.matched) {
                    return status;
                }
                for (auto p = s; p != '\0';) {
                    status = element->matches(p);
                    if (status.matched) {
                        p = status.p;
                        status = next ? next->matches(p) : Status(true, p);
                        if (status.matched) {
                            return status;
                        }
                    } else {
                        break;
                    }
                }
                return Status::Failed();
            }
            Ptr element;
        };
        struct Begin: Element {
            Begin() {}
            virtual Status matches(const char *s) {
#if MSR_DEBUG
                cout << "Matching Begin with " << *s << endl;
#endif
                return next->matches(s);
            }
        };
        struct End: Element {
            End() {}
            virtual Status matches(const char *s) {
#if MSR_DEBUG
                cout << "Matching End with " << *s << endl;
#endif
                auto matched = *s == '\0';
                return Status(matched, matched ? s : nullptr);
            }
        };
    public:
        RegularExpression(Element::Ptr e): e(e) {}
        static RegularExpression construct(const string &s) {
            auto p = s.c_str();
            return construct(p);
        }
    private:
        static RegularExpression construct(const char *&p) {
            auto head = make_shared<Begin>();
            Element::Ptr previous = head; // before head
            Element::Ptr current = head;
            for (; *p != '\0'; ++p) {
                const auto &c = *p;
                if (c == '*') {
                    auto elem = current;
                    auto seq = make_shared<Sequence>();
                    seq->element = elem;
                    current = seq;
                } else {
                    if (previous != current) {
                        previous->next = current;
                        previous = current;
                    }
                    if (c == '.') {
                        current = make_shared<AnyAtom>();
                    } else {
                        current = make_shared<Atom>(c);
                    }
                }
            }
            if (previous != current) {
                previous->next = current;
            }
            current->next = make_shared<End>();
            return RegularExpression(head);
        }
    public:
        bool matches(const string &s) {
            return e->matches(s.c_str()).matched;
        }
        Element::Ptr e;
    };
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("10.in");
    cin.rdbuf(fin.rdbuf());
#endif
    string s, p;
    while (cin >> s >> p) {
        cout << boolalpha << Solution().isMatch(s, p) << endl;
    }
    return EXIT_SUCCESS;
}
