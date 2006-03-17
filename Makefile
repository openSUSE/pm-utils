VERSION:=0.16

CFLAGS= $(RPM_OPT_FLAGS) -Wall -D_GNU_SOURCE -g
LDFLAGS = 

prefix=$(DESTDIR)/usr
sysconfdir=$(DESTDIR)/etc
bindir=$(prefix)/bin
sbindir=$(prefix)/sbin
datadir=$(prefix)/share
mandir=$(datadir)/man
includedir=$(prefix)/include
libdir=$(prefix)/lib

CVSROOT:=$(shell cat CVS/Root 2>/dev/null || :)

CVSTAG = pm-utils-$(subst .,-,$(VERSION))

all: on_ac_power

ON_AC_POWER_CFLAGS:=$(shell pkg-config --cflags --libs hal)

on_ac_power: on_ac_power.c
	$(CC) -o $@ $(CFLAGS) $(ON_AC_POWER_CFLAGS) $<

install:
	install -m 755 -d $(bindir)
	install -m 755 on_ac_power $(bindir)
	install -m 755 -d $(mandir)/man1
	install -m 644 on_ac_power.1 $(mandir)/man1

	ln -s poweroff $(bindir)/pm-shutdown
	ln -s reboot $(bindir)/pm-restart

	ln -s consolehelper $(bindir)/pm-suspend
	ln -s consolehelper $(bindir)/pm-hibernate
	ln -s consolehelper $(bindir)/pm-powersave

	install -m 755 -d $(sbindir)
	install -m 755 pm-powersave $(sbindir)
	install -m 755 pm-action $(sbindir)
	ln -s pm-action $(sbindir)/pm-suspend
	ln -s pm-action $(sbindir)/pm-hibernate

	install -m 755 -d $(sysconfdir)/pam.d
	install -m 755 -d $(sysconfdir)/security/console.apps
	install -m 755 -d $(sysconfdir)/pm
	install -m 755 -d $(sysconfdir)/pm/hooks
	install -m 755 -d $(sysconfdir)/sysconfig
	install -m 644 pm-suspend.pam $(sysconfdir)/pam.d/pm-suspend
	install -m 644 pm-suspend.app $(sysconfdir)/security/console.apps/pm-suspend
	install -m 644 pm-hibernate.pam $(sysconfdir)/pam.d/pm-hibernate
	install -m 644 pm-hibernate.app $(sysconfdir)/security/console.apps/pm-hibernate
	install -m 644 pm-powersave.pam $(sysconfdir)/pam.d/pm-powersave
	install -m 644 pm-powersave.app $(sysconfdir)/security/console.apps/pm-powersave

	install -m 644 pm.sysconfig $(sysconfdir)/sysconfig/pm
	for file in pm/functions* ; do \
		install -m 644 $$file $(sysconfdir)/pm ; \
	done
	for file in pm/hooks/* ; do \
		install -m 755 $$file $(sysconfdir)/pm/hooks ; \
	done

tag-archive:
	@cvs -Q tag -F $(CVSTAG)

create-archive:
	@rm -rf /tmp/pm-utils
	@cd /tmp ; cvs -Q -d $(CVSROOT) export -r$(CVSTAG) pm-utils || echo "Um... export aborted."
	@mv /tmp/pm-utils /tmp/pm-utils-$(VERSION)
	@cd /tmp ; tar -czSpf pm-utils-$(VERSION).tar.gz pm-utils-$(VERSION)
	@rm -rf /tmp/pm-utils-$(VERSION)
	@cp /tmp/pm-utils-$(VERSION).tar.gz .
	@rm -f /tmp/pm-utils-$(VERSION).tar.gz
	@echo ""
	@echo "The final archive is in pm-utils-$(VERSION).tar.gz"

archive: clean tag-archive create-archive

clean:
	rm -f *.o on_ac_power

dummy:
