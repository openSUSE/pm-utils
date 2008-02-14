pm_libdir = $(libdir)/pm-utils
pm_bindir = $(pm_libdir)/bin
pm_sysconfdir = $(sysconfdir)/pm

pm_bin_PROGRAMS =		\
	pm-pmu			\
	pm-reset-swap

pm_pmu_SOURCES = pm-pmu.c

pm_reset_swap_SOURCES = pm-reset-swap.c

pm_bin_SCRIPTS = pm-action

bin_SCRIPTS = pm-is-supported

dist_bin_SCRIPTS = on_ac_power

sbin_SCRIPTS = pm-powersave

script_in_files = pm-action.in pm-is-supported.in pm-powersave.in

CLEANFILES =  $(script_in_files:.in=)

EXTRA_DIST = $(script_in_files)

do_subst = sed -e 's,[@]PM-UTILS-LIBDIR[@],$(pm_libdir),g' \
	   -e 's,[@]PM-UTILS-SYSCONFDIR[@],$(pm_sysconfdir),g'

SUFFIXES = .in

.in:
	$(do_subst) $< >$@
	chmod +x $@

install-data-hook:
	-mkdir -p $(DESTDIR)$(sbindir)
	-ln -s $(pm_bindir)/pm-action $(DESTDIR)$(sbindir)/pm-suspend
	-ln -s $(pm_bindir)/pm-action $(DESTDIR)$(sbindir)/pm-hibernate
	-ln -s $(pm_bindir)/pm-action $(DESTDIR)$(sbindir)/pm-suspend-hybrid

clean-local :
	rm -f *~
