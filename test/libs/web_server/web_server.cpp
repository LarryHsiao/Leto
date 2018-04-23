//
// Created by Larry Hsiao on 4/12/2018.
//

#include <gtest/gtest.h>
#include <server_http.hpp>
#include <client_http.hpp>
#include <algorithm>

using namespace std;
using namespace SimpleWeb;
using HttpServer=Server<HTTP>;
using HttpClient=Client<HTTP>;

TEST(web_server, server_ok) {
    HttpServer server;
    server.config.port = 9010;
    server.resource["^/string$"]["GET"] = [](shared_ptr<HttpServer::Response> response,
                                             shared_ptr<HttpServer::Request> request) {
        auto content = std::string("This is response");
        *response << "HTTP/1.1 200 OK\r\n"
                  << "Content-Length: " << content.length() << "\r\n\r\n"
                  << content;
    };

    thread thread([&server]() {
        server.start();
    });

    this_thread::sleep_for(chrono::seconds(1));

    HttpClient client("localhost:9010");
    auto response = client.request("GET", "/string");
    auto content = response->content.string();
    server.stop();
    thread.join();
    ASSERT_EQ(string("This is response"), content);
}

TEST(web_server, parameterReceived) {
    std::string parameter;
    HttpServer server;
    server.config.port = 9010;
    server.resource["^/string$"]["GET"] = [&](shared_ptr<HttpServer::Response> response,
                                              shared_ptr<HttpServer::Request> request) {
        parameter = std::string(request->query_string);
        *response << "HTTP/1.1 200 OK\r\n"
                  << "Content-Length: 0" << "\r\n\r\n"
                  << "";
    };

    thread thread([&server]() {
        server.start();
    });

    this_thread::sleep_for(chrono::seconds(1));

    HttpClient client("localhost:9010");
    auto response = client.request("GET", "/string?params=value");
    server.stop();
    thread.join();
    ASSERT_EQ(string("params=value"), parameter);
}

TEST(web_server, parameter_parse) {
    std::string parameterValue;
    HttpServer server;
    server.config.port = 9010;
    server.resource["^/string$"]["GET"] = [&](shared_ptr<HttpServer::Response> response,
                                              shared_ptr<HttpServer::Request> request) {
        auto queryParameter= request->parse_query_string();
        parameterValue = queryParameter.find("params")->second;
        *response << "HTTP/1.1 200 OK\r\n"
                  << "Content-Length: 0" << "\r\n\r\n"
                  << "";
    };

    thread thread([&server]() {
        server.start();
    });

    this_thread::sleep_for(chrono::seconds(1));

    HttpClient client("localhost:9010");
    auto response = client.request("GET", "/string?params=value");
    server.stop();
    thread.join();
    ASSERT_EQ(string("value"), parameterValue);
}