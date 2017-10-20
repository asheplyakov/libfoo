cmake_minimum_required(VERSION 3.1)

project(libfoo)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_STANDARD 11)


# make binaries/libraries relocatable
set(_rpath_reloc "$ORIGIN/../lib")

if (NOT DEFINED CMAKE_SKIP_RPATH)
   set(CMAKE_SKIP_RPATH false)
endif()

if (NOT CMAKE_SKIP_RPATH)
   set(_libfoo_rpath "${_rpath_reloc}")
   if (NOT DEFINED CMAKE_INSTALL_RPATH)
       set(CMAKE_INSTALL_RPATH "${_libfoo_rpath}")
   endif()
   if (NOT DEFINED CMAKE_BUILD_WITH_INSTALL_RPATH)
      set(CMAKE_BUILD_WITH_INSTALL_RPATH true)
   endif()
endif()

set(libfoo_SOURCES
    src/foo.cpp
)

set(libfoo_HEADERS
    include/foo/foo.h
)

add_library(foo SHARED ${libfoo_SOURCES})

install(TARGETS foo
	LIBRARY DESTINATION lib
	RUNTIME DESTINATION lib
	ARCHIVE DESTINATION lib
)
install(FILES ${libfoo_HEADERS} DESTINATION include/foo)

set(fooclient_SOURCES
    src/fooclient.cpp
)

add_executable(fooclient ${fooclient_SOURCES})
target_link_libraries(fooclient foo)
install(TARGETS fooclient
	RUNTIME DESTINATION bin
)

