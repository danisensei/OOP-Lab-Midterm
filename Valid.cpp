#include <iostream>
#include <vector>
#include <string>

class FitnessClass {
private:
    std::string name;
    int maxSlots;
    int availableSlots;

public:
    FitnessClass(const std::string& name, int maxSlots)
        : name(name), maxSlots(maxSlots), availableSlots(maxSlots) {}

    std::string getName() const {
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
    std::string memberName;
    FitnessClass* fitnessClass;

public:
    Booking(const std::string& memberName, FitnessClass* fitnessClass)
        : memberName(memberName), fitnessClass(fitnessClass) {}

    std::string getMemberName() const {
        return memberName;
    }

    FitnessClass* getFitnessClass() const {
        return fitnessClass;
    }
};

int main() {
    // Create some fitness classes
    FitnessClass yoga("Yoga", 10);
    FitnessClass zumba("Zumba", 15);

    // Book slots for members
    Booking booking1("John", &yoga);
    Booking booking2("Jane", &zumba);

    // Output booking information
    std::cout << "Booking 1: " << booking1.getMemberName() << " - " << booking1.getFitnessClass()->getName() << std::endl;
    std::cout << "Booking 2: " << booking2.getMemberName() << " - " << booking2.getFitnessClass()->getName() << std::endl;

    // Check available slots
    std::cout << "Available slots for Yoga: " << yoga.getAvailableSlots() << std::endl;
    std::cout << "Available slots for Zumba: " << zumba.getAvailableSlots() << std::endl;

    return 0;
}