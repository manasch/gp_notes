#include <iostream>

template <typename T>
struct movable_unit
{
    void advance(size_t steps)
    {
        while (steps--)
            static_cast<T*>(this)->step_forth();
    }

    void retreat(size_t steps)
    {
        while (steps--)
            static_cast<T*>(this)->step_back();
    }
};

struct knight : movable_unit<knight>
{
    void step_forth()
    {
        std::cout << "knight moves forward\n";
    }

    void step_back()
    {
        std::cout << "knight moves back\n";
    }
};

struct mage : movable_unit<mage>
{
    void step_forth()
    {
        std::cout << "mage moves forward\n";
    }

    void step_back()
    {
        std::cout << "mage moves back\n";
    }
};

int main()
{
    constexpr size_t steps = 3;

    knight k;
    k.advance(steps);
    k.retreat(steps);

    mage m;
    m.advance(steps);
    m.retreat(steps);

    return 0;
}
