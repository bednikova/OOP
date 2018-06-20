#ifndef __POLINOM_H__
#define __POLINOM_H__

#include <fstream>



template <typename Type>
class Polinom
{
    public:

        class Iterator
        {
            public:

                Iterator(Type* ptr) : ptr_(ptr)
                {

                }

                Iterator& operator++()
                {
                    ++this->ptr_;
                    return *this;
                }

                Iterator operator++(int)
                {
                    Iterator i = *this;
                    ++(*this);
                    return i;
                }

                Iterator& operator--()
                {
                    --this->ptr_;
                    return *this;
                }

                Iterator operator--(int)
                {
                    Iterator i = *this;
                    --(*this);
                    return i;
                }

                Type& operator*()
                {
                    return *ptr_;
                }

                Type* operator->()
                {
                    return ptr_;
                }

                bool operator==(const Iterator& rhs)
                {
                    return ptr_ == rhs.ptr_;
                }
                bool operator!=(const Iterator& rhs)
                {
                    return ptr_ != rhs.ptr_;
                }
            private:

                Type* ptr_;
        };

        Polinom();
        Polinom(Type* coef, int deg);
        ~Polinom();
        Polinom(const Polinom&);
        Polinom& operator=(const Polinom&);

        //get
        Type getElem(int index) const;


        //trqbva da sa v klasa, zashtoto promenqt obekta!!!
        Polinom& operator+=(const Polinom&);
        Polinom& operator-=(const Polinom&);
        Polinom& operator*=(const Polinom&);
        Polinom& operator/=(const Polinom&);
        Polinom& operator%=(const Polinom&);

        //moje bi trqbva da sa vynshni functions,
        //zashtoto ne promenqt obekta
        Polinom operator+(const Polinom&);
        Polinom operator-(const Polinom&);
        Polinom operator*(const Polinom&);
        Polinom operator/(const Polinom&);
        Polinom operator%(const Polinom&);

        //moje bi trqbva da sa vynshni functions,
        //zashtoto ne promenqt obekta
        bool operator==(const Polinom&);
        bool operator!=(const Polinom&);

        //moje me sa chlenove na klasa
        bool operator<(const Polinom&);
        bool operator>(const Polinom&);
        bool operator>=(const Polinom&);
        bool operator<=(const Polinom&);

        Polinom operator*(Type);
        Polinom operator/(Type);

        //trqbva da sa vytreshni!!!
        Type operator()(Type) const;
        Type operator()(Type,Type) const;

        Type& operator[](int);

        //operator za cast
        operator int() const;

        //operator za cast
        operator bool() const;

        //п!
        bool operator!(void) const;

        //++
        Polinom& operator++();
        Polinom operator++(int);

        Polinom& operator--();
        Polinom operator--(int);

        //integral
        Polinom& integral();

        //proizvodna
        Polinom& proizvodna();

        int getSize() const;




        Iterator begin()
        {
            return Iterator(coef);
        }

        Iterator end()
        {
            return Iterator(coef + size);
        }


        friend std::ostream& operator<< (std::ostream& os, const Polinom& p)
        {
            for(int index = 0; index < p.size; ++index)
            {
                if(p.getElem(index) == -0 || p.getElem(index) == 0)
                {
                     os << (index > 0 ? " + " : "")
                        << ((p.getElem(index) == 0) ? p.getElem(index) : p.getElem(index)*(-1))
                        << "*x^" << p.deg - index;
                }
                else
                {
                    if(index > 0)
                    {
                        os << (p.getElem(index) >= 0 ? " + " : " - ")
                           << ((p.getElem(index) > 0) ? p.getElem(index) : p.getElem(index)*(-1))
                           << "*x^" << p.deg - index;
                    }
                    if(index == 0)
                    {
                        os << (p.getElem(index) >= 0 ? "" : "-")
                           << ((p.getElem(index) > 0) ? p.getElem(index) : p.getElem(index)*(-1))
                           << "*x^" << p.deg - index;
                    }
                }


            }

            return os;
        }

        friend std::istream& operator>> (std::istream& is, Polinom& p)
        {

            int degree;
            std::cout << "Enter degree: ";
            is >> degree;

            p.deleteHelp();
            p.deg = degree;
            p.size =  p.deg + 1;
            p.coef = new Type[p.size];


    //      for(int index = p.size - 1; index >= 0; --index)
            for(int index = 0; index < p.size; ++index )
            {
                Type type;
                std::cout << "Enter coef: ";
                is >> type;
                p.coef[index] = type;
            }

            return is;
        }

    private:
            void copyHelp(const Polinom&);
            void deleteHelp();


    private:
        //[a0, a1, ... , an-1, an] -> coef
        //p(x) = a0*x^n + a1*x^n-1 + ... + an-1*x^1 + an*x^0
        Type* coef;  //shte sydyrja koef.
        int size;  // size = deg + 1
        int deg;  //deg = size - 1




};

#include "Polinom.imp"

#endif



