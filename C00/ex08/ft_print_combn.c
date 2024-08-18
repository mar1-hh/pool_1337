#include <unistd.h>

void print_arr(char *arr, int size, char c)
{
    int i;

    i = 0;
    if (arr[0] == c)
    {
        while (i < size)
            write(1, &arr[i++], 1);
        return ;
    }
    while (i < size)
        write(1, &arr[i++], 1);
    write(1, ", ", 2);
}

void ft_print_combn(int n)
{
    char    arr[10];
    char    arr_max[10];
    int     i;
    int     flag;

    i = 0;
    while (i < n)
    {
        arr[i] = i + 48;
        arr_max[i] = (10 - n) + i + 48;
        i++;
    }
    print_arr(arr, n, arr_max[0]);
    while (arr[0] != arr_max[0])
    {
        flag = n - 1;
        while (arr[flag] == arr_max[flag])
            flag--;
        i = (arr[flag]) + 1;
        while (flag < n)
            arr[flag++] = i++;
        print_arr(arr, n, arr_max[0]);
    }
}
