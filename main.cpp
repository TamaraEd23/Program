//
//  main.cpp
//  Program 1
// Created by Tamara Edmond on 9/25/24.
//

#include <iostream>
#include <vector>
#include <exception>

using namespace std;

// Function to display seating
void displaySeating(const vector<vector<int>>& seating) {
    cout << "   A  B  C  D" << endl;  // Seat labels
    
    for (int i = 0; i < seating.size(); ++i) {
        cout << i + 1;  // Display row number
        
        for (int j = 0; j < seating[i].size(); ++j) {
            if (seating[i][j] == -1)
                cout << " X ";  // If seat is taken, show 'X'
            else
                cout << " " << seating[i][j] << " "; // If seat is available, show 0
        }
        
        cout << endl;
    }
}

// Function to book a seat
void bookSeat(vector<vector<int>>& seating) {
    char seatLetter;
    int row;
    
    cout << "Enter row number (1-5): ";
    cin >> row;
    cout << "Enter seat letter (A-D): ";
    cin >> seatLetter;
    

    int seatIndex = seatLetter - 'A';

    // Check if the seat is valid and available
    if (row >= 1 && row <= seating.size() && seatIndex >= 0 && seatIndex < seating[0].size()) {
        if (seating[row - 1][seatIndex] == 0) {
            seating[row - 1][seatIndex] = -1;  // Mark seat as taken
            cout << "Seat assigned successfully!\n";
        } else {
            cout << "That seat is already taken. Please choose another seat.\n";
        }
    } else {
        cout << "Invalid seat selection. Try again.\n";
    }
}

int main() {
    int rows = 5;  // Set number of rows
    int seatsPerRow = 4;  // Set number of seats per row

    // Initialize seating chart with available seats
    vector<vector<int>> planeSeats(rows);

    for (int i = 0; i < rows; ++i) {
        planeSeats[i].resize(seatsPerRow, 0);
    }

    bool isBookingActive = true; // variables
    char choice;

    while (isBookingActive) {
        displaySeating(planeSeats);  // Display the seating chart
        
        bookSeat(planeSeats);  // alolow user to choose
        
        cout << "Do you want to book another seat? (Y/N): ";
        cin >> choice;
        
        if (choice == 'N' || choice == 'n') {
            isBookingActive = false; // End the booking loop
        }
    }

    // Display final seating chart
    cout << "\nFinal seating chart:\n";
    displaySeating(planeSeats);
    
    return 0;
}


