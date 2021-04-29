#ifndef CODE_CIRCULAR_BUFFER_H
#define CODE_CIRCULAR_BUFFER_H

#include <cstdio>
#include <memory>
#include "cb_iterator.h"

namespace cbuf {
    template<typename Tp_, class Alloc_ = std::allocator<Tp_>>
    class ring {

    public:
        explicit ring(size_t _n) : capacity_(_n) {
            if (std::is_default_constructible_v<Tp_>)
                fill_with({Tp_()}, false);
            else
                throw std::runtime_error("Type of the circular buffer has no default constructor");
        }

        explicit ring(size_t _n, Tp_ _value) : capacity_(_n) {

            fill_with({_value});

        }

        explicit ring(std::initializer_list<Tp_> _list) : capacity_(_list.size()) {

            fill_with(_list);
        }

        ~ring() {
            delete[] data_;
        }

        void resize(size_t _n) {
            Tp_ *tmp = new Tp_[_n];
            size_t size = (_n > capacity_) ? capacity_ : _n;
            if (size <= capacity_) {
                for (size_t i = 0; i != size; ++i)
                    tmp[i] = data_[i];
            } else {
                size_t i;
                for (i = 0; i != capacity_; ++i)
                    tmp[i] = data_[i];
                for (; i != size; ++i)
                    tmp[i] = Tp_();

            }
            delete[] data_;
            data_ = new Tp_[_n];
            for (size_t i = 0; i != size; ++i)
                data_[i] = tmp[i];
            first_ = random_access_iterator(data_);
            if (size <= capacity_)
                last_ = random_access_iterator(data_ + size - 1);
            delete[] tmp;

        }

        random_access_iterator <Tp_> &begin() {
            return first_;
        }

        random_access_iterator <Tp_> &end() {
            return last_;
        }

        size_t size() {
            return capacity_;
        }

        void push_back(Tp_ _val) {
            ++last_;
            *last_ = _val;
        }

        void push_front(Tp_ _val) {


        }

    protected:
        void fill_with(std::initializer_list<Tp_> _list, bool _haveItems = true) {
            data_ = new Tp_[capacity_];
            first_ = random_access_iterator(data_);
            last_ = random_access_iterator(data_);
            if (_haveItems)
                last_ += capacity_;
            auto iter = _list.begin();
            if (_list.size() > 1)
                for (size_t i = 0; i != capacity_; ++i, ++iter)
                    data_[i] = *iter;
            else
                for (size_t i = 0; i != capacity_; ++i)
                    data_[i] = *iter;
        }

        void increment(random_access_iterator <Tp_> &_iter) {
            if (last_ - capacity_ + 1 == first_) {}
        }

    public:

        Tp_ *data_ = nullptr;
        size_t capacity_;
        random_access_iterator <Tp_> first_;
        random_access_iterator <Tp_> last_;
    };

}
#endif //CODE_CIRCULAR_BUFFER_H
