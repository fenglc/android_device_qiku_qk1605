cmake_minimum_required(VERSION 3.4.1)

include(GNUInstallDirs)
include(ExternalProject)

add_subdirectory(3rdparty)
ExternalProject_Get_Property(cppdemo INSTALL_DIR )
set(cppdemo_install_dir ${INSTALL_DIR} )

add_library(native-lib
            SHARED
            src/main/cpp/native-lib.cpp)

find_library(log-lib
             log)

add_dependencies(native-lib
            cppdemo)

target_compile_definitions(native-lib
        PRIVATE
        CPPDEMO_STATIC)

target_include_directories(native-lib
        PRIVATE
            ${cppdemo_install_dir}/include)

target_link_libraries(native-lib
                      ${log-lib}
                      ${cppdemo_install_dir}/lib/libcppdemo.a)