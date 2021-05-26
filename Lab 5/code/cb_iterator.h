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
        //add begin
        Tp_ *head_;
        Tp_ *first_ = nullptr;

        size_t capacity_;

    public:
        typedef typename ra_iterator::difference_type difference_type;
        using value_type = Tp_;
        using pointer = Tp_ *;
        using reference = Tp_ &;
        using iterator_category = std::random_access_iterator_tag;

        random_access_iterator() : ptr_(nullptr), head_(nullptr), capacity_(1), first_(nullptr) {}

        explicit random_access_iterator(Tp_ *ptr, Tp_ *head, size_t capacity, Tp_ *first) : ptr_(ptr),
                                                                                            head_(head),
                                                                                            capacity_(capacity + 1),
                                                                                            first_(first) {}

        random_access_iterator(const ra_iterator *_iterator) : ptr_(_iterator->ptr_),
                                                               head_(_iterator->head_),
                                                               capacity_(_iterator->capacity_),
                                                               first_(first_) {}

        //random_access_iterator(Tp_ *ptr): ptr_(ptr), head_(ptr_), capacity_(0) {}


        Tp_ &operator[](difference_type _n) const noexcept {
            _n %= capacity_;
            int from_first_to_current = ptr_ - head_ + 1;
            if (from_first_to_current + _n > capacity_) {
                return *(ptr_ - _n);
            }
            return *(ptr_ + _n);
        }

        ra_iterator &operator+=(difference_type _n) noexcept {
            if (_n < 0)
                operator-=(-_n);
            _n %= capacity_;
            int from_first_to_current = ptr_ - head_ + 1;
            if (ptr_ + _n >= head_ + capacity_) {
//                _n -= capacity_ - from_first_to_current;
//                ptr_ = first_ + _n - 1;
                if (ptr_ == first_)
                    first_ -= capacity_ - _n;
                ptr_ -= capacity_ - _n;
                return ptr_;
            }
            if (ptr_ == first_)
                first_ += _n;
            ptr_ += _n;
            return *this;
        }

        ra_iterator &operator-=(difference_type _n) noexcept {
            _n %= capacity_;
            if (ptr_ - _n <= head_) {
                if (ptr_ == first_)
                    first_ += capacity_ - _n;
                return ptr_ += capacity_ - _n;
            }
            if (ptr_ == first_)
                first_ -= _n;
            return ptr_ -= _n;
        }

        ra_iterator operator+(difference_type n_) const noexcept {
            difference_type _n = n_;
            _n %= capacity_;
            if (ptr_ + _n >= head_ + capacity_) {

                return ra_iterator(ptr_ - (capacity_ - _n), head_, capacity_, first_);
            }

            return ra_iterator(ptr_ + n_, head_, capacity_, first_);
        }

        ra_iterator operator-(difference_type n_) const noexcept {
            difference_type _n = n_;
            _n %= capacity_;
            if (ptr_ - _n < head_) {
                //ptr_+= (capacity_ - _n);
                return ra_iterator(ptr_ + capacity_ - _n, head_, capacity_, first_);
            }

            return ra_iterator(ptr_ - _n, head_, capacity_, first_);
        }

        difference_type operator-(ra_iterator &iterator) const noexcept {
            difference_type _n = ptr_ - iterator.ptr_;
            if (_n < 0) {
                _n = -_n + 1;
                return capacity_ - _n;
            }
            return _n;
        }

        ra_iterator &operator++() noexcept {
            if (ptr_ == head_ + capacity_ - 1) {
                if (ptr_ == first_)
                    first_ = head_;
                ptr_ = head_;
            } else {
                if (ptr_ == first_)
                    ++first_;
                ++ptr_;
            }
            return *this;
        }

        ra_iterator operator++(int) noexcept {
            if (ptr_ == head_ + capacity_ - 1) {
                if (ptr_ == first_)
                    first_ = head_;
                ptr_ = head_;
                return ra_iterator(ptr_, head_, capacity_, first_);
            }
            return ra_iterator(ptr_++, head_, capacity_, first_);
        }

        ra_iterator &operator--() noexcept {
            if (ptr_ == head_) {
                if (ptr_ == first_)
                    first_ += capacity_ - 1;
                ptr_ += capacity_ - 1;
            } else {
                if (ptr_ == first_)
                    --first_;
                --ptr_;
            }
            return *this;
        }

        ra_iterator operator--(int) noexcept {
            if (ptr_ == head_) {
                if (ptr_ == first_)
                    first_ += capacity_ - 1;
                ptr_ += capacity_ - 1;
            } else {
                return ra_iterator(ptr_--, head_, capacity_, first_--);
            }
            return ra_iterator(ptr_, head_, capacity_, first_);
        }

        Tp_ &operator*() {
            return *ptr_;
        }

        Tp_ *operator->() {
            return ptr_;
        }


        inline bool operator==(const ra_iterator &_iteratorR) noexcept {
            return ptr_ == _iteratorR.ptr_; //&& head_ == _iteratorR.head_ && capacity_ == _iteratorR.capacity_;
        }

        inline bool operator!=(const ra_iterator &_iteratorR) noexcept {
            return !(*this == _iteratorR);
        }

        inline bool operator<(const ra_iterator &_iteratorR) noexcept {

            return ptr_ - first_ < _iteratorR.ptr_ - first_;
        }
        inline bool operator>(const ra_iterator &_iteratorR) noexcept {
            return ptr_ - first_ > _iteratorR.ptr_ - first_;
        }
        inline bool operator<=(const ra_iterator &_iteratorR) noexcept {
            return !(*this>_iteratorR);
        }



        inline bool operator>=(const ra_iterator &_iteratorR) noexcept {
            return !(*this<_iteratorR);
        }

        random_access_iterator &operator=(const ra_iterator &_other) {
            if (_other.ptr_ == ptr_)
                return *this;

            ptr_ = _other.ptr_;
            head_ = _other.head_;
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