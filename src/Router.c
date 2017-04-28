/* $CORTO_GENERATED
 *
 * Router.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/httprouter/httprouter.h>

int16_t _httprouter_Router_construct(
    httprouter_Router this)
{
/* $begin(corto/httprouter/Router/construct) */

    if (!corto_interface(this)->base) {
        corto_setref(&corto_interface(this)->base, httprouter_Service_o);
    }

    return corto_super_construct(this);
/* $end */
}

int32_t _httprouter_Router_matchRoute(
    httprouter_Router this,
    corto_route route,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData)
{
/* $begin(corto/httprouter/Router/matchRoute) */
    corto_assert(
      corto_instanceofType(server_HTTP_Request_o, param.type),
      "web/server/Router parameter is not HTTP/Request");

    corto_int32 result = -1;
    server_HTTP_Request *r = param.value;
    corto_bool match = FALSE;

    if ((r->method == Server_Get) && (corto_instanceof(httprouter_GET_o, route))) {
        match = TRUE;
    } else if ((r->method == Server_Post) && (corto_instanceof(httprouter_POST_o, route))) {
        match = TRUE;
    } else if ((r->method == Server_Put) && (corto_instanceof(httprouter_PUT_o, route))) {
        match = TRUE;
    } else if ((r->method == Server_Delete) && (corto_instanceof(httprouter_DELETE_o, route))) {
        match = TRUE;
    }

    if (match) {
        result = x_parser_matchRoute_v(this, route, pattern, param, routerData);
    }

    return result;
/* $end */
}
