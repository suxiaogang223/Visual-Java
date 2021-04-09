cmake_minimum_required(VERSION 3.0.0)
project(Visual-Java VERSION 0.1.0)

include(CTest)
enable_testing()


include_directories(./include)
aux_source_directory(src/gava GAVA_SRC)
aux_source_directory(src/jvm JVM_SRC)
aux_source_directory(src/rtda RTDA_SRC)
aux_source_directory(src/classfile CLASSFILE_SRC)
aux_source_directory(src/rtda/heap HEAP_SRC)
add_executable(gava ${GAVA_SRC} ${JVM_SRC} ${RTDA_SRC} ${CLASSFILE_SRC} ${HEAP_SRC})



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

