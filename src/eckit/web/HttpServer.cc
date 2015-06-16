/*
 * (C) Copyright 1996-2013 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include "eckit/web/HttpServer.h"
#include "eckit/web/HttpService.h"

//-----------------------------------------------------------------------------

namespace eckit {

//-----------------------------------------------------------------------------


HttpServer::HttpServer(int port):
    HtmlResource("/"),
    http_(new HttpService(port))
{
	http_.start();
}

HttpServer::~HttpServer()
{
	http_.stop();
}

//-----------------------------------------------------------------------------

} // namespace eckit

