#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>

char* ver_str(); // returns string representation of current program version

// TODO implement arguments as callbacks, prob wrap in a struct for help etc

int main(int argc, char** argv)
{
    size_t cntdn_secs = 0; // how many seconds to count
    size_t step = 1; // how many ticks between printing the remaining time

    for (int i = 0; i < argc; ++i) {
        //printf("%d: %s\n", i, argv[i]); // TODO - tidy debug code

        if (strcmp("-s", argv[i]) == 0) {
            step = atoi(argv[i+1]); // TODO check bounds, check isdigit
        } else if (strcmp("--version", argv[i]) == 0) {
            printf("v%s\n", ver_str());
            exit(1);
        }
    }

    if(argc < 2) {
        printf("ERROR: not enough arguments provided\n");
        exit(1);
    }

    if(!isdigit(*argv[argc-1])) {
        printf("ERROR: time argument does not appear to be numeric\n");
        exit(1);
    } else {
        cntdn_secs = atoi(argv[argc-1]);
    }



    for (size_t i = 0; cntdn_secs > 0; --cntdn_secs, ++i) {
        if (i % step == 0) { printf("%d\n", cntdn_secs); }
        sleep(1);
    }

    return 0;
}

char* ver_str()
{
    return "0.0.2";
}
