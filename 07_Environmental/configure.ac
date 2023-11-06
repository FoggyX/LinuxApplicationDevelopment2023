#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([rhasher], [0.00], [foggyx@yandex.ru])
AC_CONFIG_SRCDIR([src/rhasher.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign subdir-objects])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

AC_CHECK_LIB([rhash],[rhash_library_init],[],[AC_MSG_ERROR([Rhash is needed])])
AC_CHECK_LIB([readline],[readline])

# Checks for header files.

AC_CHECK_HEADERS([string.h])
AC_CHECK_HEADERS([ctype.h])
AC_CHECK_HEADERS([errno.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Optional clues

AC_ARG_ENABLE([readline],
	AS_HELP_STRING([--enable-readline], [Enable readline]),
	AC_DEFINE(READLINE,[],[Readline mode])
  )

# Checks for library functions.
AC_CHECK_FUNCS([strcasecmp strerror])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
