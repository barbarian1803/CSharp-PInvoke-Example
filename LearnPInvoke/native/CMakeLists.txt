cmake_minimum_required(VERSION 3.7)

project(TestWrapper)

set(Sources
    src/object.cpp
)

set(SourcesWrapper
    src/object.cpp
    src/object_wrapper.cpp
)

set(TestSources
    tests/test.cpp
)

set(TestWrapperSources
    tests/test_wrapper.c
)

add_library( Object SHARED ${Sources} )
target_include_directories( Object PUBLIC include)

add_library( ObjectWrapper SHARED ${Sources} ${SourcesWrapper} )
target_include_directories( ObjectWrapper PUBLIC include)

add_executable(tests ${TestSources})
target_link_libraries(tests Object)

add_executable(tests_wrapper ${TestWrapperSources})
target_link_libraries(tests_wrapper ObjectWrapper)

install(TARGETS Object LIBRARY DESTINATION lib )
install(TARGETS tests)
install(TARGETS ObjectWrapper LIBRARY DESTINATION lib )
install(TARGETS tests_wrapper)