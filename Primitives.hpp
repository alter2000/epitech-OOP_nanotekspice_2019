/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#ifndef PRIMITIVES_HPP_
#define PRIMITIVES_HPP_

#include "IComponent.hpp"

namespace nts
{
    class Primitive
    {
        public:
            virtual ~Primitive() {}
            virtual nts::TriState get() const { return nts::UNDEFINED; };
    };

    class Not : public Primitive
    {
        public:
            Not(nts::TriState a) : a{a} {}
            Not(Primitive a) : a{a.get()} {}
            nts::TriState operator()() const
            {
                switch (a) {
                    case nts::UNDEFINED: return nts::UNDEFINED;
                    case nts::TRUE:      return nts::FALSE;
                    case nts::FALSE:     return nts::TRUE;
                }
            }
            nts::TriState get() const { return a; }
        private:
            nts::TriState a;
    };

    class And : public Primitive
    {
        public:
            And(nts::TriState a, nts::TriState b) : a{a}, b{b} {}
            And(nts::TriState a, Primitive b) : a{a}, b{b.get()} {}
            And(Primitive a, nts::TriState b) : a{a.get()}, b{b} {}
            And(Primitive a, Primitive b) : a{a.get()}, b{b.get()} {}
            nts::TriState operator()(nts::TriState a, nts::TriState b) const
            {
                if (a == nts::UNDEFINED || b == nts::UNDEFINED)
                    return nts::UNDEFINED;
                return (a == b) ? nts::TRUE : nts::FALSE;
            }
            nts::TriState get() const { return this->operator()(a, b); }
        private:
            nts::TriState a;
            nts::TriState b;
    };

    class NAnd : public Primitive
    {
        public:
            NAnd(nts::TriState a, nts::TriState b) : a{a}, b{b} {}
            NAnd(nts::TriState a, Primitive b) : a{a}, b{b.get()} {}
            NAnd(Primitive a, nts::TriState b) : a{a.get()}, b{b} {}
            NAnd(Primitive a, Primitive b) : a{a.get()}, b{b.get()} {}
            nts::TriState operator()(nts::TriState a, nts::TriState b) const
            {
                if (a == nts::UNDEFINED || b == nts::UNDEFINED)
                    return nts::UNDEFINED;
                return Not(And(a, b)).get();
            }
            nts::TriState get() const { return this->operator()(a, b); }
        private:
            nts::TriState a;
            nts::TriState b;
    };

    class Or : public Primitive
    {
        public:
            Or(nts::TriState a, nts::TriState b) : a{a}, b{b} {}
            Or(nts::TriState a, Primitive b) : a{a}, b{b.get()} {}
            Or(Primitive a, nts::TriState b) : a{a.get()}, b{b} {}
            Or(Primitive a, Primitive b) : a{a.get()}, b{b.get()} {}
            nts::TriState operator()(nts::TriState a, nts::TriState b) const
            {
                if (a == nts::UNDEFINED || b == nts::UNDEFINED)
                    return nts::UNDEFINED;
                return (a == nts::TRUE || b == nts::TRUE) ? nts::TRUE : nts::FALSE;
            }
            nts::TriState get() const { return this->operator()(a, b); }
        private:
            nts::TriState a;
            nts::TriState b;
    };

    class NOr : public Primitive
    {
        public:
            NOr(nts::TriState a, nts::TriState b) : a{a}, b{b} {}
            NOr(nts::TriState a, Primitive b) : a{a}, b{b.get()} {}
            NOr(Primitive a, nts::TriState b) : a{a.get()}, b{b} {}
            NOr(Primitive a, Primitive b) : a{a.get()}, b{b.get()} {}
            nts::TriState operator()(nts::TriState a, nts::TriState b) const
            {
                if (a == nts::UNDEFINED || b == nts::UNDEFINED)
                    return nts::UNDEFINED;
                return Not(Or(a, b)).get();
            }
            nts::TriState get() const { return this->operator()(a, b); }
        private:
            nts::TriState a;
            nts::TriState b;
    };

    class XOr : public Primitive
    {
        public:
            XOr(nts::TriState a, nts::TriState b) : a{a}, b{b} {}
            XOr(nts::TriState a, Primitive b) : a{a}, b{b.get()} {}
            XOr(Primitive a, nts::TriState b) : a{a.get()}, b{b} {}
            XOr(Primitive a, Primitive b) : a{a.get()}, b{b.get()} {}
            nts::TriState operator()(nts::TriState a, nts::TriState b) const
            {
                if (a == nts::UNDEFINED || b == nts::UNDEFINED)
                    return nts::UNDEFINED;
                return (a == b) ? nts::FALSE : nts::TRUE;
            }
            nts::TriState get() const { return this->operator()(a, b); }
        private:
            nts::TriState a;
            nts::TriState b;
    };

    class True : public Primitive
    {
        public:
            nts::TriState operator()() const { return nts::TRUE; }
            nts::TriState get() const { return this->operator()(); }
    };

    class False : public Primitive
    {
        public:
            nts::TriState operator()() const { return nts::FALSE; }
            nts::TriState get() const { return this->operator()(); }
    };

    class Clock : public Primitive
    {
        public:
            nts::TriState operator()()
            {
                nts::TriState r;

                switch (a) {
                    case nts::TRUE:
                        r = a;
                        a = nts::FALSE;
                    case nts::FALSE:
                        r = a;
                        a = nts::TRUE;
                    case nts::UNDEFINED:
                        return a;
                }
                return r;
            }
            nts::TriState get() const { return a; }
        private:
            nts::TriState a;
    };
}

#endif
