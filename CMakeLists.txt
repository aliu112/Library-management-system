CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)
find_package(GTest REQUIRED)


SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(main
    main.cpp
    LibraryFacade.cpp
    User.cpp
)

ADD_EXECUTABLE(test
    unit_test.cpp
    User.cpp
)



TARGET_LINK_LIBRARIES(
    test
    gmock
    gtest 
    gtest_main
)

TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)