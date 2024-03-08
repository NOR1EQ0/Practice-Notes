#include <stdio.h>

typedef float Dollars;

int main(int argc, char const *argv[])
{
    Dollars cash_in, cash_out, balance;
    cash_in = 455.7;
    cash_out = 20.8;
    balance = cash_in - cash_out;
    printf("Cash-in: %f\nCash-out: %f\nBalance: %f", cash_in, cash_out, balance);
    return 0;
}

// Result:

// Cash-in: 455.700012
// Cash-out: 20.799999
// Balance: 434.900024