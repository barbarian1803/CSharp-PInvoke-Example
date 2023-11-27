#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <string>

namespace MyObject{
    class Object{
        private:
            std::string name;
        
        public:
            Object(std::string);
            std::string GetName();
            void SetName(std::string);
            
    };
}

#endif