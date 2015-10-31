SET(CMAKE_CXX_FLAGS "-std=c++11")

ADD_LIBRARY( CalcCompileLib STATIC
	lexer.cpp
	parser.cpp
	ast.cpp
	symbol.cpp
	)

add_executable (Calc main.cpp)

target_link_libraries(Calc LINK_PUBLIC CalcCompileLib)
