/* $CORTO_GENERATED
 *
 * Service.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/httprouter/httprouter.h>

corto_int16 _httprouter_Service_onRequest(
    httprouter_Service this,
    server_HTTP_Connection c,
    server_HTTP_Request *r,
    corto_string uri)
{
/* $begin(corto/httprouter/Service/onRequest) */
    corto_string resultStr = NULL;
    corto_any result = {corto_type(corto_string_o), &resultStr, FALSE};
    corto_any param = {corto_type(server_HTTP_Request_o), r, FALSE};
    corto_route route = NULL;

    if (corto_router_match(this, uri, param, result, &route)) {
        corto_debug("web: request '%s' not matched to routes in '%s' of type '%s'", 
            r->uri, 
            corto_fullpath(NULL, this),
            corto_fullpath(NULL, corto_typeof(this)));
        corto_lasterr(); /* Don't report error */
        goto nomatch;
    } else {
        corto_debug("httprouter: matched '%s' with '%s'", r->uri, corto_fullpath(NULL, route));
        if (resultStr) {
            server_HTTP_Request_reply(r, resultStr);
            corto_dealloc(resultStr);
        }
    }

    return 1;
nomatch:
    return 0;
/* $end */
}
