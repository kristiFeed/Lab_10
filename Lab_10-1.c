#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int v(FILE *filen)
{

    int c = fgetc(filen);
    if (c == EOF)
        return 1;
    ungetc(c, filen);
    return 0;
}
void clear(char *sub)
{

    char filen[100];

    snprintf(filen, sizeof(filen), "%s.txt", sub);

    FILE *file = fopen(filen, "w");
    if (file != NULL)
    {
        fclose(file);
        printf("Файл %s обнулено\n", filen);
    }
    else
    {
        printf("Не вдалося відкрити файл\n");
    }
}

void add(char *sub)
{
    char name[100];
    int ocinka;
    char filen[104];

    snprintf(filen, sizeof(filen), "%s.txt", sub);
    FILE *file = fopen(filen, "a");

    if (file == NULL)
    {
        printf("Неможливо відкрити файл %s\n", filen);
        return;
    }

    printf("Введіть і'мя \n");
    scanf("%s", name);
    printf("Введіть оцінку \n");
    scanf("%d", &ocinka);
    fprintf(file, "%s %d\n", name, ocinka);
    fclose(file);
    printf("Результат додан\n");
}

void res(char *sub)
{

    char filen[104];
    char line[200];

    snprintf(filen, sizeof(filen), "%s.txt", sub);

    FILE *file = fopen(filen, "r");
    if (file == NULL)
    {
        printf("Не вдалося відкрити файл\n");
        return;
    }
    if (v(file))
    {
        printf("Файл порожній\n");
        return;
    }

    printf("Результат іспиту %s\n", sub);
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }
    fclose(file);
}
void menu()
{
    int h;
    char sub[100];
    do
    {
        printf("\n1. Додати результат іспиту\n");
        printf("2. Прочитати результати іспиту\n");
        printf("3. Обнулити файл\n");
        printf("0. Вийти\n");
        printf("Виберіть номер (0-3): ");

        scanf("%d", &h);
        if (h == 1)
        {
            printf("Введіть назву предмету \n");
            scanf("%s", &sub);
            add(sub);
        }
        else if (h == 2)
        {
            printf("Введіть назву предмету \n");
            scanf("%s", &sub);
            res(sub);
        }
        else if (h == 3)
        {
            printf("Введіть назву файла\n");
            scanf("%s", &sub);
            clear(sub);
        }
        else if (h == 0)
        {
            printf("Вихід з програми");
        }
        else
        {
            printf("Неправильна цифра");
        }
    } while (h != 0);
}

int main(void)
{
    menu();
}