lib_LTLIBRARIES = libfoo.la
bin_PROGRAMS = fooclient

AM_CPPFLAGS = -I$(top_srcdir)/include
AM_CXXFLAGS = -std=c++11

libfoo_la_SOURCES = src/foo.cpp \
		    include/foo/foo.h

libfoo_la_LDFLAGS = -version-info $(libfoo_LT_VERSION)
fooclient_SOURCES = src/fooclient.cpp
fooclient_LDADD = libfoo.la

ACLOCAL_AMFLAGS = -I m4
