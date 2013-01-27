AM_CPPFLAGS = -Wall -g -I. -I/usr/local/include

bin_PROGRAMS=main
main_SOURCE=main.c
main_LDFLAGS=-L.

check_PROGRAMS=testsimplesort
testsimplesort_SOURCE=testsimplesort.c
testsimplesort_CFLAGS=-D__DEBUG_UT
testsimplesort_LDFLAGS=-L. -L/usr/local/lib
testsimplesort_LDADD=libmain.la -lcunit

lib_LTLIBRARIES=libmain.la
libmain_la_SOURCES=main.c
libmain_la_CFLAGS=-D__DEBUG_UT
