project(Leap)
set(SOURCE LeapYear.hpp)
set(TESTSOURCE test.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE} ${TESTSOURCE})