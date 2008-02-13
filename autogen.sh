#! /bin/sh
# Run this to generate all the initial makefiles, etc.

srcdir=`dirname $0`
test -z "$srcdir" && srcdir=.

ORIGDIR=`pwd`
cd "$srcdir"

if ! type autoreconf >/dev/null 2>&1; then
	echo "**Error**: Missing \`autoreconf' program." >&2
	echo "You will need the autoconf and automake packages." >&2
	echo "You can download them from ftp://ftp.gnu.org/pub/gnu/." >&2
	exit 1
fi

autoreconf -v --install || exit 1
cd "$ORIGDIR" || exit $?

if test "x$NOCONFIGURE" = x; then
	"$srcdir"/configure --enable-maintainer-mode "$@"
fi
