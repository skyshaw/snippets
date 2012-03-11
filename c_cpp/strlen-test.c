/*
 * 两种strlen的实现比较
 * 参考 http://blog.csdn.net/do_fork/article/details/4745862
 * input: 执行多少遍strlen
 * output: (len1, clock1) (len2, clock2) (clock1/clock2)
 *
 */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
size_t strlen1(const char *str) {
    char *e = (char *)str;
    while(*e) e++;
    return e - str;
}
size_t strlen2(const char *str) 
{
    const char *char_ptr;
    const unsigned long int *longword_ptr;
    unsigned long int longword, himagic, lomagic;
    for (char_ptr = str; ((unsigned long int) char_ptr
        & (sizeof (longword) - 1)) != 0; 
            ++char_ptr)  
        if (*char_ptr == '\0')
            return char_ptr - str;
    longword_ptr = (unsigned long int *) char_ptr;
    himagic = 0x80808080L;  
    lomagic = 0x01010101L;  
    if (sizeof (longword) > 4)
    {
        himagic = ((himagic << 16) << 16) | himagic;
        lomagic = ((lomagic << 16) << 16) | lomagic;
    }
    for (;;)
    {
        longword = *longword_ptr++;
        if (((longword - lomagic) & ~longword & himagic) != 0) 
        {
            const char *cp = (const char *) (longword_ptr - 1);
            if (cp[0] == 0)
                return cp - str;
            if (cp[1] == 0)
                return cp - str + 1;
            if (cp[2] == 0)
                return cp - str + 2;
            if (cp[3] == 0)
                return cp - str + 3;
            if (sizeof (longword) > 4)
            {
                if (cp[4] == 0)
                    return cp - str + 4;
                if (cp[5] == 0)
                    return cp - str + 5;
                if (cp[6] == 0)
                    return cp - str + 6;
                if (cp[7] == 0)
                    return cp - str + 7;
            }
        }
    }
}
int main(int argc, char **argv) 
{
    //printf("%ld\n", CLOCKS_PER_SEC);
    const int len = 1000000;
    char* str = malloc((len + 1) * sizeof(char));
    int i = 0;
    for (i = 0; i < len; ++i) 
        str[i] = 'a';
    str[len] = '\0';
    size_t cnt = atoi(argv[1]);
    size_t len1 = 0, len2 = 0;
    long clk1 = 0, clk2 = 0;
    clock_t begin, end;
    begin = clock();
    for (i = 0; i < cnt; ++i)
        len1 = strlen1(str);
    end = clock();
    clk1 = end - begin;

    begin = clock();
    for (i = 0; i < cnt; ++i)
        len2 = strlen2(str);
    end = clock();
    clk2 = end - begin;
    printf("(%d %ld) (%d %ld) (%lf)\n", len1, clk1, len2, 
        clk2, clk1 / (double)(clk2));
    return 0;
}
