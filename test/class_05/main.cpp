#include <stdio.h>
struct object
{
    int phone_number;
};
int main()
{
    int mom = 1,dad = 2, cousin = 3;
    object family[5];
    family[mom].phone_number = 912345678;
    family[dad].phone_number = 912345000;
    family[cousin].phone_number = 912000678;
    printf("%d\n", family[mom].phone_number);
    printf("%d\n", family[dad].phone_number);
    printf("%d", family[cousin].phone_number);
}