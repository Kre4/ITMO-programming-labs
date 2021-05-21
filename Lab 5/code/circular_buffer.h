#ifndef CODE_CIRCULAR_BUFFER_H
#define CODE_CIRCULAR_BUFFER_H

#include <cstdio>
#include <memory>
#include "cb_iterator.h"
#include <iostream>
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
        explicit ring(size_t _n, const allocator_type &_alloc = allocator_type()) : capacity_(_n), alloc_(_alloc),
                                                                                    size_(0) {

            fill_with({}, false);

        }

        explicit ring(size_t _n, Tp_ _value, const allocator_type &_alloc = allocator_type()) : capacity_(_n),
                                                                                                alloc_(_alloc),
                                                                                                size_(_n) {

            fill_with(_value);

        }

        explicit ring(std::initializer_list<Tp_> _list, const allocator_type &_alloc = allocator_type()) : capacity_(
                _list.size()), alloc_(_alloc), size_(_list.size()) {

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
                alloc_.destroy(data_ + i);
            }
            alloc_.deallocate(data_, capacity_);


            data_ = tmp;

            first_ = random_access_iterator(data_, data_, capacity_);

            last_ = first_ + delta;
            if (_n< capacity_){
                size_=_n;
            }
            capacity_ = _n;

        }


        random_access_iterator<Tp_> begin() const {
            return random_access_iterator<Tp_>(data_, first_.ptr_, capacity_);
        }

        random_access_iterator<Tp_> end() {
            //last_ = first_ + capacity_;
            return random_access_iterator<Tp_>(data_ + capacity_, first_.ptr_, capacity_);
        }

        Tp_ &back() {
            return *(last_);
        }

        const Tp_ &back() const {
            return *(last_);
        }

        size_t size() const {
            return size_;
        }

        size_t capacity() const {
            return capacity_;
        }


        void push_back(Tp_ _val) {
            ++size_;
            if (size_ == capacity_+1)
                --size_;
            alloc_.destroy(last_.ptr_);
            alloc_.construct(std::addressof(*last_), _val);
            ++last_;
            if (last_ <= first_)
                ++first_;
        }

        void push_front(Tp_ _val) {
            --first_;
            alloc_.destroy(first_.ptr_);
            alloc_.construct(std::addressof(*first_), _val);
            if (last_ == first_)
                --last_;
        }

        void pop_back() {
            if (size() != 0) {
                --size_;
                --last_;
                alloc_.destroy(last_.ptr_);
                if (last_+1 == first_)
                    --first_;
            }
        }

        void pop_front() {
            if (size() != 0) {
                --size_;
                alloc_.destroy(first_.ptr_);
                if (first_ != last_)
                ++first_;



            }
        }

        Tp_ &operator[](size_t index) {

            return *(first_ + index);

        }

    private:
        allocator_pointer allocate(size_t &n) {
            return (n == 0) ? (nullptr) : (alloc_.allocate(n));

        }

        void fill_with(std::initializer_list<Tp_> _list, bool _haveItems = true) {
            data_ = allocate(capacity_);
            first_ = random_access_iterator(data_, data_, capacity_);
            last_ = random_access_iterator(data_, data_, capacity_);

            if (!_haveItems)
                return;
            auto iter = _list.begin();
            for (size_t i = 0; i != capacity_; ++i, ++iter) {
                //alloc_traits::construct(alloc_,std::addressof(*last_),*iter);
                alloc_.construct(std::addressof(*last_), *iter);
                ++last_;
            }
        }

        void fill_with(Tp_ &_val) {
            data_ = allocate(capacity_);
            first_ = random_access_iterator(data_, first_, capacity_);
            last_ = random_access_iterator(data_, first_, capacity_);

            for (size_t i = 0; i != capacity_; ++i) {
                //alloc_traits::construct(alloc_,std::addressof(*last_),_val);
                alloc_.construct(std::addressof(*last_), _val);
                ++last_;

            }
        }


    public:
        allocator_type alloc_;
        //allocator_pointer data_;
        Tp_ *data_;
        size_t capacity_;
        size_t size_;

        random_access_iterator<Tp_> first_;
        random_access_iterator<Tp_> last_;
    };

}
#endif //CODE_CIRCULAR_BUFFER_H