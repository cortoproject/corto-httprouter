/* This is a managed file. Do not delete this comment. */

#include <corto/httprouter/httprouter.h>
corto_string httprouter_route_defaultAction(
    httprouter_route this,
    httprouter_Service service,
    server_HTTP_Request *request)
{
    corto_string result = NULL;

    if (this->file) {
        httprouter_route_fileAction(this, service, request, NULL, this->file);
    }

    return result;
}

corto_string httprouter_route_fileAction(
    httprouter_route this,
    httprouter_Service service,
    server_HTTP_Request *request,
    corto_string path,
    corto_string file)
{

    /* More efficient than loading the entire file into memory */
    char *filePath;
    if (path) {
        corto_asprintf(&filePath, "%s/%s/%s", service->path, path, file);
    } else {
        corto_asprintf(&filePath, "%s/%s", service->path, file);
    }

    if (corto_fileTest("%s", filePath)) {
        server_HTTP_Request_sendfile(request, filePath);
    } else {
        corto_string msg;
        corto_asprintf(&msg, "Resource '%s%s%s' not found", path ? path : "", path ? "/" : "", file);
        corto_error("httprouter: %s", msg);
        server_HTTP_Request_setStatus(request, 404);
        server_HTTP_Request_reply(request, msg);
        corto_dealloc(msg);            
    }
    corto_dealloc(filePath);

    return NULL;
}

