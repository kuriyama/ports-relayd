--- relayctl/parser.h.orig	2010-03-18 14:58:32.000000000 -0700
+++ relayctl/parser.h	2010-03-18 14:58:54.000000000 -0700
@@ -44,5 +44,3 @@
 };
 
 struct parse_result	*parse(int, char *[]);
-const struct token      *match_token(const char *, const struct token *);
-void                     show_valid_args(const struct token *);
