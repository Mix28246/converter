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