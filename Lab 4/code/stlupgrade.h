#ifndef CODE_STLUPGRADE_H
#define CODE_STLUPGRADE_H

#include <iostream>
#include <algorithm>

namespace stl {
#define Type typename std::iterator_traits<Iterator>::value_type

    template<typename Iterator, class UnaryPredicate>
    bool
    all_of(Iterator begin, Iterator end, UnaryPredicate predicate) {

        for (Iterator it = begin; it != end; ++it) {
            if (!predicate(*it))
                return false;
        }
        return true;
    }

    template<typename Iterator, class UnaryPredicate>
    bool
    any_of(Iterator begin, Iterator end, UnaryPredicate predicate) {
        for (Iterator it = begin; it != end; ++it) {
            if (predicate(*it))
                return true;
        }
        return false;
    }

    template<typename Iterator, class UnaryPredicate>
    bool
    none_of(Iterator begin, Iterator end, UnaryPredicate predicate) {
        return !(any_of(begin, end, predicate));
    }

    template<typename Iterator, class UnaryPredicate>
    bool
    one_of(Iterator begin, Iterator end, UnaryPredicate predicate) {
        short counter = 0;
        for (Iterator it = begin; it != end; ++it) {
            if (predicate(*it))
                counter++;
            if (counter == 2) {
                return false;
            }
        }
        return counter == 1;
    }

    template<typename Iterator, class Compare>
    bool
    is_sorted(Iterator begin, Iterator end, Compare comp) {
        if (begin == end)
            return true;
        end--;

        for (Iterator it = begin; it != end;++begin) {
            if (comp(*(++it), *(begin)))
                return false;
        }
        return true;
    }

    template<typename Iterator, class Compare>
    bool
    is_partitioned(Iterator begin, Iterator end, Compare comp) {
        for (; begin != end && comp(*begin); ++begin) {

        }
        while (begin != end) {
            if (comp(*begin)) return false;
            ++begin;
        }
        return true;
    }

    template<typename Iterator, class UnaryPredicate>
    Iterator
    find_if_not(Iterator begin, Iterator end, UnaryPredicate comp) {
        for (; begin != end; ++begin) {
            if (!comp(*begin))
                return begin;
        }
        return end;
    }

    template<typename Iterator>
    Iterator
    find_backward(Iterator begin, Iterator end, Type &_val) {
        Iterator result = end;
        for (; begin != end; ++begin) {
            if (*begin == _val) {
                result = begin;
            }
        }
        return result;
    }

    template<typename Iterator, class Compare>
    bool is_palindrome(Iterator begin, Iterator end, Compare comp) {
        if (begin == end)
            return true;
        --end;
        //size_t size = end - begin + 1;
        for (; begin != end;) { // 1 2 2 1
            if (!comp(*begin, *end))
                return false;
            ++begin;
            if (begin == end)
                return true;
            --end;
        }
        return true;
    }
}
#endif //CODE_STLUPGRADE_H
