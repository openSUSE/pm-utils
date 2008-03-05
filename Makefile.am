SUBDIRS = pm man src

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = pm-utils.pc

ChangeLog:
	@-git log --no-merges --topo-order > $@

clean-local :
	rm -f *~
