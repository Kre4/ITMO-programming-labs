#ifndef CODE_CB_ITERATOR_H
#define CODE_CB_ITERATOR_H

#include <cstdio>
#include <iterator>
#define ra_iterator random_access_iterator
namespace cbuf {
    template<typename Tp_>
    class random_access_iterator : std::iterator<std::random_access_iterator_tag, Tp_> {
    protected:
        Tp_ *ptr_;
//        size_t pos_ = 0;
//        size_t capacity_ = 0;
        //typedef typename ra_iterator::difference_type difference_type;

    public:
        typedef typename ra_iterator::difference_type difference_type;
        using value_type = Tp_;
        using pointer = Tp_*;
        using reference = Tp_&;
        using iterator_category = std::random_access_iterator_tag;
        random_access_iterator() : ptr_(nullptr) {}

        explicit random_access_iterator(Tp_ *ptr) : ptr_(ptr) {}

        explicit random_access_iterator(const ra_iterator *_iterator) : ptr_(_iterator->ptr_) {}


        Tp_ &operator[](difference_type _n) const noexcept {
            return *(ptr_ + _n);
        }

        ra_iterator &operator+=(difference_type _n) noexcept {
            ptr_ += _n;
            return *this;
        }

        ra_iterator &operator-=(difference_type _n) noexcept {

            return ptr_ += -_n;
        }

        ra_iterator operator+(difference_type _n) const noexcept {
            return ra_iterator(ptr_ + _n);
        }

        ra_iterator operator-(difference_type _n) const noexcept {
            return ra_iterator(ptr_ - _n);
        }
        int operator-(ra_iterator _iter)const noexcept{
            return ptr_ - _iter.ptr_;
        }

        ra_iterator &operator++() noexcept {
            ++ptr_;
            return *this;
        }

        ra_iterator operator++(int) noexcept {
            return ra_iterator(ptr_++);
        }

        ra_iterator &operator--() noexcept {
            --ptr_;
            return *this;
        }

        ra_iterator operator--(int) noexcept {
            return ra_iterator(ptr_--);
        }

        Tp_ &operator*() {
            return *ptr_;
        }

        Tp_ *operator->() {
            return ptr_;
        }


        inline bool operator==(const ra_iterator &_iteratorR) noexcept {
            return ptr_ == _iteratorR.ptr_;
        }

        inline bool operator!=(const ra_iterator &_iteratorR) noexcept {
            return ptr_ != _iteratorR.ptr_;
        }

        inline bool operator<(const ra_iterator &_iteratorR) noexcept {
            return ptr_ < _iteratorR.ptr_;
        }

        inline bool operator<=(const ra_iterator &_iteratorR) noexcept {
            return ptr_ <= _iteratorR.ptr_;
        }

        inline bool operator>(const ra_iterator &_iteratorR) noexcept {
            return ptr_ > _iteratorR.ptr_;
        }

        inline bool operator>=(const ra_iterator &_iteratorR) noexcept {
            return ptr_ >= _iteratorR.ptr_;
        }
        random_access_iterator& operator=(const ra_iterator &_other){
            if (_other.ptr_ == ptr_)
                return *this;
            ptr_ = _other.ptr_;
            return *this;
        }

    };
/*
    TODO list
    operator+=
    operator-=
    operator*
    operator->
    operator[]
    operator++
    operator--
    operator++(T)
    operator--(T)
    operator==
    operator!=
    operator>
    operator<
    operator>=
    operator<=
    operator+
    operator-
     */
};
#endif //CODE_CB_ITERATOR_H