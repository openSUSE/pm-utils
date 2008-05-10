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

install-data-hook:
	-mkdir -p $(DESTDIR)$(mandir)/man8
	-ln -s pm-action.8 $(DESTDIR)$(mandir)/man8/pm-suspend.8
	-ln -s pm-action.8 $(DESTDIR)$(mandir)/man8/pm-hibernate.8
	-ln -s pm-action.8 $(DESTDIR)$(mandir)/man8/pm-suspend-hybrid.8

clean-local :
	rm -f *~
