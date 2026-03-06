#include "converters.h"
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

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

float random_conversion(void) {
    static int initialized = 0;
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }
    
    float random_value = ((float)rand() / RAND_MAX) * 100.0f;
    
    int random_action = rand() % 10 + 1;
    
    printf("\n=== СЛУЧАЙНОЕ ПРЕОБРАЗОВАНИЕ ===\n");
    printf("Сгенерированное число: %.2f\n", random_value);
    printf("Случайное действие: ");
    
    float result;
    
    switch (random_action) {
        case 1:
            printf("Цельсии -> Фаренгейты\n");
            result = convert_to_fahrenheit(random_value);
            printf("Результат: %.2f F\n", result);
            break;
            
        case 2:
            printf("Метры -> Километры\n");
            result = meters_to_kilometers(random_value);
            printf("Результат: %.3f KM\n", result);
            break;
            
        case 3:
            printf("Литры -> Галлоны\n");
            result = liters_to_gallons(random_value);
            printf("Результат: %.2f Gal\n", result);
            break;
            
        case 4:
            printf("Км/ч -> М/с\n");
            result = kmh_to_ms(random_value);
            printf("Результат: %.2f M/S\n", result);
            break;
            
        case 5:
            printf("Джоули -> Калории\n");
            result = joules_to_calories(random_value);
            printf("Результат: %.2f Cal\n", result);
            break;
            
        case 6:
            printf("Часы -> Минуты\n");
            result = hours_to_minutes(random_value);
            printf("Результат: %.0f Min\n", result);
            break;
            
        case 7:
            printf("ГБ -> МБ\n");
            result = gb_to_mb(random_value);
            printf("Результат: %.0f MB\n", result);
            break;
            
        case 8:
            printf("PSI -> Бар (давление)\n");
            result = psi_to_bar(random_value);
            printf("Результат: %.2f Bar\n", result);
            break;
            
        case 9:
            printf("Градусы -> Радианы\n");
            result = degrees_to_radians(random_value);
            printf("Результат: %.4f Rad\n", result);
            break;
            
        case 10:
            printf("Рубли -> Доллары\n");
            result = rubles_to_dollars(random_value);
            printf("Результат: %.2f $\n", result);
            break;
    }
    
    printf("================================\n");
    return result;
}