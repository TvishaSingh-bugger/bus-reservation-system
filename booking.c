#include <stdio.h>
#include <string.h>

struct Booking
{
    int passengerId;
    char name[50];
    char route[100];
    int seat;
};

struct Booking bookings[150];
char *routes[]={"Dehradun to Lucknow","Patna to Lucknow","Lucknow to Delhi","Delhi to Dehradun","Lucknow to Patna"};

int seats[5][30];
int totalBookings=0;

void bookSeat()
{
    if (totalBookings>=150)
    {
        printf("All bookings full.\n");
        return;
    }

    char name[50];
    int route,seat;

    printf("Enter your name: ");
    scanf("%s",name);

    printf("Select Route:\n");
    for (int i=0;i<5;i++)
    printf("%d. %s (Rs 300)\n", i + 1, routes[i]);
    scanf("%d",&route);
    route--;

    printf("Enter seat number (1-30): ");
    scanf("%d",&seat);

    if (route<0||route>=5||seat<1||seat>30||seats[route][seat-1])
    {
        printf("Invalid route or seat already booked.\n");
        return;
    }

    seats[route][seat-1]=1;

    struct Booking *b=&bookings[totalBookings];
    b->passengerId=totalBookings+1;
    strcpy(b->name,name);
    strcpy(b->route,routes[route]);
    b->seat=seat;

    totalBookings++;
    printf("Booking successful! Passenger ID: P%d\n",b->passengerId);
}

void cancelSeat()
{
    int pid,found=0;
    printf("Enter your Passenger ID to cancel (without P): ");
    scanf("%d",&pid);

    for (int i=0;i<totalBookings;i++)
    if (bookings[i].passengerId==pid)
    {
        for (int r=0;r<5;r++)
        if (strcmp(bookings[i].route,routes[r])==0)
        {
            seats[r][bookings[i].seat - 1] = 0;
            break;
        }

        for (int j=i;j<totalBookings-1;j++)
        {
            bookings[j]=bookings[j+1];
            bookings[j].passengerId=j+1;
        }

        totalBookings--;
        found=1;
        printf("Booking with Passenger ID P%d cancelled.\n",pid);
        break;
    }

    if (!found)
    printf("Booking with Passenger ID P%d not found.\n",pid);
}

void checkAvailability()
{
    for (int r=0;r<5;r++)
    {
        int available=0;
        for (int s=0;s<30;s++)
        if (!seats[r][s])
        available++;
        printf("Route: %s, Available Seats: %d\n",routes[r],available);
    }
}

void viewBooking()
{
    if (totalBookings==0)
    {
        printf("No bookings yet.\n");
        return;
    }

    printf("\nAll Bookings\n");
    for (int i=0;i<totalBookings;i++)
    {
        struct Booking *b=&bookings[i];
        printf("Passenger ID: P%d, Name: %s, Route: %s, Seat: %d, Price: Rs 300\n",b->passengerId, b->name, b->route, b->seat);
    }
}