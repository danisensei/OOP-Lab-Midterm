#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class FitnessClass {
private:
    string className;
    int maxSlots;
    int availableSlots;

public:
    FitnessClass(const string& name, int maxSlots)
        : className(name), maxSlots(maxSlots), availableSlots(maxSlots) {}

    string getClassName() const {
        return className;
    }

    int getAvailableSlots() const {
        return availableSlots;
    }

    bool bookSlot() {
        if (availableSlots > 0) {
            availableSlots--;
            return true;
        }
        return false;
    }

    void cancelSlot() {
        if (availableSlots < maxSlots) {
            availableSlots++;
        }
    }
};

class Booking {
private:
    string memberName;
    FitnessClass* fitnessClass;

public:
    Booking(const string& name, FitnessClass* fitnessClass)
        : memberName(name), fitnessClass(fitnessClass) {}

    string getMemberName() const {
        return memberName;
    }

    FitnessClass* getFitnessClass() const {
        return fitnessClass;
    }
};

// Function to display booked slots
void displayBookedSlots(const vector<Booking>& bookings) {
    cout << "Booked Slots:" << endl;
    if (bookings.empty()) {
        cout << "No slots booked yet." << endl;
    } else {
        for (const auto& booking : bookings) {
            cout << "Class: " << booking.getFitnessClass()->getClassName() << ", Booked by: " << booking.getMemberName() << endl;
        }
    }
}

// Function to display fitness class schedule
void displaySchedule(const FitnessClass& yoga, const FitnessClass& zumba, const FitnessClass& pilates) {
    cout << "Fitness Class Schedule:" << endl;
    cout << "---------------------------------------" << endl;
    cout << setw(15) << left << "Class" << setw(15) << left << "Available Slots" << endl;
    cout << "---------------------------------------" << endl;
    cout << setw(15) << left << yoga.getClassName() << setw(15) << left << yoga.getAvailableSlots() << endl;
    cout << setw(15) << left << zumba.getClassName() << setw(15) << left << zumba.getAvailableSlots() << endl;
    cout << setw(15) << left << pilates.getClassName() << setw(15) << left << pilates.getAvailableSlots() << endl;
    cout << "---------------------------------------" << endl;
}

int main() {
    // Create fitness classes
    FitnessClass yoga("Yoga", 10);
    FitnessClass zumba("Zumba", 15);
    FitnessClass pilates("Pilates", 8);

    // Create a vector to store bookings
    vector<Booking> bookings;

    // Main loop
    while (true) {
        // Display options
        cout << "\nOptions:" << endl;
        cout << "1. Display Fitness Class Schedule" << endl;
        cout << "2. Book a Slot" << endl;
        cout << "3. Cancel Booking" << endl;
        cout << "4. Display Booked Slots" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySchedule(yoga, zumba, pilates);
                break;
            case 2: {
                // Display available fitness classes
                displaySchedule(yoga, zumba, pilates);

                // Get member's choice
                int classChoice;
                cout << "Enter the number of the fitness class you want to book: ";
                cin >> classChoice;

                // Book a slot for the chosen fitness class
                FitnessClass* chosenClass;
                switch (classChoice) {
                    case 1:
                        chosenClass = &yoga;
                        break;
                    case 2:
                        chosenClass = &zumba;
                        break;
                    case 3:
                        chosenClass = &pilates;
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        continue;
                }

                if (chosenClass->bookSlot()) {
                    string memberName;
                    cout << "Enter your name: ";
                    cin >> memberName;

                    Booking newBooking(memberName, chosenClass);
                    bookings.push_back(newBooking);

                    cout << "Booking confirmed! You have successfully booked a slot for " << chosenClass->getClassName() << "." << endl;
                } else {
                    cout << "Sorry, no slots available for " << chosenClass->getClassName() << "." << endl;
                }
                break;
            }
            case 3: {
                // Cancel booking
                displayBookedSlots(bookings);

                int cancelChoice;
                cout << "Enter the index of the booking you want to cancel (1-" << bookings.size() << "): ";
                cin >> cancelChoice;

                if (cancelChoice >= 1 && cancelChoice <= bookings.size()) {
                    FitnessClass* canceledClass = bookings[cancelChoice - 1].getFitnessClass();
                    canceledClass->cancelSlot();
                    bookings.erase(bookings.begin() + cancelChoice - 1);
                    cout << "Booking canceled successfully." << endl;
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;
            }
            case 4:
                displayBookedSlots(bookings);
                break;            case 5:
                return 0;
            default:
                break;
        }
    }

    return 0;
}
