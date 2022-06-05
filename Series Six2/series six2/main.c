
#include <stdio.h>
#include <math.h>

void one(void);
void two(void);
void three(void);
void four(void);
int problem;

int main() {

    while (problem != EOF){
        printf_s("%s","\n*****************\n");
        printf_s("\n Enter the number of the problem you wish to resolve. \n""Give A medical order in calculating the rate in ");
        printf_s( "\n (1) ml/hr & tubing drop factor drops/min"
                  "\n (2) 1 L for n hr ml/hr"
                  "\n (3) mg/kg/hr & concentration in mg/ml ml/hr"
                  "\n (4) units/hr & concentration in units/ml ml/hr"
                  "\n (5) QUIT \n");
        printf_s("%s","Problem> ");
        scanf_s("%d", &problem);
        switch (problem) {
            case 1:
                one();
                break;
            case 2:
                two();
                break;
            case 3:
                three();
                break;
            case 4:
                four();
                break;
            case 5:
                problem = EOF;
                break;
            default:
                printf_s("%s","\n The value entered is incorrect");
                break;
        }
    }
    return 0;
}
void one(void){
    double ml_hr, drops_ml;
    printf_s("Enter rate in ml/hr=> ");
    scanf_s("%lf",&ml_hr);
    printf_s("\n Enter tubing's drop factor(drops/ml)=> ");
    scanf_s("%lf",&drops_ml);
    printf_s("The drop rate per minute is %.0f .", ceil(((ml_hr*drops_ml)/60)));
}
void two(void){
    float hours;
    printf_s("Enter The Number of Hours=> ");
    scanf_s("%f",&hours);
    printf_s("\n The rate in milliliters per hour is %.0f .",1000/hours);
}
void three(void){
    float mg_kg_hr;
    float kg, mg_ml;
    printf_s("%s","\n Enter rate in mg/kg/hr=> ");
    scanf_s("%f",&mg_kg_hr);
    printf_s("%s","\n Enter the patient's weight in kg=> ");
    scanf_s("%f",&kg);
    printf_s("%s","\n Enter the concentration in mg/ml=> ");
    scanf_s("%f",&mg_ml);
    printf_s("\n The rate in milliliters per hour is %.0f .",(kg * mg_kg_hr)/mg_ml);
}
void four(void){
    float units_ml, ml_hr;
    printf_s("%s","Enter the rate in units/hr=>  ");
    scanf_s("%f",&units_ml);
    printf_s("%s","\nEnter concentration in units/ml=> ");
    scanf_s("%f",&ml_hr);
    printf_s("\n The rate in milliliters per hour is %.0f .", units_ml/ml_hr);

}