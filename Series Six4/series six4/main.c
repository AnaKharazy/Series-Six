
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct  ReceiptForadd{
    char spaceF[3];
    char CustomerID[6];
    char  Time[10];
    char spaceE[3];
}rece;
struct Receipt {
    char spaceF[3];
    char CustomerID[20];
    char  Time[10];
    char  Price[10];
    char  Average[10];
    char spaceE[3];
}rec;
char Date[10];
int roundToUpper(float f);
void AddTime();
float AverageUsageperhour( float Time,float Price);
char CountingReceipt(char Time[10],char Customerid[20]);
void GetFromFile();
void writeTofile(char customerid[10],char  average[10],char price[10],char time[10]);
void AddTofileManually();
int main() {

    //AddTofileManually();
    AddTime();
    GetFromFile();
    return 0;
}
int roundToUpper(float f)
{
    if (f < 0)
        return ((int)(f));
    else
        return (int)(f + 1);
}
float AverageUsageperhour( float Time,float Price)
{
    return Price/Time;
}
void writeTofile(char customerid[10],char average[10],char price[10],char time[10])
{
    FILE *p;
    strcpy(rec.CustomerID,customerid);
    strcpy(rec.Average,average);
    strcpy(rec.Time,time);
    strcpy(rec.Price,price);
    printf("Customer: %s\n", rec.CustomerID);
    printf("Average :%s \n", rec.Average);
    printf("Price : %s  \n", rec.Price);
    printf("Time  : %s \n", rec.Time);
    strcpy(&rec.spaceE,"\n");
    strcpy(&rec.spaceF,"\n");
    p = fopen("C:\\Users\\4566\\Desktop\\ch.txt","a");
    fwrite(&rec,sizeof(struct Receipt),1,p);
    fclose(p);
}
void GetFromFile(){
    FILE *p;

    p = fopen("C:\\Users\\4566\\Desktop\\charges.txt","r");
    fread(&rece,sizeof(struct ReceiptForadd),1,p);
    if (p!=NULL) //is chek is main file is exist
    {
        while(!feof(p))
        {
            CountingReceipt(rece.Time,rece.CustomerID);
            fread(&rece,sizeof(struct ReceiptForadd),1,p);
        }
        fclose(p);
    }
    else
    {
        printf("there is not any contex");
    }

}
char CountingReceipt(char Time[10],char Customerid[20]){
    float tempTime=0;
    float newtime= atof(Time);
    float Price=0;
    if(newtime<=10)
    {
        Price=7.99;
    }
    else if(Time>10)
    {    Price=7.99;
        tempTime= newtime -10;

        if(tempTime<=1){
            Price+=1.99;
        }
        else if(tempTime>1)
        {
            for (int i = 0; i < roundToUpper(tempTime) ; ++i)
            {
                Price+=1.99;

            }
        }

    }
    char price[10];
    char Average[10];
    gcvt(Price, 6,  price);
    gcvt(AverageUsageperhour(newtime,Price), 6,  Average);
    writeTofile(Customerid,Average,price,Time);
    return price;
}
void AddTofileManually(){
    char Date[20];
    FILE *p;
    //AddTime();
    for (int i = 0; i < 3; ++i) {

        printf("Enter CustomerID : ");
        scanf(" %s",&rece.CustomerID);
        printf("Enter Time  : ");
        scanf(" %s",&rece.Time);
        strcpy(&rece.spaceE,"\n");
        strcpy(&rece.spaceF,"\n");
        p = fopen("C:\\Users\\4566\\Desktop\\charges.txt","a");
        fwrite(&rece,sizeof(struct ReceiptForadd),1,p);
    }
    fclose(p);
}
void AddTime(){
    char DateYear[5];
    char DateMounth[3];
    FILE *p;
    p = fopen("C:\\Users\\4566\\Desktop\\ch.txt","a");
    fprintf(p, "  2022 10 \n");
    fprintf(p, "  Customer          Hours   UsedPerHour  AverageCost \n");
    fclose(p);
}