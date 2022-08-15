#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

void* sqrt(double **arr)
{

}


int main()
{
    int N, M;
    printf("Please enter how many vectors would you like:");
    scanf("%d", &N);
    printf("Please enter how many elemens a vector has:");
    scanf("%d", &M);
    double** vectors = malloc(sizeof(double) * N);
    for(int i = 0; i < N; i++)
    {
        vectors[i] = malloc(sizeof(double) * M);
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%lf", &vectors[i][j]);
        }
    }

    pthread_t* p = malloc(sizeof(pthread_t) * THREAD_COUNT + 1);
    for(int i = 1; i <= THREAD_COUNT; i++)
    {
        /*if(pthread_create(&p[i], NULL, &sqrt, vectors) != 0) {
            return i;
        }*/

    }
    double in_the_sqrt = 0, result, numbers;;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            numbers = vectors[i][j];
            in_the_sqrt += numbers * numbers;
        }
        //result = sqrt(in_the_sqrt);
        printf("%.2lf", result);
    }
    return 0;
}