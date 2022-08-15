#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct Laptop {
    uint64_t serries_number;
    char name[100];
    double weight;
    double price;
}Laptop;

void enter_laptops(Laptop* laptops, const char** name) {
    for(int i = 0; i < LAPTOPS_COUNT; i++)
    {
        (laptops + i) -> serries_number = i;
        strcpy((laptops + i) -> name , name[rand() % 5]);
        (laptops + i) -> weight = (25 + rand() % (10025 - 25)); 
        (laptops + i) -> price = (10 + rand() % (500010 - 10));
    }
}
void print_laptops(Laptop* laptops)
{
    for(int i = 0; i < LAPTOPS_COUNT; i++)
    {
        printf("Series number: %lu, mark: %s, weighting: %.3lf kg on the price of: %.2lf\n",
        (laptops + i)->serries_number, (laptops + i)->name, (laptops + i)->weight / 1000, (laptops + i)->price / 100);
    }
}

double totalLaptopWeight(Laptop* laptops) {
    double weigth_sum = 0;
    for(int i = 0; i < LAPTOPS_COUNT; i++)
    {
        weigth_sum += ((laptops + i) -> weight / 100);
    }
    return weigth_sum;
}

Laptop *minPriceItem(Laptop* laptops) {
    double min_price = laptops -> price;
    Laptop* laptop_with_min_price = laptops;
    for(int i = 1; i < LAPTOPS_COUNT; i++)
    {
        if(min_price > (laptops + i) -> price){
            min_price = (laptops + i) -> price;
            laptop_with_min_price = (laptops + i);
        }
    }
    return laptop_with_min_price;
}

int main()
{
    srand(time(NULL));
    const char* name_type[] = {"Lenovo", "Asus", "Acer", "Phillips", "VeryCoolLaptop"};
    Laptop* laptops = malloc(sizeof(Laptop) * LAPTOPS_COUNT);
    enter_laptops(laptops, name_type);
    print_laptops(laptops);
    printf("Total weight of all laptops : %.3lf kg\n", totalLaptopWeight(laptops) / 100);
    printf("The laptop with the min price is:\nSeries number: %lu, mark: %s, weighting: %.3lf kg on the price of: %.2lf\n",
        minPriceItem(laptops)->serries_number, minPriceItem(laptops)->name, minPriceItem(laptops)->weight / 1000, minPriceItem(laptops)->price / 100);
    free(laptops);
    return 0;
}