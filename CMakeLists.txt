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

# Shared library ABI versioning (Linux/Solaris specific)
# When making a release do
# 1. If ABI hasn't changed since the previous release:
#    foo_PATCHLEVEL++;
# 2. If ABI change since the previous release is backward compatible:
#    foo_REVISION++;
#    foo_PATCHLEVEL = 0;
# 3. If ABI is INCOMPATIBLE with one of the previous release:
#    foo_SOVERSION++;
#    foo_REVISION = foo_PATCHLEVEL = 0;
# Please note: the ABI version has *nothing to do* with the product release version
# See
# https://community.kde.org/Policies/Binary_Compatibility_Issues_With_C%2B%2B#Note_about_ABI
# to find out what causes (in)compatible C++ library ABI changes

set(foo_SOVERSION 0) # SONAME: libfoo.so.0
set(foo_REVISION 1)
set(foo_PATCHLEVEL 0)
set_target_properties(foo PROPERTIES
    SOVERSION ${foo_SOVERSION}
    VERSION ${foo_SOVERSION}.${foo_REVISION}.${foo_PATCHLEVEL}
)

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

