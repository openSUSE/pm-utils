SUBDIRS = pm man src

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = pm-utils.pc

EXTRA_DIST = ChangeLog

.PHONY: ChangeLog
ChangeLog:
	@if test -d $(srcdir)/.git; then \
	  echo git --git-dir="$(srcdir)/.git" log > $@; \
	  git --git-dir="$(srcdir)/.git" log > $@; \
	elif test -f $(srcdir)/ChangeLog; then \
	  touch $(srcdir)/$@; \
	else \
	  touch $@; \
	fi

dist-hook: ChangeLog

MAINTAINERCLEANFILES = ChangeLog

clean-local :
	rm -f *~
