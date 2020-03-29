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
#include "../Primitives/Primitives.hpp"
#include "../IComponent.hpp"

namespace nts
{
    class Output : public IComponent
    {
        public:
            Output(const std::string &name);
            ~Output() {};
            TriState compute(size_t pin = 1);
            void setLink(std::size_t pin, ct component, std::size_t target);
            void dump(void) const;
            ctName Name() const;
            ctType Type() const;

            ctls getLinks() const { return ctls{_link}; }
        private:
            const std::string _t = "output";
            const std::string _n;
            ct _link;
    };
}

#endif /* Output_H_ */
