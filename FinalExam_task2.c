#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

char checkBit(uint32_t mask, size_t bit) {
    return (!!(mask & (1 << bit)));
}

void* sum(const char* argv) {
        uint32_t mask; 
        int bit_up_count = 0;
        FILE* f = fopen(argv, "r");
        if(f == NULL)
        {
            printf("no such file!\n");
            fclose(f);
        }
        else
        {
            while(fscanf(f, "%d", &mask) != EOF)
            {
                for(int i = 0; i < sizeof(mask) * __CHAR_BIT__; i++) 
                {
                    bit_up_count += checkBit(mask, i);  
                }
            }
            printf("%d\n", bit_up_count);
            fclose(f);
        }
        sleep(1);
        printf("%s - ", argv);
        printf("%d\n", bit_up_count);
}

int main(int argc, char* argv[]) {

    pthread_t* p = malloc(sizeof(pthread_t) * argc);
    uint32_t mask; 
    int bit_up_count;
    int total_count = 0;
    for(int i = 1; i < argc; i++)
    {
        /*if(pthread_create(&p[i], NULL, &sum, argv[i]) != 0) {
            return i;
        }*/
        bit_up_count = 0;
        FILE* f = fopen(argv[i], "r");
        if(f == NULL)
        {
            printf("no such file!\n");
            fclose(f);
        }
        else
        {
            printf("%s - ", argv[i]);
            while(fscanf(f, "%d", &mask) != EOF)
            {
                for(int i = 0; i < sizeof(mask) * __CHAR_BIT__; i++) 
                {
                    bit_up_count += checkBit(mask, i);  
                }
            }
            total_count += bit_up_count;
            printf("%d\n", bit_up_count);
            fclose(f);
        }
    }
    printf("Total bits up: %d\n" , total_count);
    return 0;
}