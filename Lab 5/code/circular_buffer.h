#ifndef CODE_CIRCULAR_BUFFER_H
#define CODE_CIRCULAR_BUFFER_H

#include <cstdio>
#include <memory>
#include "cb_iterator.h"
#include <iostream>

// The structure is that, buffer has one extra element
// The same as in any stl container
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
        explicit ring(size_t _n, const allocator_type &_alloc = allocator_type()) : capacity_(_n + 1), alloc_(_alloc),
                                                                                    size_(0) {

            fill_with({}, false);

        }

        explicit ring(size_t _n, Tp_ _value, const allocator_type &_alloc = allocator_type()) : capacity_(_n + 1),
                                                                                                alloc_(_alloc),
                                                                                                size_(_n) {

            fill_with(_value);

        }

        explicit ring(std::initializer_list<Tp_> _list, const allocator_type &_alloc = allocator_type()) : capacity_(
                _list.size() + 1), alloc_(_alloc), size_(_list.size()) {

            fill_with(_list);
        }

        ~ring() {
            alloc_.deallocate(data_, capacity_);
        }

        // functions for the buffer
        void resize(size_t _n) {
            if (_n == capacity_)
                return;

            Tp_ *tmp = alloc_.allocate(_n);
            size_t i = 0;

            auto fixed = first_;
            for (i = 0; i != capacity_ && i != _n && first_ != last_; ++first_, ++i) {
                alloc_.construct(tmp + i, *(fixed + i));
                if (i == 0)
                    --first_;

            }

            typedef typename random_access_iterator<Tp_>::difference_type dft;
            dft delta = last_ - fixed;

            for (i = 0; i != capacity_; ++i) {
                destroy(data_ + i);
                //alloc_.destroy(data_ + i);
            }
            alloc_.deallocate(data_, capacity_);


            data_ = tmp;

            first_ = random_access_iterator(data_, data_, capacity_);

            last_ = first_ + delta;
            if (_n < capacity_) {
                size_ = _n;
            }
            capacity_ = _n;

        }


        random_access_iterator<Tp_> begin() {
            return first_;
        }


        random_access_iterator<Tp_> end() {
            //last_ = first_ + capacity_;
            return last_;
        }


        Tp_ &back() {
            return *(last_ - 1);
        }


        size_t size() const {
            return size_;
        }

        size_t capacity() const {
            return capacity_;
        }


        void push_back(const Tp_ &_val) {

            if (size_ != capacity_)
                ++size_;
            alloc_.construct(std::addressof(*last_), _val);
            ++last_;
            if (last_ == first_) {
                destroy(last_.ptr_);
                // alloc_.destroy(last_.ptr_);
                ++first_;
            }
        }

        void push_front(const Tp_ &_val) {
            if (size_ != capacity_)
                ++size_;
            --first_;
            if (first_ == last_) {
                --last_;
                destroy(last_.ptr_);
                //alloc_.destroy(last_.ptr_);
            }
            alloc_.construct(std::addressof(*first_), _val);

        }

        void pop_back() {
            if (size_ == 0)
                return;
            --size_;
            --last_;
            destroy(last_.ptr_);
            if (last_ == first_ && size_ != 0) {
                --first_;
            }
        }

        void pop_front() {
            if (size_ == 0)
                return;
            --size_;
            destroy(first_.ptr_);
            ++first_;
        }

        Tp_ &operator[](const size_t &index) {
            return *(first_ + index);
        }


    private:
        allocator_pointer allocate(size_t &n) {
            return (n == 0) ? (nullptr) : (alloc_.allocate(n));

        }

        void destroy(Tp_ *item) {
            alloc_.destroy(item);
        }

        void fill_with(std::initializer_list<Tp_> _list = {}, bool _haveItems = true) {
            data_ = allocate(capacity_);
            --capacity_;
            first_ = random_access_iterator(data_, data_, capacity_);
            last_ = random_access_iterator(data_, data_, capacity_);

            if (!_haveItems) {
                return;
            }
            auto iter = _list.begin();
            for (size_t i = 0; i != capacity_; ++i, ++iter) {
                //alloc_traits::construct(alloc_,std::addressof(*last_),*iter);
                alloc_.construct(std::addressof(*last_), *iter);
                ++last_;
            }
            ++last_;
        }

        void fill_with(Tp_ &_val) {
            data_ = allocate(capacity_ + 1);
            --capacity_;
            first_ = random_access_iterator(data_, first_, capacity_);
            last_ = random_access_iterator(data_, first_, capacity_);

            for (size_t i = 0; i != capacity_; ++i) {
                //alloc_traits::construct(alloc_,std::addressof(*last_),_val);
                alloc_.construct(std::addressof(*last_), _val);
                ++last_;

            }
            ++last_;
        }


    public:

        allocator_type alloc_;
        //allocator_pointer data_;
        Tp_ *data_;
        size_t capacity_;
        size_t size_;

        random_access_iterator<Tp_> first_;
        random_access_iterator<Tp_> last_; // contains next element after the last edited.

    };

}
#endif //CODE_CIRCULAR_BUFFER_H