#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([GNU Tools Noob Guide], [1.0.0], [maintainer@example.com])
AM_INIT_AUTOMAKE([subdir-objects])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])
# M4 macros specific to this project.
AC_CONFIG_MACRO_DIR([m4-project])

# Add debug option.
AX_CHECK_ENABLE_DEBUG([no], [DEBUG])
AX_CHECK_ENABLE_PEDANTIC([no])

# Checks for programs.
AC_PROG_CC([clang gcc])

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AX_CHECK_COMPILE_FLAG([-std=c11], [CFLAGS+=" -std=c11"],
    [echo -e "\tcompiler needs to support the C11 standard"; exit 1;])

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

echo \
"-------------------------------------------------

 ${PACKAGE_NAME} Version ${PACKAGE_VERSION}

 Prefix: '${prefix}'.
 Variables:
 
 ac_top_srcdir= ${ac_top_srcdir}
 
 -- Compiler
 CC: ${CC}
 CXX: ${CXX}
 CPP: ${CPP}
 CFLAGS: ${CFLAGS}
 CPPFLAGS: ${CPPFLAGS}
 CXXFLAGS: ${CXXFLAGS}

 -- Linker
 LDFLAGS: ${LDFLAGS}
 LIBOBJS: ${LIBOBJS}
 LIBS: ${LIBS}
 LTLIBOBJS: ${LTLIBOBJS}

 Now type 'make @<:@<target>@:>@'
   where the optional <target> is:
     all                - build all binaries

--------------------------------------------------"