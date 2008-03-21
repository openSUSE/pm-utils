EXTRA_DIST = changelog 			\
	     compat 			\
	     control 			\
	     copyright 			\
	     dirs 			\
	     docs 			\
	     pm-utils.doc-base.EX 	\
	     README 			\
	     README.Debian 		\
	     rules

.PHONY: changelog

changelog: Makefile
	git --git-dir="$(srcdir)/../.git" log  --pretty=format:"pm-utils (%ct.%h) unstable; urgency=low%n%n  * %s%n%n -- %an <%ae>  %aD%n" --no-merges >$@

dist-hook: changelog

DISTCLEANFILES = changelog
