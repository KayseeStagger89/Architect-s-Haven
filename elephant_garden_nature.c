// interior_design_firm.c

/*
 * This program is designed to provide customers of an interior designing firm 
 * with a modern and aesthetically pleasing experience. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store information about a customer
struct customer {
	char name[50];
	char address[100];
	int phone;
};

// Data structure to store information about a room
struct room {
	int type; // 0 = bedroom, 1 = living, 2 = dining
	int size; // in sq. ft.
	int num_windows;
	int num_doors;
	int num_furniture_items;
	char *color_scheme;
};

int main() {
	// Create an array of customer objects
	struct customer customers[1000];
	int num_customers = 0;

	// Create an array of room objects
	struct room rooms[1000];
	int num_rooms = 0;

	// Variable to track whether the user has selected an option
	int option_selected = 0;

	// Variable to track whether the user is done with their selections
	int done = 0;

	// Variable to hold user input
	int input = 0;

	// Store user input into array
	while (done == 0) {
		// Display menu
		printf("Please select one of the following options:\n");
		printf("1. Add customer\n");
		printf("2. Add room\n");
		printf("3. View current list of customers\n");
		printf("4. View current list of rooms\n");
		printf("5. Exit\n");
		
		// Get user input
		scanf("%d", &input);

		// Process user input
		switch (input) {
			case 1: // Add customer
				// Get customer information from user
				printf("Please enter customer name: ");
				scanf("%s", customers[num_customers].name);
				printf("Please enter customer address: ");
				scanf("%s", customers[num_customers].address);
				printf("Please enter customer phone number: ");
				scanf("%d", &customers[num_customers].phone);

				// Increment num_customers counter
				num_customers++;
				option_selected = 1;
				break;
			case 2: // Add room
				// Get room information from user
				printf("Please enter room type (0 = bedroom, 1 = living, 2 = dining): ");
				scanf("%d", &rooms[num_rooms].type);
				printf("Please enter room size (sq. ft.): ");
				scanf("%d", &rooms[num_rooms].size);
				printf("Please enter number of windows: ");
				scanf("%d", &rooms[num_rooms].num_windows);
				printf("Please enter number of doors: ");
				scanf("%d", &rooms[num_rooms].num_doors);
				printf("Please enter number of furniture items: ");
				scanf("%d", &rooms[num_rooms].num_furniture_items);
				printf("Please enter room color scheme: ");
				rooms[num_rooms].color_scheme = (char *) malloc(sizeof(char) * 50);
				scanf("%s", rooms[num_rooms].color_scheme);

				// Increment num_rooms counter
				num_rooms++;
				option_selected = 1;
				break;
			case 3: // View current list of customers
				printf("Current list of customers:\n");
				for (int i = 0; i < num_customers; i++) {
					printf("Name: %s, Address: %s, Phone: %d\n", customers[i].name, customers[i].address, customers[i].phone);
				}
				option_selected = 1;
				break;
			case 4: // View current list of rooms
				printf("Current list of rooms:\n");
				for (int i = 0; i < num_rooms; i++) {
					printf("Type: %d, Size: %d, Number of Windows: %d, Number of Doors: %d, Number of Furniture Items: %d, Color Scheme: %s\n", rooms[i].type, rooms[i].size, rooms[i].num_windows, rooms[i].num_doors, rooms[i].num_furniture_items, rooms[i].color_scheme);
				}
				option_selected = 1;
				break;
			case 5: // Exit
				// Set done to 1
				done = 1;
				option_selected = 1;
				break;
			default:
				// Display error message
				printf("Invalid input. Please select a valid option.\n");
				option_selected = 0;
				break;
		}
	}

	// Free memory allocated to color scheme
	for (int i = 0; i < num_rooms; i++) {
		free(rooms[i].color_scheme);
	}

	return 0;
}