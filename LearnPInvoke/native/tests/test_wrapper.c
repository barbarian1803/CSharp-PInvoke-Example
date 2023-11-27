#include <stdio.h>
#include "object_wrapper.hpp"

int main(int argc, char** argv)
{
    printf("Test Object wrapper\n");

    object_str_t* o_wrapped = object_create("test name");
    const char* o_name;
    const char* o_name2;
    o_name = object_get_name(o_wrapped);
    printf("Object name: %s \n", o_name);
    object_set_name(o_wrapped, "XX name");
    o_name2 = object_get_name(o_wrapped);
    printf("Object name: %s \n", o_name2);
    free_memory(o_name);
    free_memory(o_name2);
    delete_oject(o_wrapped);
}
