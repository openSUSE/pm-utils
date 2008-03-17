SUBDIRS = pm man src

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = pm-utils.pc

EXTRA_DIST = ChangeLog

.PHONY: ChangeLog
ChangeLog:
	git --git-dir="$(srcdir)/.git" log > $@

dist-hook: ChangeLog

DISTCLEANFILES = ChangeLog

clean-local :
	rm -f *~
