//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// Input hpp file
//

#ifndef INPUT_H_
#define INPUT_H_

#include <string>
#include <vector>
#include "../Primitives.hpp"
#include "../IComponent.hpp"

namespace nts
{
    class Input : public IComponent
    {
        public:
            Input(const std::string &name);
            ~Input() {};
            TriState compute(size_t pin = 1);
            void setLink(std::size_t pin, IComponent &component, std::size_t target);
            void dump(void) const;
            void _setIn(TriState a);
            ctName Name() const;
            ctType Type() const;
        private:
            const std::string _type;
            ctName _name;
            ctls _link;
    };
}

#endif /* INPUT_H_ */
