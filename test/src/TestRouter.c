/* This is a managed file. Do not delete this comment. */

#include <include/test.h>



#include "MobyDickOrTheWhale.h"


corto_string test_TestRouter_add(
    test_TestRouter this,
    server_HTTP_Request *request,
    test_add *data)
{
    corto_string aStr = server_HTTP_Request_getVar(request, "a");
    corto_string bStr = server_HTTP_Request_getVar(request, "b");
    int a = atoi(aStr);
    int b = atoi(bStr);
    corto_string buffer = ut_asprintf("result = %d", a + b);
    return buffer;
}

corto_string test_TestRouter_addSomething(
    test_TestRouter this,
    server_HTTP_Request *request,
    test_addSomething *data)
{
    ut_error("_test_TestRouter_addSomething 1"); // this is not printed :(
    ut_error("_test_TestRouter_addSomething 2"); // this is not printed :(
    char *buffer = ut_asprintf("Added %s!", data->what);
    ut_error("_test_TestRouter_addSomething 3"); // this is not printed :(
    return buffer;
}

corto_string test_TestRouter_getMessage(
    test_TestRouter this,
    server_HTTP_Request *request,
    test_getMessage *data)
{
    char* message = "Congratulation, this is a message";
    return ut_strdup(message);
}

corto_string test_TestRouter_hello(
    test_TestRouter this,
    server_HTTP_Request *request,
    test_hello *data)
{
    corto_string name = server_HTTP_Request_getVar(request, "name");
    corto_string buffer = ut_asprintf("Hello %s!", name);
    return buffer;
}

corto_string test_TestRouter_index(
    test_TestRouter this,
    server_HTTP_Request *request,
    test_index *data)
{
    return ut_strdup("Congratulations, this is the endpoint /");
}

corto_string test_TestRouter_mobyDick(
    test_TestRouter this,
    server_HTTP_Request *request,
    test_mobyDick *data)
{
    return ut_strdup(MOBY_DICK_OR_THE_WHALE);
}

corto_string test_TestRouter_part1(
    test_TestRouter this,
    server_HTTP_Request *request,
    test_part1 *data)
{
    return ut_strdup("Congratulations, this is the endpoint /part1");
}

corto_string test_TestRouter_part2_part1(
    test_TestRouter this,
    server_HTTP_Request *request,
    test_part2_part1 *data)
{
    return ut_strdup("Congratulations, this is the endpoint /part2/part1");
}

corto_string test_TestRouter_part3_part1(
    test_TestRouter this,
    server_HTTP_Request *request,
    test_part3_part1 *data)
{
    return ut_strdup("Congratulations, this is the endpoint /part3/part1");
}

corto_string test_TestRouter_part3_part2(
    test_TestRouter this,
    server_HTTP_Request *request,
    test_part3_part2 *data)
{
    return ut_strdup("Congratulations, this is the endpoint /part3/part2");
}

corto_string test_TestRouter_post_users(
    test_TestRouter this,
    server_HTTP_Request *request,
    test_post_users *data)
{
    corto_string name = server_HTTP_Request_getVar(request, "name");
    corto_string email = server_HTTP_Request_getVar(request, "email");
    corto_string buffer = ut_asprintf("Created user %s with email %s", name, email);
    return buffer;
}

