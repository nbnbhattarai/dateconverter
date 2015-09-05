#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([dateconverter], [1.0.0], [you@address.com])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/dateconverter.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h getopt.h])
AC_CHECK_HEADERS([curses.h],[],[AC_MSG_ERROR("Could not find curses development files. Please install ncurses-devel")])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.

#AC_CONFIG_FILES([Makefile])
AC_OUTPUT(Makefile src/Makefile)
