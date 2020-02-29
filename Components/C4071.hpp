//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// C4071 hpp file
//

#ifndef C4071_H_
#define C4071_H_

#include <string>
#include <vector>
#include "../Primitives.hpp"
#include "../IComponent.hpp"

namespace nts
{
    class C4071 : public IComponent
    {
    public:
        C4071(const std::string &name);
        ~C4071() {};
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


#endif /* C4071_H_ */
