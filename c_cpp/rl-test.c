#include <stdio.h>
#include <stdlib.h>
#if defined(__i386__)
/*http://blog.sina.com.cn/s/blog_593af2a701012kgs.html*/
static __inline__ unsigned long long rdtsc(void)
{
    unsigned long long int x;
    __asm__ volatile ("rdtsc" : "=A" (x));
    return x;
}
#elif defined(__x86_64__)
static __inline__ unsigned long long rdtsc(void)
{
    unsigned hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

#endif

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("./some_file_with_many_line", "r");
    if (fp == NULL)
    exit(EXIT_FAILURE);
    int start;
    int end;
    int i=0;
    start = rdtsc();
    while ((read = getline(&line, &len, fp)) != -1) {
    end = rdtsc();
    printf("%dth\t the time cost for read a line %d\n",i++,end - start);
    start = rdtsc();
    }
    if (line)
    free(line);
    exit(EXIT_SUCCESS);
}
