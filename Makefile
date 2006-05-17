VERSION:=0.18.0

CFLAGS= $(RPM_OPT_FLAGS) -Wall -Werror
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

ifeq ($(VERSION), HEAD)
	CVSTAG ?= HEAD
else
	CVSTAG ?= pm-utils-$(subst .,-,$(VERSION))
endif

all: pm-pmu

pm-pmu: pm-pmu.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

install: all
	install -m 755 -d $(sbindir)
	install -m 755 pm-pmu $(sbindir)
	install -m 755 -d $(bindir)
	install -m 755 on_ac_power $(bindir)
	install -m 755 -d $(mandir)/man1
	install -m 644 pm-pmu.1 on_ac_power.1 $(mandir)/man1

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

	install -m 755 -d $(sysconfdir)/pm
	install -m 755 -d $(sysconfdir)/pm/hooks
	install -m 755 -d $(sysconfdir)/pm/config.d
	install -m 755 -d $(sysconfdir)/pm/power.d

	install -m 644 pm.sysconfig $(sysconfdir)/pm/config
	for file in pm/functions* ; do \
		install -m 644 $$file $(sysconfdir)/pm ; \
	done
	for file in pm/hooks/* ; do \
		install -m 755 $$file $(sysconfdir)/pm/hooks ; \
	done
	for file in pm/power.d/* ; do \
		install -m 755 $$file $(sysconfdir)/pm/power.d ; \
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

test-archive: clean
	@if [ "$(origin VERSION)" == "command line" ]; then	\
		$(MAKE) VERSION=$(VERSION) create-archive ;	\
	else							\
		$(MAKE) VERSION=HEAD create-archive ;		\
	fi

clean:

dummy:
