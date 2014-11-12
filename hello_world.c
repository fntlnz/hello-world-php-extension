#include "php_hello_world.h"

PHP_FUNCTION (hello_world) {
    char *arg = NULL;
    size_t arg_len, len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
        return;
    }

    char greet[1024];
    strcpy(greet, "Hi ");
    strcat(greet, arg);
    strcat(greet, "!");

    RETURN_STRING(greet, 1);
}

PHP_MINIT_FUNCTION (hello_world) {
    return SUCCESS;
}

const zend_function_entry hello_world_functions[] = {
PHP_FE(hello_world, NULL)
PHP_FE_END };

zend_module_entry hello_world_module_entry = {
STANDARD_MODULE_HEADER,
PHP_HELLO_WORLD_NAME,
hello_world_functions,
PHP_MINIT(hello_world),
NULL,
NULL,
NULL,
NULL,
PHP_HELLO_WORLD_VERSION,
STANDARD_MODULE_PROPERTIES };

#ifdef COMPILE_DL_HELLO_WORLD
ZEND_GET_MODULE(hello_world)
#endif
