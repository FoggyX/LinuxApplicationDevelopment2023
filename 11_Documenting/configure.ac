#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([Roman guesser], [1.0], [foggyx@yandex.ru], [guesser])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN([guesser])
AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_REQUIRE_VERSION(0.21)
GETTEXT_PACKAGE=guesser
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, ["$GETTEXT_PACKAGE"], [Name of the gettext message domain])
ALL_LINGUAS="ru"
AC_CONFIG_SRCDIR([src/guesser.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
IT_PROG_INTLTOOL

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([floor setlocale strcasecmp])

AC_CONFIG_FILES([Makefile src/Makefile po/Makefile.in Doxyfile])
AC_OUTPUT
