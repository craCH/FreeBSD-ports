--- eval_error.c.orig	2013-06-24 15:03:35.000000000 +0200
+++ eval_error.c	2016-01-10 01:00:43.200335000 +0100
@@ -80,9 +80,9 @@ static void
 error_print(void)
 {
     volatile VALUE errat = Qundef;
-    rb_thread_t *th = GET_THREAD();
-    VALUE errinfo = th->errinfo;
-    int raised_flag = th->raised_flag;
+    rb_thread_t *volatile th = GET_THREAD();
+    volatile VALUE errinfo = th->errinfo;
+    volatile int raised_flag = th->raised_flag;
     volatile VALUE eclass = Qundef, e = Qundef;
     const char *volatile einfo;
     volatile long elen;
