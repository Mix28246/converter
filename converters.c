#include "converters.h"

float convert_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float meters_to_kilometers(float m) {
    return m / 1000.0;
}

float liters_to_gallons(float l) {
    return l * 0.264172;
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

