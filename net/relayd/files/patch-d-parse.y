--- relayd/parse.y.orig	2010-03-18 17:14:18.000000000 -0700
+++ relayd/parse.y	2010-03-18 17:15:45.000000000 -0700
@@ -1490,10 +1490,12 @@
 				    router->rt_conf.name);
 				YYERROR;
 			}
+#ifndef __FreeBSD__
 			if ($2 < 0 || $2 > RT_TABLEID_MAX) {
 				yyerror("invalid rtable id %d", $2);
 				YYERROR;
 			}
+#endif
 			router->rt_conf.rtable = $2;
 		}
 		| RTLABEL STRING {
@@ -2416,7 +2418,7 @@
 	hints.ai_family = PF_UNSPEC;
 	hints.ai_socktype = SOCK_DGRAM; /* DUMMY */
 	error = getaddrinfo(s, NULL, &hints, &res0);
-	if (error == EAI_AGAIN || error == EAI_NODATA || error == EAI_NONAME)
+	if (error == EAI_AGAIN || error == EAI_NONAME)
 		return (0);
 	if (error) {
 		log_warnx("host_dns: could not parse \"%s\": %s", s,
