#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FitnessClass {
private:
    string name;
    int maxSlots;
    int availableSlots;

public:
    FitnessClass(const string& name, int maxSlots)
        : name(name), maxSlots(maxSlots), availableSlots(maxSlots) {}

    string getName() const {
        return name;
    }

    int getMaxSlots() const {
        return maxSlots;
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

    void cancelBooking() {
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
    Booking(const string& memberName, FitnessClass* fitnessClass)
        : memberName(memberName), fitnessClass(fitnessClass) {}

    string getMemberName() const {
        return memberName;
    }

    FitnessClass* getFitnessClass() const {
        return fitnessClass;
    }
};

int main() {
    FitnessClass yoga("Yoga", 10);
    FitnessClass zumba("Zumba", 15);

    Booking booking1("John", &yoga);
    Booking booking2("Jane", &zumba);

    cout << "Booking 1: " << booking1.getMemberName() << " - " << booking1.getFitnessClass()->getName() << endl;
    cout << "Booking 2: " << booking2.getMemberName() << " - " << booking2.getFitnessClass()->getName() << endl;

    cout << "Available slots for Yoga: " << yoga.getAvailableSlots() << endl;
    cout << "Available slots for Zumba: " << zumba.getAvailableSlots() << endl;

    return 0;
}