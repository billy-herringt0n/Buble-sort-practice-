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
    printf("������ ������� ��������!\n");
}
void readArrayFromFile() {
    printf("������� ��� ����� ��� �������� ������ �� ����: ");
    scanf("%s", n_file);
    if (sizeof(n_file) > 49) {
        printf("��� ����� ��������� ��������� �������� (49)!");
        return;
    }
    if ((file = fopen(n_file, "r+")) == 0)
    {
        printf("���������� ������� ���� ��� ������ %s\n", n_file);
        _getch();
        return;
    }
    fscanf(file, "%d", &size);
    arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
    printf("������ ������� ���������!\n");
}

void helloScreen() {
    printf("\t������������ ������\n�� ����: \"���������� ��������� (bubble sort)\"\n\n��������� �������� ������ 22���1: ������� �������, �������� ���������, ����� ����.\n\n");
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
        printf("\t����\n");
        printf("1. ����������� ������\n");
        printf("2. ������������� ������\n");
        printf("3. �������� ������ � ����\n");
        printf("4. ��������� ������ �� �����\n");
        printf("5. ���������� ����� ���������� ���������\n");
        printf("6. ������� ����� ������\n");
        printf("7. �����\n");
        printf("�������� ��������: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: //��������
            system("cls");
            printf("������:\n ");
            for (int i = 0; i < size; i++) {
                printf("%d) %d\n ", i+1, arr[i]);
            }
            printf("\n");
            break;
        case 2: // ����������
            system("cls");
            if (arr == 0) {
                printf("������� �������� ������!\n");
                break;
            }
            start = clock();
            bubbleSort(arr, size);
            end = clock();
            printf("������ ������������!\n");
            time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("\n");
            break;
        case 3: // ������ � ����
            system("cls");
            if (arr == 0) {
                printf("������� �������� ������!\n");
                break;
            }
            writeArrayToFile(arr, size);
            break;
        case 4: // ������ �� �����
            system("cls");
            if (arr != NULL) 
            {
                free(arr);
            }
            readArrayFromFile();
            break;
        case 5: // �����
            system("cls");
            if (time_spent == 0) {
                printf("������� ������������ ������!\n");
                break;
            }
             printf("����� ���������� ���������: %f\n", time_spent);
             break;
        case 6: //���� ������ 
            system("cls");
            free(arr);
            printf("������� ������ �������: ");
            scanf("%d", &size);
            arr = (int*)malloc(size * sizeof(int));
            if (arr == NULL) {
                printf("�� ������� �������� ������!\n");
                return;
            }
            for (int i = 0; i < size; i++) {
                arr[i] = rand();
            }
            break;
        case 7: // �����
             system("cls");
             printf("�� ��������!\n");
             free(arr);
             break;
        default:
             system("cls");
             printf("������������ �����!\n");
             break;
        }
    } while (choice != 7);

    getchar();
}