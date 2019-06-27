#include <stdio.h>

struct Computer
{
    char model[20];
    char producer[30];
    float price;
    int year;
};

void enterComputerData(struct Computer *p1);
void showComputerData(struct Computer *p1);

int main()
{
    int n;
    printf("Enter n computers: ");
    scanf("%d",&n);
    struct Computer c1[n];
    for (int i = 0; i < n; i++)
    {
        enterComputerData(&c1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        showComputerData(&c1[i]);
    }
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + c1[i].price;
        
    }
    printf("%.2f", sum/n);
}


void enterComputerData(struct Computer *p1) {
    printf("Enter computer model: ");
    scanf("%s",&p1->model);
    printf("Enter computer producer: ");
    scanf("%s",&p1->producer);
    printf("Enter computer price: ");
    scanf("%f",&p1->price);
    printf("Enter computer year: ");
    scanf("%d",&p1->year);
}

void showComputerData(struct Computer *p1) {
    printf("\nEnter computer model: %s\n", p1->model);
    printf("Enter computer producer: %s\n", p1->producer);
    printf("Enter computer price: %.2f\n", p1->price);
    printf("Enter computer year: %d\n", p1->year);
}