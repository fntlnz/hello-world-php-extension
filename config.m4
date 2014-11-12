dnl config.m4 for extension hello_world

PHP_ARG_WITH(hello_world, whether to enable hello world support,
[  --enable-hello-world       Enable hello world])

if test "$PHP_HELLOWORLD" != "no"; then
  PHP_NEW_EXTENSION(hello_world, hello_world.c, $ext_shared)
fi
