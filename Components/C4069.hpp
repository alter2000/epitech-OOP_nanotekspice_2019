//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// C4069 hpp file
//

#ifndef C4069_H_
#define C4069_H_

#include <string>
#include <vector>
#include "../Primitives.hpp"
#include "../IComponent.hpp"

namespace nts
{
    class C4069 : public IComponent
    {
    public:
        C4069(const std::string &name);
        ~C4069() {};
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


#endif /* C4069_H_ */
