#include <stdio.h>
#include <conio.h>

//C-code for finance in Mathematics in the Modern World.

int main ()
{
    double I, P, r, t, OrdInt, ExactInt, CompAmount, PeriodicIntRate, NomIntRate;
    double numOfdays, m, OneOver_n, CdivP, F;
    char s;
    /*I for interest, P for principal, r for rate and t for time.
    OrdInt is the variable for Ordinary Simple Interest.
    ExactInt is the variable for the Exact Simple Interest.
    CompIint is the variable for the Compound Interest.
    PeriodicIntRate is the variable for the Periodic Interest Rate
    NomIntRate is the variable for the Nominal Interest Rate*/

    printf ("[A]Press 'A' to solve for the simple interest(I) and for the future or maturity value(F).\n");
    printf ("[B]Press 'B' to solve for the principal amount(P).\n");
    printf ("[C]Press 'C' to solve for the time(t).\n");
    printf ("[D]Press 'D' to solve for the rate(r).\n");
    printf ("[E]Press 'E' to solve for the ordinary simple interest.\n");
    printf ("[F]Press 'F' to solve for the exact simple interest.\n");
    printf ("[G]Press 'G' to solve for the compound amount(C).\n");
    printf ("[H]Press 'H' to solve for the periodic interest rate(i) and for the nominal interest rate(r).\n");

    s=getchar();

    switch (toupper(s))
    {
        case'A':

            printf ("\nEnter the principal value(P):");
            scanf ("%lf", &P);

            printf ("\nEnter the interest rate in percentage(r):");
            scanf ("%lf", &r);

            printf ("\nEnter the time(in terms of year)(t):");
            scanf ("%lf", &t);

            r=r/100;
            I= P*r*t;
            //F= P + I;
            F= P*(1 + (r*t));
            printf ("\n(I)Interest Value=%lf", I);
            printf ("\n(F)Future Value=%lf", F);
            break;

        case 'B':

            printf ("\nEnter the interest value(I):");
            scanf ("%lf", &I);

            printf ("\nEnter the interest rate in percentage(r):");
            scanf ("%lf", &r);

            printf ("\nEnter the time(in terms of year)(t):");
            scanf ("%lf", &t);

            r=r/100;
            P=I/(r*t);
            printf ("\n(P)Principal Value=%lf", P);
            break;

        case 'C':

            printf ("\nEnter the interest value(I):");
            scanf ("%lf", &I);

            printf ("\nEnter the interest rate in percentage(r):");
            scanf ("%lf", &r);

            printf ("\nEnter the principal value(P):");
            scanf ("%lf", &P);

            r=r/100;
            t=I/(P*r);
            printf ("\n(t)time=%lf", t);

            break;

        case 'D':

            printf ("\nEnter the interest value(I):");
            scanf ("%lf", &I);

            printf ("\nEnter the time (in terms of years)(t):");
            scanf ("%lf", &t);

            printf ("\nEnter the principal value(P):");
            scanf ("%lf", &P);

            r=(I/(P*t))*100;
            printf ("\n(r)rate=%lf%%%", r);

            break;

        case 'E':

            printf ("\nEnter the number of days:");
            scanf ("%lf", &numOfdays);

            printf ("\nEnter the principal value:");
            scanf ("%lf", &P);

            printf ("\nEnter the interest rate in percentage: ");
            scanf ("%lf", &r);

            r=r/100;
            OrdInt=P*r * (numOfdays/360);
            printf ("\nOrdinary Simple Interest (I(o))= %lf", OrdInt);

            break;

        case 'F':

            printf ("\nEnter the number of days:");
            scanf ("%lf", &numOfdays);

            printf ("\nEnter the principal value:");
            scanf ("%lf", &P);

            printf ("\nEnter the rate in percentage: ");
            scanf ("%lf", &r);

            r=r/100;
            //The 365 is only applicable if the year is not leap year.
            ExactInt=P*r * (numOfdays/365);
            printf ("\nExact Simple Interest (I(e)) = %lf", ExactInt);

            break;

        case 'G':

            printf ("\nEnter the principal value:");
            scanf ("%lf", &P);

            printf ("\nEnter the interest rate per year in percentage:");
            scanf ("%lf", &r);

            printf ("\nEnter the number of compounding periods in a year:");
            scanf ("%lf", &m);

            printf ("\nEnter the number of years:");
            scanf ("%lf", &t);

            r=r/100;
            CompAmount= P* pow((1+(r/m)), m*t);
            double CompIntVal=CompAmount-P;
            printf ("\nCompound Amount = %lf", CompAmount);
            printf ("\n\nCompound Interest Amount = %lf", CompIntVal);

            break;

        case 'H':

            printf ("\nEnter the principal value:");
            scanf ("%lf", &P);

            printf ("\nEnter the compound amount:");
            scanf ("%lf", &CompAmount);

            printf ("\nEnter the compounding periods a year:");
            scanf ("%lf", &m);

            printf ("\nEnter the number of years:");
            scanf ("%lf", &t);

            CdivP= CompAmount/P;
            printf ("\n\nCdivP=%lf", CdivP);

            OneOver_n= 1/(m*t);
            printf ("\n\nn=%lf", OneOver_n);

            double TempPeriodicIntRate= pow(CdivP,OneOver_n);
            printf ("\n\nTempPeriodicIntRate=%lf", TempPeriodicIntRate);

            double n=m*t;
            printf ("\n\nn=%lf", n);

            PeriodicIntRate= (TempPeriodicIntRate-1)*100;
            NomIntRate= PeriodicIntRate*m;
            //printf ("\n\nPeriodic Interest Rate (in decimal) = %lf", PeriodicIntRate);
            printf ("\n\nPeriodic Interest Rate (in percentage) = %lf%%%", PeriodicIntRate);
            printf ("\n\nNominal Interest Rate = %lf%%%", NomIntRate);

            break;

    default: printf ("\n\n\nSelection is not on the list!");
    }
}
