/* This is a managed file. Do not delete this comment. */

#include <corto/httprouter/httprouter.h>

int16_t httprouter_Service_onRequest(
    httprouter_Service this,
    httpserver_HTTP_Connection c,
    httpserver_HTTP_Request *r,
    const char *uri)
{
    corto_log_push("httprouter");

    corto_string resultStr = NULL;
    corto_any result = {corto_type(corto_string_o), &resultStr, FALSE};
    corto_any param = {corto_type(httpserver_HTTP_Request_o), r, FALSE};
    corto_route route = NULL;
    corto_debug("match uri '%s' to routes of '%s'",
        uri,
        corto_fullpath(NULL, this));

    if (corto_router_match(this, uri, param, result, &route)) {
        corto_debug("request '%s' not matched to routes in '%s' of type '%s'",
            r->uri,
            corto_fullpath(NULL, this),
            corto_fullpath(NULL, corto_typeof(this)));
        corto_lasterr(); /* Don't report error */
        goto nomatch;
    } else {
        if (httpserver_HTTP_Request_getStatus(r) < 400) {
            corto_trace("matched '%s' with '%s'", uri, corto_fullpath(NULL, route));
            if (resultStr) {
                httpserver_HTTP_Request_reply(r, resultStr);
                corto_debug("result: '%s'", resultStr);
                corto_dealloc(resultStr);
            }

        } else {
            /* If route returned a 404, router did not match */
            goto nomatch;
        }

    }

    corto_log_pop();
    return 1;
nomatch:
    corto_log_pop();
    return 0;
}

int16_t httprouter_Service_construct(
    httprouter_Service this)
{
    httpserver_Service(this)->redirectEndpointToPath = true;
    return corto_super_construct(this);
}
