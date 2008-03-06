SUBDIRS = pm man src

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = pm-utils.pc

EXTRA_DIST = ChangeLog

.PHONY: ChangeLog
ChangeLog:
	git log "--git-dir=$(srcdir)" > $@

dist-hook: ChangeLog

DISTCLEANFILES = ChangeLog

clean-local :
	rm -f *~
