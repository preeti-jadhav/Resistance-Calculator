//  FINAL MODULE of RESISTANCE CALCULATOR

//Description: Calculates resistance value of 4 and 5 banded resistors.

#include <stdio.h>
#include <math.h>
#include <string.h>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define bgWhite "\e[47;1m"
#define bgBlack "\e[40;1m"
#define RESET "\033[0m"

int sigfigs(char band[10]);
float mult(char band[10]);
float tol(char band[10]);
//--------------------------------------------------------------------------------------------------------------
int sigfigs(char band[10])
{
        if (strcmp(band, "black") == 0)
                return (0);
        else if (strcmp(band, "brown") == 0)
                return (1);
        else if (strcmp(band, "red") == 0)
                return (2);
        else if (strcmp(band, "orange") == 0)
                return (3);
        else if (strcmp(band, "yellow") == 0)
                return (4);
        else if (strcmp(band, "green") == 0)
                return (5);
        else if (strcmp(band, "blue") == 0)
                return (6);
        else if (strcmp(band, "violet") == 0)
                return (7);
        else if (strcmp(band, "grey") == 0)
                return (8);
        else if (strcmp(band, "white") == 0)
                return (9);
        else
                return (100);
}

float mult(char band[10])
{
        if (strcmp(band, "black") == 0)
                return (1);
        else if (strcmp(band, "brown") == 0)
                return (10);
        else if (strcmp(band, "red") == 0)
                return (100);
        else if (strcmp(band, "orange") == 0)
                return (1000);
        else if (strcmp(band, "yellow") == 0)
                return (10000);
        else if (strcmp(band, "green") == 0)
                return (100000);
        else if (strcmp(band, "blue") == 0)
                return (1000000);
        else if (strcmp(band, "violet") == 0)
                return (10000000);
        else if (strcmp(band, "gold") == 0)
                return (0.1);
        else if (strcmp(band, "silver") == 0)
                return (0.01);
        else
                return (9);
}

float tol(char band[10])
{
        if (strcmp(band, "brown") == 0)
                return (0.01);
        else if (strcmp(band, "red") == 0)
                return (0.02);
        else if (strcmp(band, "green") == 0)
                return (0.005);
        else if (strcmp(band, "blue") == 0)
                return (0.0025);
        else if (strcmp(band, "violet") == 0)
                return (0.001);
        else if (strcmp(band, "grey") == 0)
                return (0.0005);
        else if (strcmp(band, "gold") == 0)
                return (0.05);
        else if (strcmp(band, "silver") == 0)
                return (0.1);
        else
                return (9);
}


//----------------------------------------------------------------------------------------------------

int main(void)
{
        int bands = 0;
        char restart;
        char band1[10];
        char band2[10];
        char band3[10];
        char band4[10];
        char band5[10];
        float resistance;
        float finalResistance;
        int count;
        
    printf(" %s",RESET);
    printf("\n________________________________________\n");
    label :
    printf("\n________________________________________\n");
    printf("\nEnter no. of colour bands 4 or 5:");
    scanf("%i", &bands);
        if(bands==4||bands==5)
        {
          printf("\nBand 1: ");
          scanf("%s", band1);
        if (sigfigs(band1) == 100)
        {
                printf("%sColour is invalid!",RED);
                printf("%s",RESET);
                goto label;
                
        }
        fflush(stdin);
        printf("\nBand 2: ");
        scanf("%s", band2);
        if (sigfigs(band2) == 100)
        {
                printf("%sColour is invalid!",RED);
                printf("%s",RESET);
                goto label;
        }
        fflush(stdin);
        printf("\nBand 3: ");
        scanf("%s", band3);
        if (bands == 5)
        {
                if (sigfigs(band3) == 100)
                {
                        printf("%sColour is invalid!",RED);
                        printf("%s",RESET);
                        goto label;
                }
        }
        else if (bands == 4)
        {
                if (mult(band3) == 9)
                {
                        printf("%sColour is invalid!",RED);
                        printf("%s",RESET);
                        goto label;
                }
        }
        fflush(stdin);
        printf("\nBand 4: ");
        scanf("%s", band4);
        if (mult(band4) == 9)
        {
                printf("%sColour is invalid!",RED);
                printf("%s",RESET);
                goto label;
        }
        fflush(stdin);
        if (bands == 5)
        {
                printf("\nBand 5: ");
                scanf("%s", band5);
                if (tol(band5) == 9)
                {
                        printf("%sColour is invalid!",RED);
                        printf("%s",RESET);
                        goto label;
                }
                fflush(stdin);
        }

        if (bands == 4)
        {
                resistance= ((sigfigs(band1) * 10) + (sigfigs(band2) * 1)) * mult(band3);
                if(resistance>1000){
                    resistance=resistance/1000;
                    count=1;
                }
                else if(resistance>1000000){
                    resistance=resistance/1000000;
                    count=2;
                }
                else{
                    count=0;
                }
                printf("\n");
                printf("%s%sRESISTANCE VALUE =%s%.1f%s%sΩ\n",bgWhite,BLUE,RED,resistance,count==1?"K":count==2?"M":"",GREEN);
                printf("%s%sTOLERANCE = %s+-%.0f%%     \n",bgWhite,BLUE,MAGENTA,tol(band4)*100);
                printf("%s",RESET);
                
        }
        else if (bands == 5)
        {
                resistance = ((sigfigs(band1) * 100) + (sigfigs(band2) * 10) + (sigfigs(band3) * 1)) * mult(band4);
                if(resistance>1000){
                    resistance=resistance/1000;
                    count=1;
                }
                else if(resistance>1000000){
                    resistance=resistance/1000000;
                    count=2;
                }
                else{
                    count=0;
                }
                printf("\n");
                printf("%s%sRESISTANCE VALUE =%s%.1f%s%sΩ\n",bgWhite,BLUE,RED,resistance,count==1?"K":count==2?"M":"",GREEN);
                printf("%s%sTOLERANCE = %s+-%.0f%%      \n",bgWhite,BLUE,MAGENTA,  tol(band5)*100);
                printf("%s",RESET);
        }
            printf("\n%s%sDo you want to continue?\nPRESS [Y/N]:",bgBlack,GREEN);
            scanf(" %c",&restart);
            if(restart=='Y'||restart=='y')
            {
                main();
            }
            else
            {
                printf("\n\n%s*** THANK YOU! ***\n\n\n",MAGENTA);
                printf(" %s",RESET);
            }
    }
    else
    {
        printf("\n%sINVALID NUMBER",RED);
        printf(" %s",RESET);
        goto label;
    }
    
}
//------------------------------------------------------------------------------------------

