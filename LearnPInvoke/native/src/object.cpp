#include "object.hpp"
#include <string>

MyObject::Object::Object(std::string pName){
    this->name = pName;
}

std::string MyObject::Object::GetName(){
    return this->name;
}

void MyObject::Object::SetName(std::string pName){
    this->name = pName;
}