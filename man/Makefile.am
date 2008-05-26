pm_mans =			\
	on_ac_power.1		\
	pm-is-supported.1	\
	pm-pmu.8		\
	pm-powersave.8		\
	pm-action.8

if HAVE_XMLTO
man_MANS = $(pm_mans)
endif

EXTRA_DIST =			\
	on_ac_power.xml		\
	pm-pmu.xml		\
	pm-is-supported.xml	\
	pm-powersave.xml	\
	pm-action.xml		\
	$(pm_mans)

MAINTAINERCLEANFILES =		\
	$(pm_mans)

.xml.1:
	$(XMLTO) man $<

.xml.8:
	$(XMLTO) man $<

install-data-hook: install-man
	@if test -f $(DESTDIR)$(mandir)/man8/pm-action.8; then \
	  for page in pm-suspend pm-hibernate pm-suspend-hybrid; do \
	    echo ln -s pm-action.8 $(DESTDIR)$(mandir)/man8/$$page.8; \
	    ln -s pm-action.8 $(DESTDIR)$(mandir)/man8/$$page.8 || exit 1; \
	  done; \
	fi

clean-local :
	rm -f *~
