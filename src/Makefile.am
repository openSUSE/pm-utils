sbin_PROGRAMS =			\
	pm-pmu

pm_pmu_SOURCES = pm-pmu.c

extradir = $(sbindir)

extra_SCRIPTS =			\
	pm-powersave		\
	pm-action		\
	on_ac_power

install-exec-am:
	-ln -s $(sbindir)/pm-action $(sbindir)/pm-suspend
	-ln -s $(sbindir)/pm-action $(sbindir)/pm-hibernate

EXTRA_DIST =			\
	$(extra_SCRIPTS)

clean-local :
	rm -f *~
