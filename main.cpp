#include <iostream>
#include <string>

// A "Pure Virtual Function" is an Interface or a class that consists of unemplemented methods (sort of like a template)

// Technially an interface because of the pure virtual function, but still just a class
class Printable
{
public:
    virtual std::string GetClassName() = 0;
};

// Example Entity class now inheriting the Printable class
class Entity : public Printable
{
public:
    virtual std::string GetName() { return "Entity"; } // now declared as a "pure virtual function" requiring a subclass to implement it
    std::string GetClassName() override { return "Entity"; }
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
    std::string GetClassName() override { return "Player"; }
};

// Example function showing the issue a bit better as anything with PrintName will use the Type 'Entity'
void PrintName(Entity *entity)
{
    std::cout << entity->GetName() << std::endl;
};

void Print(Printable *obj)
{
    std::cout << obj->GetClassName() << std::endl;
}

int main()
{
    // created new Entity
    Entity *e = new Entity;
    // print the GetName from the Entity
    // PrintName(e);

    // created new Player
    Player *p = new Player("AchroDev");
    // print the GetName from the Player member
    // PrintName(p);

    Print(e);
    Print(p);

    std::cin.get();
}
