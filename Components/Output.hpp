//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// OUTPUT hpp file
//

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <string>
#include <vector>
#include "../Primitives.hpp"
#include "../IComponent.hpp"

namespace nts
{
    class Output : public IComponent
    {
        public:
            Output(const std::string &name);
            ~Output() {};
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

#endif /* Output_H_ */
