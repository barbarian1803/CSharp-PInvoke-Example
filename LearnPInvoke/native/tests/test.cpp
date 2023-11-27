#include <iostream>
#include "object.hpp"

int main(int argc, char* argv[])
{
    MyObject::Object o = MyObject::Object("myname");
    std::cout << "Object name: " << o.GetName() << "\n";
    o.SetName("myname2");
    std::cout << "Set object name: " << o.GetName() << "\n";
    std::cout << "Object name: " << o.GetName() << "\n";
}