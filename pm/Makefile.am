SUBDIRS =  hooks power.d

extradir = $(sysconfdir)/pm

extra_SCRIPTS =			\
	functions		\
	config

EXTRA_DIST =			\
	$(extra_SCRIPTS)

install-exec-am:
	-mkdir $(sysconfdir)/pm/config.d

clean-local :
	rm -f *~
