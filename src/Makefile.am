pm_utils_bindir = $(libdir)/pm-utils/bin

pm_utils_bin_PROGRAMS =		\
	pm-pmu			\
	pm-reset-swap

pm_utils_bin_SCRIPTS =		\
	pm-action

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

install-exec-hook:
	-mkdir -p $(DESTDIR)$(sbindir)
	-ln -s $(pm_utils_bindir)/pm-action $(DESTDIR)$(sbindir)/pm-suspend
	-ln -s $(pm_utils_bindir)/pm-action $(DESTDIR)$(sbindir)/pm-hibernate

EXTRA_DIST =			\
	$(extra_SCRIPTS)	\
	$(acpower_SCRIPTS)

clean-local :
	rm -f *~
