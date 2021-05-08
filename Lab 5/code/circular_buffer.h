#ifndef CODE_CIRCULAR_BUFFER_H
#define CODE_CIRCULAR_BUFFER_H

#include <cstdio>
#include <memory>
#include "cb_iterator.h"

namespace cbuf {
    template<typename Tp_, class Alloc_ = std::allocator<Tp_>>
    class ring {
        //getting allocator info
    public:
        using allocator_type = Alloc_;
        using allocator_pointer = typename std::allocator_traits<Alloc_>::pointer;
        using alloc_traits = std::allocator_traits<Alloc_>;

    public:
        //constructors
        explicit ring(size_t _n, const allocator_type &_alloc = allocator_type()) : capacity_(_n), alloc_(_alloc) {

            fill_with({}, false);

        }

        explicit ring(size_t _n, Tp_ _value, const allocator_type &_alloc = allocator_type()) : capacity_(_n),
                                                                                                alloc_(_alloc) {

            fill_with(_value);

        }

        explicit ring(std::initializer_list<Tp_> _list, const allocator_type &_alloc = allocator_type()) : capacity_(
                _list.size()), alloc_(_alloc) {

            fill_with(_list);
        }

        ~ring() {
            alloc_.deallocate(data_, capacity_);
        }

        // functions for the buffer
        void resize(size_t _n) {
            if (_n == capacity())
                return;


            Tp_ *tmp = alloc_.allocate(_n);
            size_t i = 0;
//            if (_n < capacity()) {
//                //last_ = first_ + _n;
//                for (; i < _n; ++i)
//                    tmp[i] = data_[i];
//
//            } else {
//
//                for (; i < capacity_; ++i)
//                    tmp[i] = data_[i];
//
//
//            }
            size_t size = this->size();
            for (i = 0; first_ != last_, i != _n; ++first_, ++i) {
                tmp[i] = *first_;
                //if (i == _n-1)
                //    first_ = last_;
            }
            alloc_.deallocate(data_, capacity_);
            data_ = allocate(_n);
            first_ = random_access_iterator(data_);
            last_ = first_;
            for (i = 0; (i < _n) && (i < size); ++i, ++last_)
                alloc_.construct(std::addressof(*last_), tmp[i]);

            // FIX EVERING THAT IS LOWER
            if (_n > capacity_) {
                last_ = first_ + size;

            } else {
                last_ = first_ + _n;
                l_pos_ %= _n;

            }
            capacity_ = _n;

            alloc_.deallocate(tmp, capacity_);
        }


        random_access_iterator <Tp_> begin() const {
            return first_;
        }

        random_access_iterator <Tp_> end() const {
            return last_;
        }

        random_access_iterator <Tp_> back() const {
            return last_ - 1;
        }

        size_t size() const {
            return last_ - first_;
        }

        size_t capacity() const {
            return capacity_;
        }

        void push_back(Tp_ _val) {
            if (random_access_iterator<Tp_>(data_ + capacity_) != last_) {
                alloc_.construct(std::addressof(*last_), _val);
                //*last_ = _val;
                ++last_;

            } else {
                //data_[l_pos_] = _val;
                alloc_.construct(std::addressof(data_[l_pos_]), _val);

            }
            inc(l_pos_);
        }

        void push_front(Tp_ _val) {
            if (random_access_iterator<Tp_>(data_) != first_) {
                --first_;
                alloc_.construct(std::addressof(*first_), _val);
                dec(f_pos_);
            } else {
                alloc_.construct(std::addressof(data_[f_pos_]), _val);
                dec(f_pos_);
            }

        }

        void pop_back() {
            if (size() != 0) {
                dec(l_pos_);
                alloc_.destroy(data_ + l_pos_);
                size_t s = last_ - random_access_iterator(data_);
                if (l_pos_ == last_ - random_access_iterator(data_) - 1)
                    --last_;

            }
        }

        void pop_front() {
            if (size() != 0) {
                alloc_.destroy(data_ + f_pos_);
                if (f_pos_ == first_ - random_access_iterator(data_))
                    ++first_;

                inc(f_pos_);
            }
        }

        Tp_ &operator[](size_t index) {

            return *(data_ + index);

        }

    private:
        allocator_pointer allocate(size_t &n) {
            return (n == 0) ? (nullptr) : (alloc_.allocate(n));

        }

        void fill_with(std::initializer_list<Tp_> &_list, bool _haveItems = true) {
            data_ = allocate(capacity_);
            first_ = random_access_iterator(data_);
            last_ = random_access_iterator(data_);
            f_pos_ = 0;
            l_pos_ = 0;
            if (!_haveItems)
                return;
            auto iter = _list.begin();
            for (size_t i = 0; i != capacity_; ++i, ++iter) {
                //alloc_traits::construct(alloc_,std::addressof(*last_),*iter);
                alloc_.construct(std::addressof(*last_), *iter);
                ++last_;
                inc(l_pos_);
            }
        }

        void fill_with(Tp_ &_val) {
            data_ = allocate(capacity_);
            first_ = random_access_iterator(data_);
            last_ = random_access_iterator(data_);
            f_pos_ = 0;
            l_pos_ = 0;
            for (size_t i = 0; i != capacity_; ++i) {
                //alloc_traits::construct(alloc_,std::addressof(*last_),_val);
                alloc_.construct(std::addressof(*last_), _val);
                ++last_;
                inc(l_pos_);
            }
        }

        void inc(size_t &_pos) {
            ++_pos;
            _pos %= capacity_;
        }

        void dec(size_t &_pos) {
            if (_pos == 0)
                _pos = capacity_;
            --_pos;
        }


    public:
        allocator_type alloc_;
        //allocator_pointer data_;
        Tp_ *data_;
        size_t capacity_;

        size_t f_pos_;
        size_t l_pos_;

        random_access_iterator <Tp_> first_;
        random_access_iterator <Tp_> last_;
    };

}
#endif //CODE_CIRCULAR_BUFFER_H