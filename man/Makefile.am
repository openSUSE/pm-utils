pm_mans =			\
	on_ac_power.1		\
	pm-pmu.1

if HAVE_DOCBOOK
man_MANS =			\
	$(pm_mans)
endif

EXTRA_DIST =			\
	on_ac_power.sgml	\
	pm-pmu.sgml		\
	$(pm_mans)

MAINTAINERCLEANFILES =		\
	$(pm_mans)

pm-pmu.1: pm-pmu.sgml
	$(DOCBOOK2MAN) $?

on_ac_power.1: on_ac_power.sgml
	$(DOCBOOK2MAN) $?

clean-local :
	rm -f *~
	rm -f manpage.*
