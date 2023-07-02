#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int size, choice;
int* arr = 0;
char n_file[49];
FILE* file;


void bubbleSort(int arr[], int size) {
    int k = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                k = 1;
            }
        }
        if (k == 0) {
            break;
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
    printf("Данные успешно записаны!\n");
}
void readArrayFromFile() {
    printf("Введите имя файла для загрузки данных из него: ");
    scanf("%s", n_file);
    if (sizeof(n_file) > 49) {
        printf("Имя файла превышает доступное значение (49)!");
        return;
    }
    if ((file = fopen(n_file, "r+")) == 0)
    {
        printf("Невозможно открыть файл для чтения %s\n", n_file);
        _getch();
        return;
    }
    fscanf(file, "%d", &size);
    arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
    printf("Данные успешно прочитаны!\n");
}

void helloScreen() {
    printf("\tПрактическая работа\nНа тему: \"Сортировка пузырьком (bubble sort)\"\n\nВыполнили студенты группы 22ВВВ1: Курушин Ярослав, Николаев Александр, Ганин Иван.\n\n");
    system("PAUSE");
}

void main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    helloScreen();
    clock_t start, end;
    double time_spent = 0.0;
    system("cls");
    do {
        printf("\tМеню\n");
        printf("1. Просмотреть массив\n");
        printf("2. Отсортировать массив\n");
        printf("3. Записать массив в файл\n");
        printf("4. Загрузить массив из файла\n");
        printf("5. Посмотреть время выполнения алгоритма\n");
        printf("6. Создать новый массив\n");
        printf("7. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: //Просмотр
            system("cls");
            printf("Массив:\n ");
            for (int i = 0; i < size; i++) {
                printf("%d) %d\n ", i+1, arr[i]);
            }
            printf("\n");
            break;
        case 2: // Сортировка
            system("cls");
            if (arr == 0) {
                printf("Сначала создайте массив!\n");
                break;
            }
            start = clock();
            bubbleSort(arr, size);
            end = clock();
            printf("Массив отсортирован!\n");
            time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("\n");
            break;
        case 3: // Запись в файл
            system("cls");
            if (arr == 0) {
                printf("Сначала создайте массив!\n");
                break;
            }
            writeArrayToFile(arr, size);
            break;
        case 4: // Запись из файла
            system("cls");
            if (arr != NULL) 
            {
                free(arr);
            }
            readArrayFromFile();
            break;
        case 5: // Время
            system("cls");
            if (time_spent == 0) {
                printf("Сначала отсортируйте массив!\n");
                break;
            }
             printf("Время выполнения алгоритма: %f\n", time_spent);
             break;
        case 6: //Ввод данных 
            system("cls");
            free(arr);
            printf("Введите размер массива: ");
            scanf("%d", &size);
            arr = (int*)malloc(size * sizeof(int));
            if (arr == NULL) {
                printf("Не удалось выделить память!\n");
                return;
            }
            for (int i = 0; i < size; i++) {
                arr[i] = rand();
            }
            break;
        case 7: // Выход
             system("cls");
             printf("До свидания!\n");
             free(arr);
             break;
        default:
             system("cls");
             printf("Некорректный выбор!\n");
             break;
        }
    } while (choice != 7);

    getchar();
}