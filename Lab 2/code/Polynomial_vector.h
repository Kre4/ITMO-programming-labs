#ifndef CODE_POLYNOMIAL_VEC_H
#define CODE_POLYNOMIAL_VEC_H

#include <stdarg.h>
#include <iostream>
#include <vector>
#include <iomanip>

//template<int N>
class polynomial_v {
private:
    std::vector<double> odds;
public:
    int Size() const {
        return odds.size() - 1;
    }

    std::vector<double> GetOdds() const {
        return odds;
    }

    explicit polynomial_v(int n, std::initializer_list<double> e) {
        //odds.resize(n + 1);
        odds.assign(e);
        int i = 0;
        //for (auto el: e) {
        //    odds[i] = el;
        //    i++;
        //}


    }

    explicit polynomial_v(int n = 0) {
        odds.assign(n + 1, 0.0);

    }

    polynomial_v(const polynomial_v &polynomial) : odds(polynomial.odds) {

    }

    double operator[](int index) {
        if (index > odds.size())
            return 0.0;
        return odds[index];
    }

    polynomial_v &operator=(const polynomial_v &polynomial) {
        if (&polynomial != this) {
            odds.assign(polynomial.odds.begin(), polynomial.odds.end());
        }
        return *this;
    }

    bool operator==(const polynomial_v &p1) {
        if (odds.size() != p1.Size())
            return false;
        for (int i = 0; i < Size() + 1; i++) {
            if (odds[i] != p1.odds[i])
                return false;
        }
        return true;
    }

    bool operator!=(const polynomial_v &p1) {
        return !(*this == p1);
    }

    //1+x+x^2
    //2+5x+x^2+x^3
    polynomial_v operator+(polynomial_v &p1) {

        polynomial_v result(*this);
        result += p1;

        return result;
    }

    polynomial_v operator-() {
        polynomial_v result(Size());
        for (int i = 0; i < Size() + 1; i++) {
            result.odds[i] = -odds[i];
        }
        return result;
    }

    polynomial_v operator-(polynomial_v &p1) {

        return ((-p1) + (*this));
    }

    polynomial_v &operator+=(polynomial_v &p1) {
        int n = Size() > p1.Size() ? Size() : p1.Size();
        std::vector<double> result_odds(n + 1, 0.0);
        for (int i = 0; i < n + 1; i++) {
            if (i < Size() + 1)
                result_odds[i] += odds[i];
            if (i < p1.Size() + 1)
                result_odds[i] += p1.odds[i];
        }
        odds = result_odds;
        return (*this);
    }

    polynomial_v &operator-=(polynomial_v &p1) {
        int n = Size() > p1.Size() ? Size() : p1.Size();
        std::vector<double> result_odds(n + 1, 0.0);
        for (int i = 0; i < n + 1; i++) {

            if (i < Size() + 1)
                result_odds[i] += odds[i];
            if (i < p1.Size() + 1)
                result_odds[i] -= p1.odds[i];
        }
        odds = result_odds;
        return (*this);

    }

    //1+x+3x^2
    //2+6x
    polynomial_v operator*(polynomial_v &p1) {
        polynomial_v p;
        p += *this;
        p *= p1;
        return p;
    }

    polynomial_v operator/(double value) {
        polynomial_v p(Size() + 1);
        for (int i = 0; i < Size() + 1; i++)
            p.odds[i] = odds[i] / value;
        return p;
    }

    polynomial_v &operator*=(polynomial_v &p1) {
        std::vector<double> new_odds(p1.Size() + Size() + 1);
        for (int i = 0; i < Size() + 1; i++) {
            for (int j = 0; j < p1.Size() + 1; j++) {
                new_odds[i + j] += odds[i] * p1.odds[j];
            }

        }
        odds = new_odds;
        return *this;
    }

    polynomial_v &operator/=(double value) {
        for (int i = 0; i < Size() + 1; i++)
            odds[i] /= value;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const polynomial_v &polynomial);

    friend std::istream &operator>>(std::istream &in, polynomial_v &polynomial);

    //доп функционал
    void diff() {
        for (int i = 0; i < odds.size() - 1; i++) {
            odds[i] = odds[i + 1] * (i + 1);
        }
        odds.pop_back();
    }

    void integrate(int constanta) {
        odds.resize(odds.size() + 1);
        for (int i = odds.size() - 1; i > 0; --i) {
            odds[i] = odds[i - 1] / i;
        }
        odds[0] = constanta;

    }

    ~polynomial_v() = default;
};

std::ostream &operator<<(std::ostream &out, const polynomial_v &polynomial) {

    for (int i = polynomial.Size(); i >= 0; i--) {
        double thisOdd = polynomial.odds[i];
        if (i == 0)
            out << thisOdd;
        else {
            if (thisOdd == 1)
                out << "x^" << i << "+";
            else {
                if (thisOdd != 0)
                    out << std::fixed << std::setprecision(3) << thisOdd << "x^" << i << "+";
            }
        }
    }
    return out;
}

std::istream &operator>>(std::istream &in, polynomial_v &polynomial) {

    for (int i = 0; i < polynomial.Size() + 1; i++) {
        in >> polynomial.odds[i];
    }
    return in;
}

#endif //CODE_POLYNOMIAL_VEC_H