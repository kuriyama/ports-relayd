--- relayd/relayd.c.orig	2010-03-18 14:26:05.000000000 -0700
+++ relayd/relayd.c	2010-03-18 17:29:19.000000000 -0700
@@ -17,7 +17,7 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
-#include <sys/types.h>
+#include <sys/param.h>
 #include <sys/queue.h>
 #include <sys/socket.h>
 #include <sys/wait.h>
@@ -37,7 +37,7 @@
 #include <unistd.h>
 #include <ctype.h>
 #include <pwd.h>
-#include <sha1.h>
+#include <sha.h>
 #include <md5.h>
 
 #include <openssl/ssl.h>
@@ -1055,7 +1055,7 @@
 {
 	switch (type) {
 	case DIGEST_SHA1:
-		return (SHA1Data(data, len, buf));
+		return (SHA1_Data(data, len, buf));
 		break;
 	case DIGEST_MD5:
 		return (MD5Data(data, len, buf));
@@ -1293,9 +1293,11 @@
 	    bnd->bnd_proto == IPPROTO_TCP ? SOCK_STREAM : SOCK_DGRAM,
 	    bnd->bnd_proto)) == -1)
 		goto fail;
+#ifndef __FreeBSD__
 	if (setsockopt(s, SOL_SOCKET, SO_BINDANY,
 	    &v, sizeof(v)) == -1)
 		goto fail;
+#endif
 	if (bind(s, (struct sockaddr *)&bnd->bnd_ss,
 	    bnd->bnd_ss.ss_len) == -1)
 		goto fail;
