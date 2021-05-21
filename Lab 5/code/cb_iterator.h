#ifndef CODE_CB_ITERATOR_H
#define CODE_CB_ITERATOR_H

#include <cstdio>
#include <iterator>

#define ra_iterator random_access_iterator
namespace cbuf {
    template<typename Tp_>
    class random_access_iterator : std::iterator<std::random_access_iterator_tag, Tp_> {
    public:
        Tp_ *ptr_;
        Tp_ *first_;
        size_t capacity_;

    public:
        typedef typename ra_iterator::difference_type difference_type;
        using value_type = Tp_;
        using pointer = Tp_ *;
        using reference = Tp_ &;
        using iterator_category = std::random_access_iterator_tag;

        random_access_iterator() : ptr_(nullptr), first_(nullptr), capacity_(0) {}

        explicit random_access_iterator(Tp_ *ptr, Tp_ *first, size_t capacity) : ptr_(ptr),
                                                                                 first_(first),
                                                                                 capacity_(capacity) {}

        random_access_iterator(const ra_iterator *_iterator) : ptr_(_iterator->ptr_),
                                                               first_(_iterator->first_),
                                                               capacity_(_iterator->capacity_) {}

        random_access_iterator(Tp_ *ptr):ptr_(ptr), first_(ptr_),capacity_(0) {}


        Tp_ &operator[](difference_type _n) const noexcept {
            _n %= capacity_;
            int from_first_to_current = ptr_ - first_ + 1;
            if (from_first_to_current + _n > capacity_) {
                return *(ptr_ - _n);
            }
            return *(ptr_ + _n);
        }

        ra_iterator &operator+=(difference_type _n) noexcept {
            if (_n < 0)
                operator-=(-_n);
            _n %= capacity_;
            int from_first_to_current = ptr_ - first_ + 1;
            if (ptr_ + _n >= first_ + capacity_) {
//                _n -= capacity_ - from_first_to_current;
//                ptr_ = first_ + _n - 1;
                ptr_ -= capacity_ - _n;
                return ptr_;
            }
            ptr_ += _n;
            return *this;
        }

        ra_iterator &operator-=(difference_type _n) noexcept {
            _n %= capacity_;
            if (ptr_ - _n <= first_) {
                return ptr_+= capacity_ - _n;
            }
            return ptr_ -= _n;
        }

        ra_iterator operator+(difference_type n_) const noexcept {
            difference_type _n = n_;
            _n%=capacity_;
            if (ptr_ + _n >= first_ + capacity_) {

                return ra_iterator(ptr_ - (capacity_ - _n), first_, capacity_);
            }

            return ra_iterator(ptr_ + n_, first_, capacity_);
        }

        ra_iterator operator-(difference_type n_) const noexcept {
            difference_type _n = n_;
            _n%=capacity_;
            if (ptr_ - _n <= first_) {
                //ptr_+= (capacity_ - _n);
                return ra_iterator(ptr_ + capacity_ - _n,first_, capacity_);
            }

            return ra_iterator(ptr_-_n,first_, capacity_);
        }
        difference_type operator-(ra_iterator& iterator)const noexcept{
            difference_type _n = ptr_ - iterator.ptr_;
            if (_n < 0){
                _n = -_n+ 1;
                return capacity_ - _n;
            }
            return _n;
        }

        ra_iterator &operator++() noexcept {
            if (ptr_ == first_ + capacity_ - 1) {
                ptr_ = first_;
            } else
                ++ptr_;
            return *this;
        }

        ra_iterator operator++(int) noexcept {
            if (ptr_ == first_ + capacity_ - 1) {
                ptr_ = first_;
                return ra_iterator(ptr_, first_, capacity_);
            }
            return ra_iterator(ptr_++, first_, capacity_);
        }

        ra_iterator &operator--() noexcept {
            if (ptr_ == first_) {
                ptr_ += capacity_ - 1;
            } else {
                --ptr_;
            }
            return *this;
        }

        ra_iterator operator--(int) noexcept {
            if (ptr_ == first_) {
                ptr_ += capacity_ - 1;
            } else {

            }
            return ra_iterator(ptr_--, first_, capacity_);
        }

        Tp_ &operator*() {
            return *ptr_;
        }

        Tp_ *operator->() {
            return ptr_;
        }


        inline bool operator==(const ra_iterator &_iteratorR) noexcept {
            return ptr_ == _iteratorR.ptr_ && first_ == _iteratorR.first_ && capacity_ == _iteratorR.capacity_;
        }

        inline bool operator!=(const ra_iterator &_iteratorR) noexcept {
            return !(*this == _iteratorR);
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

        random_access_iterator &operator=(const ra_iterator &_other) {
            if (_other.ptr_ == ptr_)
                return *this;
            ptr_ = _other.ptr_;
            first_ = _other.first_;
            capacity_ = _other.capacity_;
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