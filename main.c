#include <stdio.h>
#include "converters.h"

void print_menu() {
    printf("\n=== УНИВЕРСАЛЬНЫЙ КОНВЕРТЕР===\n");
    printf("1. Цельсии -> Фаренгейты\n");
    printf("2. Метры -> Километры\n");
    printf("3. Литры -> Галлоны\n");
    printf("4. Км/ч -> М/с\n");
    printf("5. Джоули -> Калории\n");
    printf("6. Часы -> Минуты\n");
    printf("7. ГБ -> МБ\n");
    printf("8. PSI -> Бар (давление)\n");
    printf("9. Градусы -> Радианы\n");
    printf("10. Рубли -> Доллары\n");
    printf("11. Случайное преобразование\n");  // Добавлено
    printf("0. Выход\n");
    printf("Выберите действие: ");
}

int main() {
    int choice;
    float value;

    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) break;
        if (choice == 0) break;

        if (choice == 11) {
            random_conversion();
            continue;
        }

        printf("Введите значение: ");
        scanf("%f", &value);

        switch (choice) {
            case 1: printf("Результат: %.2f F\n", convert_to_fahrenheit(value)); break;
            case 2: printf("Результат: %.3f KM\n", meters_to_kilometers(value)); break;
            case 3: printf("Результат: %.2f Gal\n", liters_to_gallons(value)); break;
            case 4: printf("Результат: %.2f M/S\n", kmh_to_ms(value)); break;
            case 5: printf("Результат: %.2f Cal\n", joules_to_calories(value)); break;
            case 6: printf("Результат: %.0f Min\n", hours_to_minutes(value)); break;
            case 7: printf("Результат: %.0f MB\n", gb_to_mb(value)); break;
            case 8: printf("Результат: %.2f Bar\n", psi_to_bar(value)); break;
            case 9: printf("Результат: %.4f Rad\n", degrees_to_radians(value)); break;
            case 10: printf("Результат: %.2f $\n", rubles_to_dollars(value)); break;
            default: printf("Неверный выбор!\n");
        }
    }

    printf("Программа завершена.\n");
    return 0; 
}