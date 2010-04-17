--- relayd/pfe_filter.c.orig	2010-03-18 14:26:05.000000000 -0700
+++ relayd/pfe_filter.c	2010-03-18 15:34:30.000000000 -0700
@@ -98,6 +98,7 @@
 		    sizeof(tables[i].pfrt_name))
 			goto toolong;
 		tables[i].pfrt_flags |= PFR_TFLAG_PERSIST;
+		log_debug("init_tables: prepare anchor \"%s\" and table \"%s\"", tables[i].pfrt_anchor, tables[i].pfrt_name);
 		i++;
 	}
 	if (i != env->sc_rdrcount)
@@ -314,12 +315,13 @@
 	if (ioctl(env->sc_pf->dev, DIOCRCLRADDRS, &io) == -1)
 		fatal("flush_table: cannot flush table addresses");
 
+#if 0
 	io.pfrio_esize = sizeof(io.pfrio_table);
 	io.pfrio_size = 1;
 	io.pfrio_buffer = &io.pfrio_table;
 	if (ioctl(env->sc_pf->dev, DIOCRCLRTSTATS, &io) == -1)
 		fatal("flush_table: cannot flush table stats");
-
+#endif
 	log_debug("flush_table: flushed table %s", rdr->conf.name);
 	return;
 
@@ -428,8 +430,9 @@
 		rio.rule.dst.port_op = address->port.op;
 		rio.rule.dst.port[0] = address->port.val[0];
 		rio.rule.dst.port[1] = address->port.val[1];
+#if 0
 		rio.rule.rtableid = -1; /* stay in the main routing table */
-
+#endif
 		if (rio.rule.proto == IPPROTO_TCP)
 			rio.rule.timeout[PFTM_TCP_ESTABLISHED] =
 			    rdr->conf.timeout.tv_sec;
