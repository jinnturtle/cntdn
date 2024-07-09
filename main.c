#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>

int main(int argc, char** argv)
{
    if(argc < 2) {
        printf("ERROR: not enough arguments provided\n");
        exit(1);
    }
    size_t s_to_wait = atoi(argv[1]);
    // TODO handle errors

    for (; s_to_wait > 0; --s_to_wait) {
        printf("%d\n", s_to_wait);
        sleep(1);
    }

    return 0;
}
