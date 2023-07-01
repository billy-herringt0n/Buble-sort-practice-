#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int size, choice;
char n_file[49];
FILE* file;


void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void writeArrayToFile(int arr[], int size) {
    printf("Введите имя файла для загрузки данных в него: ");
    scanf("%s", n_file);
    if (sizeof(n_file) > 49) {
        printf("Имя файла превышает доступное значение (49)!\n");
        return;
    }
    if ((file = fopen(n_file, "w")) == NULL)
    {
        printf("\nНевозможно открыть для записи файл: %s\n", n_file);
        _getch();
        return;
    }
    fprintf(file, "%d\n", size);
    for (int i = 0; i < size; i++)
        fprintf(file, "%d ", arr[i]);

    fclose(file);
    printf("Данные успешно записаны!\n");;
}

void helloScreen() {
    printf("Практическая работа\nНа тему: \"Сортировка пузырьком (bubble sort)\"\n\nВыполнили студенты группы 22ВВВ1: Курушин Ярослав, Николаев Александр, Ганин Иван.\n\n");
    system("PAUSE");
}

void main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    helloScreen();
    clock_t start, end;
    double time_spent = 0.0;
    system("cls");
    printf("Для начала нужно создать массив\n");
    printf("Введите размер массива: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Не удалось выделить память!\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
    printf("Массив создан\n");
    
    do {
        printf("1. Просмотреть массив\n");
        printf("2. Отсортировать массив\n");
        printf("3. Записать массив в файл\n");
        printf("4. Посмотреть время выполнения алгоритма\n");
        printf("5. Выход\n");
        printf("Выберите действие: ");

        scanf("%d", &choice);
        switch (choice) {
        case 1: //Просмотр
            printf("Массив: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 2: // Сортировка
            system("cls");
            start = clock();
            bubbleSort(arr, size);
            end = clock();
            printf("Массив отсортирован!\n");
            time_spent += (double)(end - start) / CLOCKS_PER_SEC;
            printf("\n");
            break;
        case 3: // Запись в файл
            system("cls");
            writeArrayToFile(arr, size);
            break;
        case 4: // Время
            system("cls");
            if (time_spent == 0) {
                printf("Сначала отсортируйте массив!\n");
                break;
            }
             printf("Время выполнения алгоритма: %f\n", time_spent);
             break;
        case 5: // Выход
             system("cls");
             printf("До свидания!\n");
             //free(arr);
             break;
        default:
             system("cls");
             printf("Некорректный выбор!\n");
             break;
        }
    } while (choice != 5);

    getchar();
}