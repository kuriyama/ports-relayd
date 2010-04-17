--- relayd/relayd.h.orig	2010-03-18 14:26:05.000000000 -0700
+++ relayd/relayd.h	2010-03-19 09:09:47.000000000 -0700
@@ -19,10 +19,11 @@
  */
 
 #include <sys/tree.h>
+#include <sys/event.h>
 
 #include <imsg.h>
 
-#define CONF_FILE		"/etc/relayd.conf"
+#define CONF_FILE		"/usr/local/etc/relayd.conf"
 #define RELAYD_SOCKET		"/var/run/relayd.sock"
 #define PF_SOCKET		"/dev/pf"
 #define RELAYD_USER		"_relayd"
@@ -58,6 +59,15 @@
 #define PURGE_PROTOS		0x08
 #define PURGE_EVERYTHING	0xff
 
+#define	SIMPLEQ_HEAD		STAILQ_HEAD
+#define	SIMPLEQ_FIRST		STAILQ_FIRST
+#define	SIMPLEQ_REMOVE_HEAD	STAILQ_REMOVE_HEAD
+#define	SIMPLEQ_ENTRY		STAILQ_ENTRY
+#define	SIMPLEQ_INIT		STAILQ_INIT
+#define	SIMPLEQ_EMPTY		STAILQ_EMPTY
+#define	SIMPLEQ_NEXT		STAILQ_NEXT
+#define	SIMPLEQ_INSERT_TAIL	STAILQ_INSERT_TAIL
+
 #define SNMP_RECONNECT_TIMEOUT	{ 3, 0 }	/* sec, usec */
 
 #if DEBUG > 1
@@ -109,7 +119,7 @@
 	int			 s;
 	int			 af;
 	int			 last_up;
-	struct event		 ev;
+	struct kevent		 ev;
 	struct timeval		 tv_start;
 };
 
@@ -120,7 +130,7 @@
 	struct host		*host;
 	struct table		*table;
 	struct timeval		 tv_start;
-	struct event		 ev;
+	struct kevent		 ev;
 	int			(*validate_read)(struct ctl_tcp_event *);
 	int			(*validate_close)(struct ctl_tcp_event *);
 	SSL			*ssl;
@@ -399,7 +409,7 @@
 	struct ctl_relay_event		 se_out;
 	void				*se_priv;
 	u_int32_t			 se_hashkey;
-	struct event			 se_ev;
+	struct kevent			 se_ev;
 	struct timeval			 se_timeout;
 	struct timeval			 se_tv_start;
 	struct timeval			 se_tv_last;
@@ -560,7 +570,7 @@
 	struct host		*rl_dsthost[RELAY_MAXHOSTS];
 	int			 rl_dstnhosts;
 
-	struct event		 rl_ev;
+	struct kevent		 rl_ev;
 
 	SSL_CTX			*rl_ssl_ctx;
 	char			*rl_ssl_cert;
@@ -647,7 +657,7 @@
 	struct timeval		 sc_timeout;
 	struct table		 sc_empty_table;
 	struct protocol		 sc_proto_default;
-	struct event		 sc_ev;
+	struct kevent		 sc_ev;
 	struct tablelist	*sc_tables;
 	struct rdrlist		*sc_rdrs;
 	struct protolist	*sc_protos;
@@ -658,12 +668,12 @@
 	char			 sc_demote_group[IFNAMSIZ];
 	u_int16_t		 sc_id;
 
-	struct event		 sc_statev;
+	struct kevent		 sc_statev;
 	struct timeval		 sc_statinterval;
 
 	int			 sc_snmp;
-	struct event		 sc_snmpto;
-	struct event		 sc_snmpev;
+	struct kevent		 sc_snmpto;
+	struct kevent		 sc_snmpev;
 
 	int			 sc_has_icmp;
 	int			 sc_has_icmp6;
@@ -681,7 +691,7 @@
 
 /* initially control.h */
 struct {
-	struct event	 ev;
+	struct kevent	 ev;
 	int		 fd;
 } control_state;
 
@@ -693,7 +703,7 @@
 struct imsgev {
 	struct imsgbuf		 ibuf;
 	void			(*handler)(int, short, void *);
-	struct event		 ev;
+	struct kevent		 ev;
 	void			*data;
 	short			 events;
 };
@@ -882,7 +892,7 @@
 struct table	*table_findbyname(struct relayd *, const char *);
 struct table	*table_findbyconf(struct relayd *, struct table *);
 struct rdr	*rdr_findbyname(struct relayd *, const char *);
-void		 event_again(struct event *, int, short,
+void		 event_again(struct kevent *, int, short,
 		    void (*)(int, short, void *),
 		    struct timeval *, struct timeval *, void *);
 struct relay	*relay_find(struct relayd *, objid_t);
