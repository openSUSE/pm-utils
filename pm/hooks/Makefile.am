sleepdir = $(libdir)/pm-utils/sleep.d

sleep_SCRIPTS =			\
	00clear			\
	01grub			\
	05led			\
	10NetworkManager	\
	20video			\
	49bluetooth		\
	50modules		\
	55battery		\
	60sysfont		\
	65alsa			\
	90clock			\
	94cpufreq		\
	95led			\
	99video

EXTRA_DIST=$(sleep_SCRIPTS)

install-exec-local:
	-mkdir -p $(DESTDIR)$(sysconfdir)/pm/sleep.d

clean-local :
	rm -f *~
