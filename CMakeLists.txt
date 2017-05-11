cmake_minimum_required (VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project (fucker_sql)
subdirs (./jyc_lib)
include_directories(
	./jyc_lib
	./)
#file(GLOB SOURCES
#	  ./*.hpp
#	  ./*.cpp)


add_executable(fucker_sql ./main.cpp  ./fsql_define.cpp ./fksql.cpp ./fsql_keyword.cpp ./fsql_token.cpp)

target_link_libraries(fucker_sql jyc_lib)




