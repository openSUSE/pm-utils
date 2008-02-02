pm_utils_libdir = $(libdir)/pm-utils
pm_utils_bindir = $(pm_utils_libdir)/bin
pm_sysconfdir = $(sysconfdir)/pm

pm_utils_bin_PROGRAMS =		\
	pm-pmu			\
	pm-reset-swap

pm_utils_bin_SCRIPTS =		\
	pm-action

pm_utils_usr_bindir = $(bindir)

pm_utils_usr_bin_SCRIPTS =	\
	pm-is-supported

pm_pmu_SOURCES = 		\
	pm-pmu.c

pm_reset_swap_SOURCES = 	\
	pm-reset-swap.c

extradir = $(sbindir)

extra_SCRIPTS =			\
	pm-powersave

acpowerdir = $(bindir)

acpower_SCRIPTS =		\
	on_ac_power

do_subst = sed -e 's,[@]PM-UTILS-LIBDIR[@],$(pm_utils_libdir),g' \
	   -e 's,[@]PM-UTILS-SYSCONFDIR[@],$(pm_sysconfdir),g'

SUFFIXES = .in

.in:
	$(do_subst) $< >$@
	chmod +x $@

install-data-hook:
	-mkdir -p $(DESTDIR)$(sbindir)
	-ln -s $(pm_utils_bindir)/pm-action $(DESTDIR)$(sbindir)/pm-suspend
	-ln -s $(pm_utils_bindir)/pm-action $(DESTDIR)$(sbindir)/pm-hibernate
	-ln -s $(pm_utils_bindir)/pm-action $(DESTDIR)$(sbindir)/pm-suspend-hybrid

EXTRA_DIST =				\
	$(extra_SCRIPTS)		\
	$(acpower_SCRIPTS)		\
	$(pm_utils_bin_SCRIPTS)		\
	$(pm_utils_usr_bin_SCRIPTS)

clean-local :
	rm -f *~
