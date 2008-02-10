SUBDIRS =		\
	sleep.d 	\
	power.d		\
	module.d

extradir = $(libdir)/pm-utils
pm_sysconfdir = $(sysconfdir)/pm

extra_SCRIPTS =			\
	functions		\
	defaults

CLEANFILES = functions

EXTRA_DIST =			\
	$(extra_SCRIPTS)

install-exec-local:
	-mkdir $(DESTDIR)$(sysconfdir)/pm/config.d

do_subst = sed -e 's,[@]PM-UTILS-LIBDIR[@],$(extradir),g' \
	   -e 's,[@]PM-UTILS-SYSCONFDIR[@],$(pm_sysconfdir),g'

SUFFIXES = .in

.in:
	$(do_subst) $< >$@
	chmod +x $@

clean-local :
	rm -f *~
