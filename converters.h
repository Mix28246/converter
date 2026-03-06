#ifndef CONVERTERS_H
#define CONVERTERS_H

// Температура и расстояние
float convert_to_fahrenheit(float celsius);
float meters_to_kilometers(float m);

// Объем и скорость
float liters_to_gallons(float l);
float kmh_to_ms(float kmh);

// Энергия и время
float joules_to_calories(float j);
float hours_to_minutes(float h);

// Данные, давление
float gb_to_mb(float gb);
float psi_to_bar(float psi);

// Углы и деньги
float degrees_to_radians(float deg);
float rubles_to_dollars(float r);

// Рандом
float random_conversion(void);

#endif