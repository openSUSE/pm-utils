powerdir = $(libdir)/pm-utils/power.d

power_SCRIPTS =			\
	sched-powersave		\
	harddrive		\
	laptop-mode		\
	xfs_buffer		\
	readahead		\
	intel-audio-powersave	\
	wireless 		\
	journal-commit		\
	disable_wol		\
	pcie_aspm		\
	sata_alpm

EXTRA_DIST=$(power_SCRIPTS)

install-exec-local:
	-mkdir -p $(DESTDIR)$(sysconfdir)/pm/power.d

clean-local :
	rm -f *~
