--- relayd/pfe.c.orig	2010-03-18 17:48:04.000000000 -0700
+++ relayd/pfe.c	2010-03-18 18:06:49.000000000 -0700
@@ -24,7 +24,7 @@
 #include <net/if.h>
 
 #include <errno.h>
-#include <event.h>
+#include <sys/event.h>
 #include <fcntl.h>
 #include <stdlib.h>
 #include <string.h>
@@ -71,7 +71,7 @@
 {
 	pid_t		 pid;
 	struct passwd	*pw;
-	struct event	 ev_sigint;
+	struct kevent	 ev_sigint;
 	struct event	 ev_sigterm;
 	int		 i;
 	size_t		 size;
