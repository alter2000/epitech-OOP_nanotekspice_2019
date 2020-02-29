//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// C4081 hpp file
//

#ifndef C4081_H_
#define C4081_H_

#include <string>
#include <vector>
#include "../Primitives.hpp"
#include "../IComponent.hpp"

namespace nts
{
    class C4081 : public IComponent
    {
    public:
        C4081(const std::string &name);
        ~C4081() {};
        nts::TriState compute(size_t pin = 1);
        void setLink(std::size_t pin, IComponent &component, std::size_t target);
        void dump(void) const;
        void _setIn(nts::TriState a);
        ctName Name() const;
        ctType Type() const;
    private:
        const std::string _type;
        ctName _name;
        ctls _link;
    };
}

#endif /* C4081_H_ */
