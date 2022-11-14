#include <stdio.h>
#include <stdlib.h>

int pCount = 0;

struct patient
{

    int id;
    char category;
    int days;
};

int addPatient(struct patient pList[]);
int calCharges(struct patient pList[]);

int main()
{

    struct patient pList[2];
    addPatient(pList);
    calCharges(pList);

    return 0;
}

int addPatient(struct patient pList[])
{
    printf("Hospital Managment System\n\n");
    for (int i = 0; i < 2; i++)
    {
        printf("\nInformation of Patient %d\n=======================================\n", i + 1);
        printf("Enter Patient Id :\t\t ");
        scanf("%d", &pList[i].id);
        printf("Enter Patient's Category :\t ");
        scanf("%s", &pList[i].category);
        printf("Enter Number of days to stay :\t ");
        scanf("%d", &pList[i].days);
        pCount++;
    }
    return 0;
}

int calCharges(struct patient pList[])
{

    int rec = 0;
    float cal = 0;
    float cal1 = 0;
    float chargePerDay = 1000;
    float grossCal = 0;
    char chCategory;
    int chdays = 0;
    printf("\nHospital Chargers Calculator \n=======================================\n");
    printf("Enter Patient Id :  \t\t");
    scanf("%d", &rec);
    grossCal = pList[rec - 1].days * chargePerDay;
    chCategory = pList[rec - 1].category;
    chdays = pList[rec - 1].days;
    if (chCategory != 'A' && chdays > 5)
    {
        cal = grossCal * 0.9;
    }
    else if (chCategory != 'A' && chdays < 5)
    {
        cal = grossCal;
    }
    else if (chCategory == 'A' && chdays > 5)
    {
        cal1 = grossCal * 0.9;
        cal = cal1 + (chargePerDay * 0.02);
    }
    else if (chCategory == 'A' && chdays < 5)
    {
        cal1 = grossCal;
        cal = grossCal + (chargePerDay * 0.02);
    }
    else
    {
        printf("Invalid Data !");
    }

    printf("Patient's Category :\t\t %c\n", chCategory);
    printf("Number of days to stayed :\t %d\n", chdays);
    printf("Total Chargers :\t\t Rs.%.2f\n\n", cal);

    printf("Remaining Beds :\t\t %d", (100 - pCount));
    return 0;
}
