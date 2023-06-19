#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main -This is the main Function of the program.
 *
 * Return: 0 if (Success).
 */


struct items
{
    char bookName[30];
    int qty;
    float price;
};

struct orders
{
    char studentName[30];
    int numofItems;
    char date[20];
    struct items itm[50];
};


//Function to generate the Bill header.

void header(char name[30], char date[20])
{
    printf("=================STUDENTS * REQUIREMENTS * ACADEMICS ==========================\n");
    printf("_________________________________________________________________________________\n");
    printf("\n\t The name of the Item is %s\n", name);
    printf("----------------------------------------\n");
    printf("\n\t The date Purchased is %s\n", date);
    printf("\n\t Items");
    printf("\n\t qty");
    printf("\n\t price");
    printf("___________________________________________\n");
}

//Function to generate The bill for the Body.


void Body(char bookName[230], int qty, float price)
{
    printf("\n\n");
    printf("%s \n\t", bookName);
    printf("%d \n\t", qty);
    printf("%f \n\t",qty * price);
}

//The Function to Compute the Total  of the Items and the student.

void BillFooter(float total)
{
    float discount = 0.9 * total;
    float netTotal = total - discount;
    float tax = 0.16 * netTotal;
    float GrandTotal = netTotal + 2 * tax;


    //Print the Resulta using the Printf Function.
    printf("\n\n");
    printf("\n\t The discount is  %.2f\n", discount);
    printf("\n\t The netTotal is  %.2f\n", netTotal);
    printf("\n\t The tax of the Item is %.2f\n", tax);
    printf("\n\t The GrandTotal is %.2f\n", GrandTotal);
    printf("-------------------------------------------\n");
}


// The main Function of the Program.

int  main(void)
{
     int choice, n, i;
     FILE *fp;
     char saveBill ='Y', contFlag = 'Y';
     struct orders  ord;
     struct orders order;
     char name[30];


     float total = 0;
     int invoiceFound = 0;

    while(contFlag = 'Y')
    {
        printf("========================THE * STUDENTS * ACADEMIA=============================\n");
        printf("-------------------------------------------------------------------------------\n");
        printf("ENTER YOUR CHOICE\n");
        printf("___________________\n");
        printf("\n\t\t 1.Generate New Bill \n");
        printf("\n\t\t 2.Show All Bills \n");
        printf("\n\t\t 3.Search For A Bill \n");
        printf("\n\t\t 4.Exit\n");
        printf("\n\t Enter Your Choice:");
        scanf("%d", &choice);

        switch(choice)
        {
         case 1:
             system("clear");
             printf("Enter the name of the student:");
             fgets(ord.studentName,30, stdin);
             ord.studentName[strlen(ord.studentName)-1]=0;
             printf("Enter the number of Items:");
             scanf("%d",&n);
            int  numofItems =n;
             for(i=0; i<numofItems; i++)
             {
                 printf("Enter the  Items %d\n", i+1);
                 fgets(ord.itm[i].bookName,30,stdin);
                 ord.itm[i].bookName[strlen(ord.itm[i].bookName) -1] =0;
                 printf("Enter the qty:");
                 scanf("%d",&ord.itm[i].qty);
                 printf("Enter the price of the item:");
                 scanf("%f",&ord.itm[i].price);
                 total += ord.itm[i].qty * ord.itm[i].price;

                     header(ord.studentName, ord.date);
                     for(i=0; i<numofItems; i++)
                     { 


                         Body(ord.itm[i].bookName, ord.itm[i].qty, ord.itm[i].price);
                     }
                                      
                     BillFooter(total);

                     //Save The bill in a File Storage.

                      printf("Do you want to save the Bill [Y/N]:");
                      scanf("%s",&saveBill);

                      if (saveBill = 'Y')
                      {
                          fp = fopen("Billstorage.txt", "a+");
                          fwrite(&ord, sizeof(struct orders), 1, fp);
                          if (fwrite != NULL)
                          {
                              printf("The bill is Saved Successfully");
                          }
                          else
                          {
                              printf("Error while saving the Bill");
                          }
                                 
                      }
                          fclose(fp);
                          break;

                 case 2:
                          fgetc(stdin);
                          printf("\n\n");
                          system("clear");
                          fp = fopen("Billstorage.txt", "r");
                          printf("********The previous Invoice******");

                          while(fread(&ord, sizeof(struct orders), 1, fp))
                          {
                               float total = 0;
                               header(order.studentName, order.date);
                               for(i=0; i<numofItems; i++)
                               {
                                   Body(order.itm[i].bookName, order.itm[i].qty, order.itm[i].price);
                                   total += order.itm[i].qty * order.itm[i].price;
                               }
                                BillFooter(total);
                          }

                          fclose(fp);
                          break;
                 case 3:
                          printf("Enter the name of the Student:");
                          fgets(name, sizeof(name), stdin);
                          name[strlen(name)-1] = 0;
                          system("clear");
                          fp = fopen("Billstorage.txt",  "r");
                          printf("The name of the student is %s\n", name);

                          while(fread(&order, sizeof(struct orders), 1, fp))
                          {
                              if(! strcmp(order.studentName, name))
                              {
                                  float total = 0;
                                  header(order.studentName, order.date);
                                  for(i=0; i<numofItems; i++)
                                  {
                                      Body(order.itm[i].bookName, order.itm[i].qty, order.itm[i].price);
                                      total += order.itm[i].qty *order.itm[i].price;
                                  }
                                  BillFooter(total);
                                  invoiceFound = 1;

                                  if (! invoiceFound)
                                  {
                                      printf("Sorry the Invoice was not Found");
                                  }

                              }
                          }
                          fclose(fp);
                 case 4:
                          system("clear");
                          printf("Thank you for Visiting my Store");
                          exit(0);
                          break;
                 default:
                          printf("The Choice enterd is Available");
                          break;
                          printf("Invalid Operational Choice");
                          break;



                          printf("Do you want to perform another Operation[Y/N]");
                          scanf("%s", &contFlag);

                          printf("Thank you for your time Bye Bye");


             }
        }
    }
                     

}










