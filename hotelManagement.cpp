#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Room 
{
    public:
        Room(int number, int capacity, double rate) : number(number), capacity(capacity), rate(rate), isOccupied(false) {}

        int getNumber() const { return number; }
        int getCapacity() const { return capacity; }
        double getRate() const { return rate; }
        bool getIsOccupied() const { return isOccupied; }

        void occupy() { isOccupied = true; }
        void vacate() { isOccupied = false; }
        double calculateBill(int nights) const { return rate * nights; }

    private:
        int number;
        int capacity;
        double rate;
        bool isOccupied;
};

class Customer 
{
    public:
        Customer(const std::string& name, const std::string& email, const std::string& phone) : name(name), email(email), phone(phone) {}

        const std::string& getName() const { return name; }
        const std::string& getEmail() const { return email; }
        const std::string& getPhone() const { return phone; }

    private:
        std::string name;
        std::string email;
        std::string phone;
};

class Booking 
{
    public:
        Booking(const Room& room, const Customer& customer, int nights)
            : room(room), customer(customer), nights(nights) {}

        double calculateTotalBill() const { return room.calculateBill(nights); }

        void displayBookingDetails() const 
        {

            std::cout << "Booking Details:\n";
            std::cout << "Room Number: " << room.getNumber() << "\n";
            std::cout << "Room Rate: Rs." << room.getRate() << " per night\n";
            std::cout << "Number of Nights: " << nights << "\n";
            std::cout << "Total Bill: Rs." << std::fixed << std::setprecision(2) << calculateTotalBill() << "\n";
            std::cout << "\n";
        }

    private:
        Room room;
        Customer customer;
        int nights;
};

class Hotel 
{
    public:
        Hotel(const std::string& name) : name(name) {}

        void addRoom(const Room& room) 
        {
            rooms.push_back(room);
        }

        std::vector<Room*> findAvailableRooms(int capacity, int numberOfRooms) 
        {
            std::vector<Room*> availableRooms;
            for (Room& room : rooms) {
                if (!room.getIsOccupied() && room.getCapacity() >= capacity) 
                {
                    availableRooms.push_back(&room);
                    if (availableRooms.size() == numberOfRooms) 
                    {
                        break;
                    }
                }
            }
            return availableRooms;
        }

    private:
        std::string name;
        std::vector<Room> rooms;
};

int main() 
{
    Hotel myHotel("My Hotel");

    Room room101(101, 2, 1000.0);
    Room room102(102, 4, 1500.0);
    Room room103(103, 3, 1200.0);
    Room room104(104, 2, 900.0);

    myHotel.addRoom(room101);
    myHotel.addRoom(room102);
    myHotel.addRoom(room103);
    myHotel.addRoom(room104);

    std::string customerName;
    std::string customerEmail;
    std::string customerPhone;
    int numberOfRooms;
    int nights;

    std::cout << "Enter customer name: ";
    std::cin >> customerName;
    std::cout << "Enter customer email: ";
    std::cin >> customerEmail;
    std::cout << "Enter customer phone: ";
    std::cin >> customerPhone;
    std::cout << "Enter the number of rooms: ";
    std::cin >> numberOfRooms;
    std::cout << "Enter the number of nights: ";
    std::cin >> nights;
    std::cout<<"\n";

    Customer customer(customerName, customerEmail, customerPhone);
    std::vector<Room*> availableRooms = myHotel.findAvailableRooms(2, numberOfRooms);

    if (availableRooms.size()== numberOfRooms) 
    {
        for (Room* room : availableRooms) 
        {
            room->occupy();
        }
        double totalBill = 0.0;
        for (Room* room : availableRooms) 
        {
            Booking booking(*room, customer, nights);
            booking.displayBookingDetails();
            totalBill += booking.calculateTotalBill();
        }
        std::cout << "Total Bill for " << numberOfRooms << " rooms: Rs." << std::fixed << std::setprecision(2) << totalBill << "\n";
    } else 
    {
        std::cout << "Not enough available rooms matching the criteria.\n";
    }
    return 0;
}