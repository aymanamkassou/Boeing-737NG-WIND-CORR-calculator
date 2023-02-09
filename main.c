#include <stdio.h>
#include <math.h>
#define PI 3.141592654

int main()
{
    int rwyhdg, winddir, windspd, g, gspeed, stop = 0;
    float windcorr, hwcomp, angle;
    while (stop == 0)
    {
        puts("Enter runway heading.");
        scanf("%d", &rwyhdg);
        puts("Enter wind direction");
        scanf("%d", &winddir);
        puts("Enter wind speed");
        scanf("%d", &windspd);
        puts("Are there gusts?, 1 for yes 0 for no.");
        scanf("%d", &g);

        angle = winddir - rwyhdg;
        angle = (angle * PI) / 180;
        hwcomp = windspd * cos(angle);

        if (g == 1)
        {
            puts("Enter gust speed.");
            scanf("%d", &gspeed);
            if (windspd < 10)
            {
                windcorr = 5 + gspeed - hwcomp;
            }
            else if (windspd > 10)
            {
                windcorr = (hwcomp / 2.0) + gspeed - hwcomp;
            }
        }
        else
        {
            if (hwcomp < 10)
            {
                windcorr = 5;
            }
            else if (hwcomp > 10)
            {
                windcorr = (hwcomp / 2.0);
                if (windcorr > 20)
                {
                    windcorr = 20;
                }
            }
        }

        printf("Your wind correction is: %.2f\n", windcorr);
        puts("Would you like to stop?, 1 for yes, 0 for no.");
        scanf("%d",&stop);
    }
}
