sleepdir = $(libdir)/pm-utils/sleep.d

sleep_SCRIPTS =			\
	00logging		\
	01grub			\
	49bluetooth		\
	50ntpd			\
	55battery		\
	55NetworkManager	\
	65alsa			\
	75modules		\
	90chvt			\
	90clock			\
	94cpufreq		\
	95led			\
	98smart-kernel-video 	\
	99video

EXTRA_DIST=$(sleep_SCRIPTS)

install-exec-local:
	-mkdir -p $(DESTDIR)$(sysconfdir)/pm/sleep.d

clean-local :
	rm -f *~
