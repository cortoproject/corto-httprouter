/* This is a managed file. Do not delete this comment. */

#include <corto/httprouter/httprouter.h>

corto_string httprouter_route_defaultAction(
    httprouter_route this,
    httprouter_service service,
    corto_httpserver_HTTP_Request *request)
{
    corto_string result = NULL;

    if (this->file) {
        httprouter_route_fileAction(this, service, request, NULL, this->file);
    }

    return result;
}

corto_string httprouter_route_fileAction(
    httprouter_route this,
    httprouter_service service,
    corto_httpserver_HTTP_Request *request,
    const char *path,
    const char *file)
{
    /* More efficient than loading the entire file into memory */
    char *filePath;
    if (path) {
        if (path[0] != '/') {
            filePath = corto_asprintf("%s/%s/%s", service->path, path, file);
        } else {
            filePath = corto_asprintf("%s/%s", path, file);
        }

    } else {
        filePath = corto_asprintf("%s/%s", service->path, file);
    }

    if (corto_file_test("%s", filePath)) {
        corto_trace("serve file '%s'", filePath);
        httpserver_HTTP_Request_sendfile(request, filePath);
    } else {
        corto_warning("file '%s' not found", filePath);
        httpserver_HTTP_Request_setStatus(request, 404);
    }

    corto_dealloc(filePath);
    return NULL;
}
