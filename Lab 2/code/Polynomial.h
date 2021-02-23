#ifndef CODE_POLYNOMIAL_H
#define CODE_POLYNOMIAL_H

#include <stdarg.h>
#include <iostream>

class Polynomial {
private:
    int N;
    double *odds;
public:
    int Size() const {
        return N;
    }

    double *GetOdds() const {
        return odds;
    }

    explicit Polynomial(int n, ...) :
            N(n) {
        odds = new double[N + 1];
        va_list factor;
        n += 1;
        va_start(factor, n);
        for (int i = 0; i < n; i++) {
            odds[i] = va_arg(factor, double);
        }
        va_end(factor);

    }

    Polynomial(const Polynomial &polynomial) :
            N(polynomial.N) {

        odds = new double[N + 1];
        for (int i = 0; i < N + 1; i++) {
            odds[i] = polynomial.odds[i];
        }
    }

    double operator[](const int index) {
        if (index > N)
            return 0.0;
        return odds[index];
    }

    Polynomial &operator=(const Polynomial &polynomial) {
        if (&polynomial != this) {
            N = polynomial.N;
            delete[] odds;
            odds = new double[N + 1];
            for (int i = 0; i < N + 1; i++) {
                odds[i] = polynomial.odds[i];
            }
        }
        return *this;
    }

    bool operator==(const Polynomial &p1) {
        if (N != p1.N)
            return false;
        for (int i = 0; i < N + 1; i++) {
            if (odds[i] != p1.odds[i])
                return false;
        }
        return true;
    }

    bool operator!=(const Polynomial &p1) {
        return !(*this == p1);
    }

    //1+x+x^2
    //2+5x+x^2+x^3
    Polynomial operator+(Polynomial &p1) {

        int n = (N > p1.N) ? (N) : (p1.N);
        Polynomial result(n);
        {
            auto *tmp = new double[n + 1];
            auto *tmp2 = new double[n + 1];
            for (int i = 0; i < n + 1; i++) {
                if (i < N + 1)
                    tmp[i] = odds[i];
                else tmp[i] = 0.0;
                tmp2[i] = p1[i];
            }

            for (int i = 0; i < n + 1; i++) {
                result.odds[i] = tmp2[i] + tmp[i];
            }

        }

        return Polynomial(result);
    }

    Polynomial operator-() {
        Polynomial result(N);
        for (int i = 0; i < N + 1; i++) {
            result.odds[i] = -odds[i];
        }
        return Polynomial(result);
    }

    Polynomial operator-(Polynomial &p1) {

        return ((-p1) + (*this));
    }

    Polynomial &operator+=(Polynomial &p1) {
/*
        int n = (N > p1.N) ? (N) : (p1.N);

        {
            auto *tmp = new double[n + 1];
            auto *tmp2 = new double[n + 1];
            for (int i = 0; i < n + 1; i++) {
                if (i < N + 1)
                    tmp[i] = odds[i];
                else tmp[i] = 0.0;
                tmp2[i] = p1[i];
            }
            N = n;
            odds = new double[n+1];
            for (int i = 0; i < n + 1; i++) {
                odds[i] = tmp2[i] + tmp[i];
            }

        }*/
        Polynomial po(*this + p1);
        *this = po;
        return (*this);
    }

    Polynomial &operator-=(Polynomial &p1) {
        /*int n = (N > p1.N) ? (N) : (p1.N);

        {
            auto *tmp = new double[n + 1];
            auto *tmp2 = new double[n + 1];
            for (int i = 0; i < n + 1; i++) {
                if (i < N + 1)
                    tmp[i] = odds[i];
                else tmp[i] = 0.0;
                tmp2[i] = p1[i];
            }
            N = n;
            odds = new double[n+1];
            for (int i = 0; i < n + 1; i++) {
                odds[i] = -tmp2[i] + tmp[i];
            }

        }*/
        Polynomial po(*this - p1);
        *this = po;
        return *this;
    }

    //1+x+3x^2
    //2+6x
    Polynomial operator*(Polynomial &p1) {
        Polynomial p(N + p1.N);
        for (int i = 0; i < p.N + 1; i++)
            p.odds[i] = 0.0;
        for (int i = 0; i < N + 1; i++) {
            for (int j = 0; j < p1.N + 1; j++) {
                p.odds[i + j] += odds[i] * p1.odds[j];
            }
        }
        return p;
    }

    Polynomial operator/(double value) {
        Polynomial p(N);
        for (int i = 0; i < N + 1; i++)
            p.odds[i] = odds[i] / value;
        return p;
    }

    Polynomial &operator*=(Polynomial &p1) {
        Polynomial tmp(*this * p1);
        *this = tmp;
        return *this;
    }

    Polynomial &operator/=(double value) {
        Polynomial tmp(*this / value);
        *this = tmp;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, const Polynomial &polynomial);
    friend std::istream &operator>>(std::istream &in, const Polynomial &polynomial);

    //⁰ ¹ ² ³ ⁴ ⁵ ⁶ ⁷ ⁸ ⁹
    ~Polynomial() {
        delete[] odds;
    }
};

std::ostream &operator<<(std::ostream &out, const Polynomial &polynomial) {

    for (int i = polynomial.N; i >= 0; i--) {
        double thisOdd = polynomial.odds[i];
        if (i == 0)
            out << thisOdd;
        else {
            if (thisOdd == 1)
                out << "x^" << i << "+";
            else
            out << thisOdd << "x^" << i << "+";
        }
    }
    return out;
}
std::istream &operator>>(std::istream &in, const Polynomial &polynomial) {

    for (int i=0;i<polynomial.Size()+1;i++){
        in>>polynomial.odds[i];
    }
    return in;
}

#endif //CODE_POLYNOMIAL_H
