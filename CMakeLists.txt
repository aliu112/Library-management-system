CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(main2
    main2.cpp
    Media.cpp
    Book.cpp
    Category.cpp
)

ADD_EXECUTABLE(test2
    unit_test.cpp
    Media.cpp
    Book.cpp
    Category.cpp
    BookManager.cpp
)

TARGET_LINK_LIBRARIES(
    test2
    gtest 
)

TARGET_COMPILE_DEFINITIONS(test2 PRIVATE gtest_disable_pthreads=ON)