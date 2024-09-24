#include <iostream>
#include <string>

// Example Entity class
class Entity
{
public:
    // public method called 'GetName' that just returns "Entity"
    // now marked as virtual to generate a vtable and allows being overwritten to the correct function
    virtual std::string GetName() { return "Entity"; }
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
    std::string GetName() override { return m_Name; } // using 'override' helps to prevent bugs and know that it is overwriting something
};

// Example function showing the issue a bit better as anything with PrintName will use the Type 'Entity'
void PrintName(Entity *entity)
{
    std::cout << entity->GetName() << std::endl;
};

int main()
{
    // created new Entity
    Entity *e = new Entity;
    // print the GetName from the Entity
    PrintName(e);

    // created new Player
    Player *p = new Player("AchroDev");
    // print the GetName from the Player member
    PrintName(p);

    std::cin.get();
}
