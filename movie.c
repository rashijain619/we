#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50

// Structure to represent a movie
typedef struct {
    char name[MAX_NAME_LENGTH];
    int availableSeats;
} Movie;

// Function prototypes
void initializeDatabase(Movie database[], int size);
void displayMovies(Movie database[], int size);
int buyTicket(Movie database[], int index);
void updateDatabase(Movie database[], int index, int numTickets);

int main() {
    Movie movieDatabase[MAX_MOVIES];
    int numberOfMovies = 3;  // Adjust as needed

    // Initialize the movie database
    initializeDatabase(movieDatabase, numberOfMovies);

    int choice;
    do {
        // Display menu
        printf("\n----- Movie Ticket Booking System -----\n");
        printf("1. Display Movies\n");
        printf("2. Buy Ticket\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMovies(movieDatabase, numberOfMovies);
                break;
            case 2: {
                int movieIndex;
                printf("Enter the index of the movie: ");
                scanf("%d", &movieIndex);
                if (movieIndex >= 0 && movieIndex < numberOfMovies) {
                    int numTickets = buyTicket(movieDatabase, movieIndex);
                    if (numTickets > 0) {
                        printf("Tickets purchased successfully!\n");
                        updateDatabase(movieDatabase, movieIndex, numTickets);
                    } else {
                        printf("Sorry, no available seats.\n");
                    }
                } else {
                    printf("Invalid movie index.\n");
                }
                break;
            }
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}

// Initialize the movie database with some sample data
void initializeDatabase(Movie database[], int size) {
    strcpy(database[0].name, "Movie 1");
    database[0].availableSeats = 50;

    strcpy(database[1].name, "Movie 2");
    database[1].availableSeats = 30;

    strcpy(database[2].name, "Movie 3");
    database[2].availableSeats = 20;
}

// Display the list of movies and available seats
void displayMovies(Movie database[], int size) {
    printf("\n----- Available Movies -----\n");
    for (int i = 0; i < size; ++i) {
        printf("%d. %s (%d seats available)\n", i, database[i].name, database[i].availableSeats);
    }
}

// Buy tickets for a specific movie
int buyTicket(Movie database[], int index) {
    int numTickets;
    printf("Enter the number of tickets to buy: ");
    scanf("%d", &numTickets);

    if (numTickets > 0 && numTickets <= database[index].availableSeats) {
        return numTickets;
    } else {
        return 0;
    }
}

// Update the database after ticket purchase
void updateDatabase(Movie database[], int index, int numTickets) {
    database[index].availableSeats -= numTickets;
}
