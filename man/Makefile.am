man_MANS =			\
	on_ac_power.1		\
	pm-pmu.1		\
	pm-is-supported.1	\
	pm-powersave.8		\
	pm-action.8

EXTRA_DIST =			\
	on_ac_power.xml		\
	pm-pmu.xml		\
	pm-is-supported.xml	\
	pm-powersave.xml	\
	pm-action.xml		\
	$(man_MANS)

MAINTAINERCLEANFILES =		\
	$(man_MANS)

.xml.1:
	$(XMLTO) man $?

.xml.8:
	$(XMLTO) man $?

clean-local :
	rm -f *~
