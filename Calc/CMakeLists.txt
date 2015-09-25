ADD_LIBRARY( CalcCompileLib STATIC
	Parser.cpp
	)

add_executable (evalCalc EvalCalc.cpp)
add_executable (sExpr SExpr.cpp)
add_executable (postExpr PostExpr.cpp)

target_link_libraries(evalCalc LINK_PUBLIC CalcCompileLib)
target_link_libraries(sExpr LINK_PUBLIC CalcCompileLib)
target_link_libraries(postExpr LINK_PUBLIC CalcCompileLib)
