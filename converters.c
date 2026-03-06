#include "converters.h"
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

char buf[8192];

size_t write_cb(void *ptr, size_t size, size_t nmemb, void *userp) {
    strncat(buf, ptr, size * nmemb);
    return size * nmemb;
}

float convert_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float meters_to_kilometers(float m) {
    return m / 1000.0;
}

float liters_to_gallons(float l) {
    return l * 0.264172;
}

float kmh_to_ms(float kmh) {
    return kmh / 3.6;
}

float joules_to_calories(float j) {
    return j * 0.238846;
}

float hours_to_minutes(float h) {
    return h * 60.0;
}

float gb_to_mb(float gb) {
    return gb * 1024.0;
}

float psi_to_bar(float psi) {
    return psi * 0.0689476;
}

float degrees_to_radians(float deg) {
    return deg * (3.14159 / 180.0);
}

float rubles_to_dollars(float r) {
    CURL *curl = curl_easy_init();
    buf[0] = 0;
    
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.cbr-xml-daily.ru/daily_json.js");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);
    curl_easy_perform(curl);
    
    char *usd = strstr(buf, "USD");
    char *value = strstr(usd, "Value");
    double kurs;
    sscanf(value, "Value\":%lf", &kurs);
        
    curl_easy_cleanup(curl);    
    return r / kurs;
}