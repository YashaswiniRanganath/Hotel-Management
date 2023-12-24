This program uses file handling also . We store the details of the program in form of file . 

Room class:
Represents a hotel room with attributes such as room number, capacity, rate, and occupancy status.
Provides methods to occupy, vacate, get information, and calculate the bill.

Customer class:
Represents a customer with attributes like name, email, and phone number.

Booking class:
Represents a booking made by a customer for a specific room and duration.
Calculates the total bill and displays booking details.

Hotel class:
Represents a hotel with a name and a list of rooms.
Allows the addition of rooms and finding available rooms based on capacity and the number of rooms requested.

main function:
Creates an instance of the Hotel class.
Adds predefined rooms to the hotel.
Takes input for customer details, number of rooms, and number of nights.
Finds available rooms based on capacity and the number of rooms requested.
If available rooms are found, it creates bookings, displays details, and calculates the total bill.
If not enough rooms are available, it informs the user.
This code provides a foundation for a hotel management system but is quite basic. Depending on your requirements, you may want to extend it by adding more features such as a database for storing information persistently, handling different room types, or implementing more sophisticated booking logic.
