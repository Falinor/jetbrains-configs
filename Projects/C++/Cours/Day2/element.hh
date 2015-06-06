#ifndef ELEMENT_HH_
# define ELEMENT_HH_

enum class Element
{
    WATER = 1,
    EARTH = 2,
    FIRE = 4,
    AIR = 8
};

inline Element operator|(Element e1, Element e2)
{
    return static_cast<Element>(static_cast<int>(e1) | static_cast<int>(e2));
}

void print_element(Element elt);

#endif /* !ELEMENT_HH_ */
