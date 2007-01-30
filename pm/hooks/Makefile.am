sleepdir = $(sysconfdir)/pm/hooks

sleep_SCRIPTS =			\
	00clear			\
	01grub			\
	05led			\
	10NetworkManager	\
	20video			\
	49bluetooth		\
	50modules		\
	60sysfont		\
	65alsa			\
	90clock			\
	94cpufreq		\
	95led

EXTRA_DIST=$(sleep_SCRIPTS)

clean-local :
	rm -f *~
