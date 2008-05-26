SUBDIRS =		\
	sleep.d 	\
	power.d		\
	module.d

pm_libdir = $(libdir)/pm-utils
pm_sysconfdir = $(sysconfdir)/pm

pm_lib_SCRIPTS = functions pm-functions

dist_pm_lib_DATA = defaults

dist_doc_DATA = HOWTO.hooks	\
	        HOWTO.modules

script_in_files = functions.in pm-functions.in

CLEANFILES =  $(script_in_files:.in=)

EXTRA_DIST =  $(script_in_files)

install-exec-local:
	-mkdir $(DESTDIR)$(sysconfdir)/pm/config.d

do_subst = sed -e 's,[@]PM-UTILS-LIBDIR[@],$(pm_libdir),g' \
	   -e 's,[@]PM-UTILS-SYSCONFDIR[@],$(pm_sysconfdir),g'

SUFFIXES = .in

.in:
	$(do_subst) $< >$@
	chmod +x $@

clean-local :
	rm -f *~
