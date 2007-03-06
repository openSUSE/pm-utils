SUBDIRS =  hooks power.d

extradir = $(libdir)/pm-utils

extra_SCRIPTS =			\
	functions		\
	defaults

EXTRA_DIST =			\
	$(extra_SCRIPTS)

install-exec-local:
	-mkdir $(DESTDIR)$(sysconfdir)/pm/config.d

clean-local :
	rm -f *~
