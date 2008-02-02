SUBDIRS =  sleep.d power.d

extradir = $(libdir)/pm-utils

extra_SCRIPTS =			\
	functions		\
	defaults

EXTRA_DIST =			\
	$(extra_SCRIPTS)

install-exec-local:
	-mkdir $(DESTDIR)$(sysconfdir)/pm/config.d

do_subst = sed -e 's,[@]PM-UTILS-LIBDIR[@],$(extradir),g' \
	   -e 's,[@]PM-UTILS-SYSCONFDIR[@],$(sysconfdir),g'

SUFFIXES = .in

.in:
	$(do_subst) $< >$@
	chmod +x $@

clean-local :
	rm -f *~
