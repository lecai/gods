//
//  main.c
//  http-server
//
//  Created by eacan  on 14-6-1.
//  Copyright (c) 2014 eacan . All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "haywire.h"

#define CRLF "\r\n"

void response_complete(void *userData){

}

void get_root(http_request *request,hw_http_response *response, void *userData){
    hw_string statusCode;
    hw_string contentTypeName;
    hw_string contentTypeValue;
    hw_string body;
    hw_string keepAliveName;
    hw_string keepAliveValue;

    SETSTRING(statusCode, HTTP_STATUS_200);
    hw_set_response_status_code(response, &statusCode);

    SETSTRING(contentTypeName, "Content-Type");

    SETSTRING(contentTypeValue, "text/html");
    hw_set_response_header(response, &contentTypeName, &contentTypeValue);

    SETSTRING(body, "hello world");
    hw_set_body(response, &body);

    if (request->keep_alive)
    {
        SETSTRING(keepAliveName, "Connection");

        SETSTRING(keepAliveValue, "Keep-Alive");
        hw_set_response_header(response, &keepAliveName, &keepAliveValue);
    } else{
        hw_set_http_version(response,1,0);
    }
    hw_http_response_send(response, "userData", response_complete);
}

int main(int argc, const char * argv[])
{

    char stats[] = "/";
    configuration config;
    config.http_listen_address = "0.0.0.0";
    config.http_listen_port = 8600;

    hw_init_with_config(&config);
    hw_http_add_route(stats, get_root, NULL);
    hw_http_open(0);
    return 0;
}

