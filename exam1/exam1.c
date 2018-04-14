// Exam1
// Name: Hugo Trejo
// 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAX_RATE 0.0775
#define CATALOG_SIZE ((int) (sizeof(catalog) / sizeof(struct item)))
#define maxSkuSize 3

struct item {
    char *sku;
    char *desc;
    double price;
    bool taxable;
};


struct item catalog[] = {
    { .sku = "87465896", .desc = "milk",         .price = 3.59, .taxable = false },
    { .sku = "37485942", .desc = "eggs",         .price = 2.98, .taxable = false },
    { .sku = "37618947", .desc = "bread",        .price = 3.18, .taxable = false },
    { .sku = "09484232", .desc = "ziploc bags",  .price = 1.19, .taxable = true },
    { .sku = "83648591", .desc = "paper towels", .price = 2.76, .taxable = true },
};


int main(void)
{
	float price = 0.00;
	 
	char skuNum[8];
	int quantity;
	double itemTotal[5];
	
	while(scanf("%s %d", skuNum, &quantity) != EOF) // read in string from exam1.input
	{
		for(int i = 0; i < CATALOG_SIZE; i++)
		{
			if(strcmp(skuNum, catalog[i].sku) == 0) // found a matching sku
				{
					//multiply price by quantity here for each item
					itemTotal[i] = catalog[i].price * quantity;
					
					// add tax if it's taxable
					if (catalog[i].taxable)
					{
						itemTotal[i] = itemTotal[i] * TAX_RATE;
					}
				printf("%s", "SKU match!\n");
				}
			else {
				printf("%s", "SKU doesnt match this Item!\n");
			}
			// add up totalrPrice
			price = price + itemTotal[i];

        	}
	}
	price = price / 1.00; 

	// couldn't figure out precision :(....
	printf("$%f \n", price);

    return EXIT_SUCCESS;
}
