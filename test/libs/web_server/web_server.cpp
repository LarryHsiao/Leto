//
// Created by Larry Hsiao on 4/12/2018.
//

#include <gtest/gtest.h>
#include <server_http.hpp>
#include <client_http.hpp>

using namespace std;
using namespace SimpleWeb;
using HttpServer=Server<HTTP>;
using HttpClient=Client<HTTP>;

TEST(web_server, server_ok) {
    HttpServer server;
    server.config.port=9010;
    server.resource["^/string$"]["GET"] = [](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
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
    auto response = client.request("GET","/string");
    auto content = response->content.string();
    server.stop();
    thread.join();
    ASSERT_EQ(string("This is response"), content);
}

