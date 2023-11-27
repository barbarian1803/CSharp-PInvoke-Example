#include "object_wrapper.hpp"
#include "object.hpp"
#include <iostream>

struct object_str {
	void *obj;
};

object_str_t* object_create(const char* pName){
    object_str* obj_str = new object_str;

    std::string pNameStr(pName);
    MyObject::Object* obj = new MyObject::Object(pNameStr);
    obj_str->obj = obj;
    return obj_str;
}

const char* object_get_name(object_str_t* o){
    if(o == NULL || o->obj == NULL){
        return nullptr;
    }
    MyObject::Object* obj = (typeof(MyObject::Object*))o->obj;
    std::string* retval = new std::string(obj->GetName());
    return retval->c_str();
}

void object_set_name(object_str_t* o, const char* pName){
    if(o == NULL){
        return;
    }
    std::string pNameStr(pName);
    MyObject::Object* obj = (typeof(MyObject::Object*))o->obj;
    obj->SetName(pNameStr);
}

// Free memory allocated by allocateMemory
void free_memory(const char* charArray) {
    delete[] charArray;
}

void delete_oject(object_str_t* o){
    delete ((typeof(MyObject::Object*))o->obj);
    delete o;
}