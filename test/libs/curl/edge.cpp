//
// Created by Larry Hsiao on 4/9/2018.
//
#include <gtest/gtest.h>
#include <curl/curl.h>

size_t emptyCallback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    return size*nmemb;
}

TEST(REQUEST, GetFailed_withoutCertfication) {
    CURL* curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://google.com");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    CURLcode response = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    ASSERT_EQ(response ,CURLE_SSL_CACERT);
}

TEST(REQUEST, GetFailed_noCheckingCACert) {
    CURL* curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://google.com");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); // We don`t have CA cert to verify google.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, emptyCallback);
    CURLcode response = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    ASSERT_EQ(response ,CURLE_OK);
}
