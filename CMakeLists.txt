cmake_minimum_required(VERSION 2.6)
project(nlpservice)

set(PROJECT_EXTERNAL_RESOURCE_DIR  ${PROJECT_SOURCE_DIR}/external)

# link path for external tools are here
link_directories(${PROJECT_EXTERNAL_RESOURCE_DIR}/ictclas/lib/linux64/) #ictclas

add_executable(nlpservice 
	server.cpp
	NlpService.cpp
	logging.cpp
	thrift/gen-cpp/NlpService.cpp
	thrift/gen-cpp/nlpservice_types.cpp
	thrift/gen-cpp/nlpservice_constants.cpp
)
target_link_libraries(nlpservice thrift)
target_link_libraries(nlpservice NLPIR opencc)

add_executable(nlpservice_testclient 
	client.cpp
	thrift/gen-cpp/NlpService.cpp
	thrift/gen-cpp/nlpservice_types.cpp
	thrift/gen-cpp/nlpservice_constants.cpp
)
target_link_libraries(nlpservice_testclient thrift)

file(COPY external DESTINATION ${PROJECT_BINARY_DIR})
