#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int v (char *filename) {
    FILE *file = fopen(filename, "r");
     

    int c = fgetc(file);
    fclose(file);

    if (c == EOF) {
        return 1;
    }
    return 0;
}
void zap_file(char *filen)
{
    FILE *file = fopen(filen, "a");
    if (file == NULL)
    {
        printf("Не вдалося відкрити файл %s\n", filen);
        return;
    }
    

    printf("Введіть числа:\n");
    int num;
    while (1)
    {
        scanf("%d", &num);
        if (num == -1)
        {
            break;
        }
        fprintf(file, "%d\n", num);
    }

    fclose(file);
}

void clear(char *filen)
{
    FILE *file = fopen(filen, "w");
    if (file == NULL)
    {
        printf("Не вдалося відкрити файл\n");
        return;
    }

    fclose(file);
    printf("Файл %s обнулено\n", filen);
}

void obrobka(char *vhid, char *vuhid)
{
    int a[100];
    int num, n = 0;
    FILE *in = fopen(vhid, "r");
    FILE *out = fopen(vuhid, "w");

    if (in == NULL || out == NULL)
    {
        printf("Не вдалося відкрити файл\n");
        return;
    }
    if (v(vhid))
    {
        printf("Файл порожній");
        return;
    }
    
    
    fprintf(out, "Точні квадрати:\n");
    while (fscanf(in, "%d", &num) != EOF)
    {
        if ((int)sqrt(num) * (int)sqrt(num) == num)
        {
            
            fprintf(out, "%d\t", num);
        }
    }
    
    rewind(in);
    while (fscanf(in, "%d", &num) != EOF)
    {
        a[n] = num;
        n++;
    }

    
    fprintf(out, "\nЧисла у зворотньому порядку:\n");
    for (int i = n - 1; i >= 0; i--)
    {
        
        fprintf(out, "%d\t", a[i]);
    }
    
    
    fprintf(out, "\nЧисла без повторень:\n");
    for (int i = 0; i < n; i++)
    {
        int dupl = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                dupl = 1;
                break;
            }
        }
        if (!dupl)
        {
            
            fprintf(out, "%d\t", a[i]);
        }
    }

    fclose(in);
    fclose(out);
}
void vuvid(char *filen) {
    char line[100];
    FILE *file = fopen(filen, "r");

    
    if (file == NULL) {
        printf("Помилка відкриття файлу\n");
        return;
    }

    
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}
void menu()
{
    int h;
    do
    {
        printf("\n1. Додати числа до файлу F.txt\n");
        printf("2. Обробити дані в файлі F.txt та записати результат у файл G.txt\n");
        printf("3. Обнулити файл F.txt\n");
        printf("0. Вийти\n");
        printf("Виберіть номер опції (0-3): ");

        scanf("%d", &h);
        if (h == 1)
        {
            zap_file("F.txt");
        }
        else if (h == 2)
        {
            obrobka("F.txt", "G.txt");
            vuvid("G.txt");
        }
        else if (h == 3)
        {
            clear("F.txt");
        }
        else if (h == 0)
        {
            printf("Вихід з програми\n");
        }
        else
        {
            printf("Неправильний вибір опції\n");
        }
    } while (h != 0);
}

int main(void)
{
    menu();
    return 0;
}
