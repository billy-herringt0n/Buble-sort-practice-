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
    printf("������� ��� ����� ��� �������� ������ � ����: ");
    scanf("%s", n_file);
    if (sizeof(n_file) > 49) {
        printf("��� ����� ��������� ��������� �������� (49)!\n");
        return;
    }
    if ((file = fopen(n_file, "w")) == NULL)
    {
        printf("\n���������� ������� ��� ������ ����: %s\n", n_file);
        _getch();
        return;
    }
    fprintf(file, "%d\n", size);
    for (int i = 0; i < size; i++)
        fprintf(file, "%d ", arr[i]);

    fclose(file);
    printf("������ ������� ��������!\n");;
}

void helloScreen() {
    printf("������������ ������\n�� ����: \"���������� ��������� (bubble sort)\"\n\n��������� �������� ������ 22���1: ������� �������, �������� ���������, ����� ����.\n\n");
    system("PAUSE");
}

void main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    helloScreen();
    clock_t start, end;
    double time_spent = 0.0;
    system("cls");
    printf("��� ������ ����� ������� ������\n");
    printf("������� ������ �������: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("�� ������� �������� ������!\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
    printf("������ ������\n");
    
    do {
        printf("1. ����������� ������\n");
        printf("2. ������������� ������\n");
        printf("3. �������� ������ � ����\n");
        printf("4. ���������� ����� ���������� ���������\n");
        printf("5. �����\n");
        printf("�������� ��������: ");

        scanf("%d", &choice);
        switch (choice) {
        case 1: //��������
            printf("������: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 2: // ����������
            system("cls");
            start = clock();
            bubbleSort(arr, size);
            end = clock();
            printf("������ ������������!\n");
            time_spent += (double)(end - start) / CLOCKS_PER_SEC;
            printf("\n");
            break;
        case 3: // ������ � ����
            system("cls");
            writeArrayToFile(arr, size);
            break;
        case 4: // �����
            system("cls");
            if (time_spent == 0) {
                printf("������� ������������ ������!\n");
                break;
            }
             printf("����� ���������� ���������: %f\n", time_spent);
             break;
        case 5: // �����
             system("cls");
             printf("�� ��������!\n");
             //free(arr);
             break;
        default:
             system("cls");
             printf("������������ �����!\n");
             break;
        }
    } while (choice != 5);

    getchar();
}