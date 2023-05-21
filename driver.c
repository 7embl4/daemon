#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "driver.h"

enum states
{
    ON,
    OFF,
};

static int status = OFF;

void turn_on(void) {
    switch (status) {
        case ON:
            printf("GPS is already working!\n");
            break;
        case OFF:
            status = ON;
            sleep(2);  // GPS is "turning on"
            printf("GPS is ready to work!\n");
            break;
    }
}

void turn_off(void) {
    status = OFF;
    printf("GPS has turned off!\n");
}

void restart(void) {
    status = OFF;
    status = ON;
    sleep(3);  // GPS is "restarting"
    printf("GPS has been restarted!\n");
}

void get_location(void) {
    switch (status) {
        case ON:
            sleep(2);
            printf("Your location is...\n");
            break;
        case OFF:
            printf("GPS isn't working! First of all turn it on!\n");
            break;
    }
}

void create_path(char* curr_loc, char* destination) {
    if (strcmp(curr_loc, destination) == 0) {
        sleep(2);
        printf("You are already here!\n");
    }
    else {
        sleep(3);
        printf("Path has been created!\n");
    }
}