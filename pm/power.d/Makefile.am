powerdir = $(libdir)/pm-utils/power.d

power_SCRIPTS =			\
	laptop-tools		\
	sched-powersave

EXTRA_DIST=$(power_SCRIPTS)

install-exec-local:
	-mkdir -p $(DESTDIR)$(sysconfdir)/pm/power.d

clean-local :
	rm -f *~
