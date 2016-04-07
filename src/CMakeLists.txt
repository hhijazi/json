include_directories(${PROJECT_INCLUDE_DIR})
file(GLOB HEADERS ${PROJECT_INCLUDE_DIR} *.hh)
file(GLOB SOURCES . *.cpp *.cc)

find_package(BISON 2.4 REQUIRED)
set(BISON_OUTPUT ${json_BINARY_DIR}/json.tab.cc)
set(BISON_DEFINES ${json_BINARY_DIR}/json.tab.hh)
include_directories(${json_BINARY_DIR})
if(BISON_FOUND)
	add_custom_command(
		OUTPUT ${BISON_OUTPUT}
		COMMAND ${BISON_EXECUTABLE}
			--defines=${BISON_DEFINES}
			--output=${BISON_OUTPUT}
			${json_SOURCE_DIR}/src/json.y
		DEPENDS ${json_SOURCE_DIR}/src/json.y
		COMMENT "Generating json.tab.hh, json.tab.cc (parser)"
	)
endif(BISON_FOUND)

find_package(FLEX 2.5 REQUIRED)
set(FLEX_OUTPUT ${json_BINARY_DIR}/lex.yy.cc)
if(FLEX_FOUND)
	add_custom_command(
		OUTPUT ${FLEX_OUTPUT}
		COMMAND ${FLEX_EXECUTABLE}
			--outfile=${FLEX_OUTPUT}
			${json_SOURCE_DIR}/src/json.l
		DEPENDS ${json_SOURCE_DIR}/src/json.l
		COMMENT "Generating lex.yy.cc (lexer)"
	)
set_source_files_properties(${FLEX_OUTPUT} PROPERTIES COMPILE_FLAGS "-Wno-deprecated-register")
endif(FLEX_FOUND)

add_library(json ${SOURCES} ${json_BINARY_DIR}/lex.yy.cc ${json_BINARY_DIR}/json.tab.cc ${HEADERS})

add_subdirectory(test)
