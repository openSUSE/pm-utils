AC_PREREQ(2.52)

AC_INIT(pm-utils, 1.2.2)
AC_CONFIG_SRCDIR(src)
AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AM_CONFIG_HEADER(config.h)

AC_PROG_CC
AC_PROG_LN_S

dnl ---------------------------------------------------------------------------
dnl - Extra verbose warning switches
dnl ---------------------------------------------------------------------------
CPPFLAGS="$CPPFLAGS -Wall -Werror"

dnl ---------------------------------------------------------------------------
dnl - Debugging switches
dnl ---------------------------------------------------------------------------
CPPFLAGS="$CPPFLAGS -g"

dnl ---------------------------------------------------------------------------
dnl - Manual page build
dnl ---------------------------------------------------------------------------
AC_PATH_PROG(XMLTO, xmlto, no)
AM_CONDITIONAL(HAVE_XMLTO, [test "x$XMLTO" != xno])

dnl ---------------------------------------------------------------------------
dnl - Make paths available for source files
dnl ---------------------------------------------------------------------------
AC_SUBST(SYSCONFDIR, $sysconfdir)
AC_SUBST(DATADIR, $datadir)
AC_SUBST(BINDIR, $bindir)
AC_SUBST(SBINDIR, $sbindir)

dnl ---------------------------------------------------------------------------
dnl - Makefiles, etc.
dnl ---------------------------------------------------------------------------
AC_OUTPUT([
Makefile
pm-utils.pc
man/Makefile
src/Makefile
pm/Makefile
pm/sleep.d/Makefile
pm/power.d/Makefile
pm/module.d/Makefile
])

dnl ==========================================================================
echo "
                    pm-utils $VERSION
                  ==================

        prefix:                    ${prefix}
        compiler:                  ${CC}
        cflags:                    ${CFLAGS}
"
