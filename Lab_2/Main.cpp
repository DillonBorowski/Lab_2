#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main() {
	//Part 1 
	/*
	string names[8] = {"David", "Jose", "Mike", "Alisha", "Kate", "Dan", "Ellen", "Nate"};
	int height[] = { 165, 174, 183, 142, 159, 170, 166, 171}; 

	//size of array
	int height_size = sizeof(height) / sizeof(height[0]);

	float average_height = 0;
	for (int i = 0; i < height_size; i++) {
		average_height += height[i];
	}
	average_height = average_height/ height_size;
	cout << "The average height is: " << average_height << endl;

	
	int max_height = 0;
	int shortest_height = height[0];

	int max_height_index = 0;
	int shortest_height_index = 0;
	//Find max height
	for (int i = 0; i < height_size; i++) {
		if (max_height < height[i]) { //set max height index = i
			max_height = height[i];
			max_height_index = i;
		}
		else if (height[i] < shortest_height) { //finds the shortest height 
			shortest_height = height[i];
			shortest_height_index = i;
		}

	}
	cout << "The tallest person is " << names[max_height_index];
	cout << " at a height of " << max_height << "cm" << endl;
	
	cout << "The shortest person is " << names[shortest_height_index];
	cout << " at a height of " << shortest_height << " cm" << endl;
	 */
	//Part 2

	
	int userinput;
	int avaible_seats = 0;
	int reserved_seats = 0;
	int window_seats = 0;
	int aisle_seats = 0;
	string seats[24][6];

	int user_row = 0;
	int user_coloum = 0;
	string user_status;
	

	ifstream my_file("seats.txt");
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 6; j++) {
			my_file >> seats[i][j];
		}
	}
	my_file.close();

	cout << "Welcome to Airline seating chart " << endl;
	cout << "Please select one of the options: " << endl;
	cout << "1 - Check Status" << endl;
	cout << "2 - Modify seats status" << endl;
	cout << "3 - Show seat" << endl;
	cout << "0 - Exit" << endl;
	
	cin >> userinput;

	while (userinput != 0) {

		if (userinput == 1) {
			
			int avaible_seats = 0;
			int reserved_seats = 0;
			int window_seats = 0;
			int aisle_seats = 0;

			for (int i = 0; i < 24; i++) {		//loops reading throught rows and coloums 
				for (int j = 0; j < 6; j++) {
					if (seats[i][j] == "A") {
						avaible_seats++;
					}
					else if (seats[i][j] == "R") {
						reserved_seats++;
					}
					if (j == 0 || j == 5) {
						if (seats[i][j] == "A") {
							window_seats++;
						}
					}
					else if (j == 1 || j == 4) {
						if (seats[i][j] == "A") {
							aisle_seats++;
						}
					}
					

				}
			}


			cout << "Avaible Seats: " << avaible_seats << endl;
			cout << "Reserved Seats: " << reserved_seats << endl;
			cout << "Aisle Seats: " << aisle_seats << endl;
			cout << "Window Seats: " << window_seats << endl;
			cout << "------" << endl;

			cin >> userinput;
			
		}
		if (userinput == 2) {
			cout << "Enter row number(1-24): " << endl;
			cin >> user_row;
			user_row--;

			cout << "Enter coloum number (1-6): " << endl;
			cin >> user_coloum;
			user_coloum--;

			cout << "The current seat status is: " << seats[user_row][user_coloum] << endl;
			cout << "New Status (A - Availbe, R - Reserved): ";
			cin >> user_status;

			seats[user_row][user_coloum] = user_status; //update it in memory
			
			ofstream my_file("seats.txt");

			// now open the file and re-write all the seat data
			for (int i = 0; i < 24; i++) {
				for (int j = 0; j < 6; j++) {
					my_file << seats[i][j] << " ";
				}
				my_file << endl;
			}
			
			my_file.close();
			
			cout << seats[user_row][user_coloum] << endl;


			cout << "------" << endl;

			cout << "Welcome to Airline seating chart " << endl;
			cout << "Please select one of the options: " << endl;
			cout << "1 - Check Status" << endl;
			cout << "2 - Modify seats status" << endl;
			cout << "3 - Show seat" << endl;
			cout << "0 - Exit" << endl;

			cin >> userinput;
			
		}
		if (userinput == 3) {
			cout << "---- Seat Chart ----" << endl;

			for (int i = 0; i < 24; i++) {
				for (int j = 0; j < 6; j++) {
					cout << seats[i][j] << " ";
				}
				cout << endl;
			}
			
			cout << "------" << endl;
			
			cout << "Welcome to Airline seating chart " << endl;
			cout << "Please select one of the options: " << endl;
			cout << "1 - Check Status" << endl;
			cout << "2 - Modify seats status" << endl;
			cout << "3 - Show seat" << endl;
			cout << "0 - Exit" << endl;

			cin >> userinput;
			
		}

		// here

	}
	

	
	return 0;
}