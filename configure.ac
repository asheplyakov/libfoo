AC_INIT([libfoo], 0.0.1)
AC_PREREQ(2.59)
AC_CONFIG_SRCDIR(src/foo.cpp)
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_HEADERS([config/config.h])
AC_CONFIG_MACRO_DIR(m4)
AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_PROG_CXX
AC_PROG_INSTALL
AM_PROG_LIBTOOL

# Shared library ABI versioning. When making releases do
# 1. libfoo_LT_REVISION++
# 2. On a backward compatible ABI change:
#    libfoo_LT_CURRENT++;
#    libfoo_LT_AGE++;
#    libfoo_LT_REVISION = 0;
# 3. On an INCOMPATIBLE ABI change:
#    libfoo_LT_CURRENT++;
#    libfoo_LT_AGE = libfoo_LT_REVISION = 0;
#
# See https://community.kde.org/Policies/Binary_Compatibility_Issues_With_C%2B%2B#Note_about_ABI
# too find out what might cause a C++ library ABI changes
libfoo_LT_CURRENT=3
libfoo_LT_AGE=0
libfoo_LT_REVISION=0
libfoo_LT_VERSION="$libfoo_LT_CURRENT:$libfoo_LT_REVISION:$libfoo_LT_AGE"
AC_SUBST(libfoo_LT_VERSION)

AC_CONFIG_FILES([
Makefile
])
AC_OUTPUT

