#include <stdio.h>
#include "booking.h"

void showMenu()
{
    int choice;
    while (1)
    {
        printf("\n1. Book Seat\n2. Cancel Booking\n3. Check Seat Availability\n4. View Booking\n5. Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:bookSeat();
            break;
            case 2:cancelSeat();
            break;
            case 3:checkAvailability();
            break;
            case 4:viewBooking();
            break;
            case 5:return;
            default:printf("Invalid choice\n");
        }
    }
}