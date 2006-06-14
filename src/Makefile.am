sbin_PROGRAMS =			\
	pm-pmu

pm_pmu_SOURCES = pm-pmu.c

extradir = $(sbindir)

extra_SCRIPTS =			\
	pm-powersave		\
	pm-action

acpowerdir = $(bindir)

acpower_SCRIPTS =		\
	on_ac_power

install-exec-hook:
	-ln -s pm-action $(DESTDIR)$(sbindir)/pm-suspend
	-ln -s pm-action $(DESTDIR)$(sbindir)/pm-hibernate

EXTRA_DIST =			\
	$(extra_SCRIPTS)	\
	$(acpower_SCRIPTS)

clean-local :
	rm -f *~
