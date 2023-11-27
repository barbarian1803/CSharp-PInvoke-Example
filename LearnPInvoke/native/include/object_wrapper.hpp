#ifndef __OBJECT_WRAPPER__
#define __OBJECT_WRAPPER__

#ifdef __cplusplus
extern "C" {
#endif

struct object_str;
typedef struct object_str object_str_t;

object_str_t* object_create(const char*);
const char* object_get_name(object_str_t*);
void object_set_name(object_str_t*, const char*);
void free_memory(const char*);
void delete_oject(object_str_t*);

#ifdef __cplusplus
}
#endif

#endif