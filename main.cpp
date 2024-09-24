#include <iostream>
#include <string>

// A "Pure Virtual Function" is an Interface or a class that consists of unemplemented methods (sort of like a template)

// Example Entity class
class Entity
{
public:
    virtual std::string GetName() = 0; // now declared as a "pure virtual function" requiring a subclass to implement it
};

// Example Player class that inherits the Entity class, i.e. subclass
class Player : public Entity
{
private:
    // declaring a string variable to store the name
    std::string m_Name;

public:
    // public constructor that allows us to specify a name
    Player(const std::string &name)
        : m_Name(name) {}

    // method 'GetName' again to return the name that is the member
    // std::string GetName() override { return m_Name; } // using 'override' helps to prevent bugs and know that it is overwriting something
};

// Example function showing the issue a bit better as anything with PrintName will use the Type 'Entity'
void PrintName(Entity *entity)
{
    std::cout << entity->GetName() << std::endl;
};

int main()
{
    // created new Entity
    Entity *e = new Player(""); // Now notice that since it isn't implemented in Player anymore, neither can be instantiated
    // print the GetName from the Entity
    PrintName(e);

    // created new Player
    Player *p = new Player("AchroDev"); // here too
    // print the GetName from the Player member
    PrintName(p);

    std::cin.get();
}
