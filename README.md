# DSA-PROJECT-1
STAFF MANAGEMENT SYSTEM
Introduction
The Staff Management System is a console-based application developed using C++. It is designed to help users manage staff records efficiently by allowing them to add, view, and search staff information.
The system demonstrates fundamental concepts in programming, especially in Data Structures and basic system design. It provides a simple but effective way to organize and retrieve structured data.

 Objectives of the Project
The main objectives of this project are:
•	To create a system for storing staff information 
•	To allow users to add new staff records 
•	To display all stored staff data 
•	To enable searching of staff by name 
•	To demonstrate the use of structured programming and data structures 

 System Overview
The system operates through a menu-driven interface, where users interact with the program by selecting options.
Key Features:
•	Add staff details 
•	 Display all staff records 
•	Search for a specific staff member 
•	Exit the system



Header Files
The system relies on four primary libraries:
•	iostream: Facilitates basic input and output operations, such as reading user choices and printing records.
•	vector: Provides a dynamic array structure used to store the staff database, allowing the list to grow as new members are added.
•	string: Used to manage text-based data like names and residences.
•	iomanip: Included for potential output formatting, such as aligning columns in the staff list.
Structure Definition
Struct (User-defined Data Type)
The core of the system is the Staff struct. This acts as a template to group different data types related to a single individual into one unit.
•	Fields: Name, age, residence, occupation, and salary mode.
•	Database: All individual Staff objects are stored in a vector (dynamic array) called staff Database, which acts as the program's central memory, resizing when new data is added and allowing easy access using indexing
Functional Modules
The program is modularized into specific functions to ensure organized and readable code.
A. Data Entry (addStaff)
This function allows the user to input new records into the system.
1.	It creates a temporary Staff object.
2.	It uses getline (cin, ...) to ensure full names and addresses (including spaces) are captured correctly.
3.	The completed record is then "pushed" into the back of the vector database.


B. Records Visualization (displayAllStaff)
This module displays all stored records of registered staff.
•	Validation: It first checks if the database is empty to avoid displaying blank information.
•	Iteration: It uses a loop to traverse the vector and print each staff member's details.
C. Search Logic (searchStaff)
This allows users to find specific individuals by their names.
•	The function compares a user-provided string against the name field of every record in the database.
•	If a match is found, the details are displayed immediately, and the search terminates.
•	If the loop finishes without a match, the system alerts the user that the staff member was not found.

Program Flow and Control
The execution logic is managed within the main () function, which serves as the entry point.
Component
Infinite Loop (while(true))
Keeps the program active so the user can perform multiple tasks without restarting.
User Menu
Displays a numbered list of options (Add, Display, Search, Exit).
Switch Statement
Directs the program to the correct function based on the user's numeric input.
Choice	Action
1	Calls addStaff()
2	Calls displayAllStaff()
3	Calls searchStaff()
4	Exits program
How the Program Works (Flow)
1.	Program starts 
2.	Menu is displayed 
3.	User chooses an option 
4.	Corresponding function runs 
5.	Returns to menu 
6.	Repeats until user exits 

Advantages of the System
•	Simple and easy to use 
•	Efficient data storage using vectors 
•	Organized structure using struct 
•	Modular design (functions improve readability) 

 Limitations
•	Data is not saved permanently (no database/file storage) 
•	Search is case-sensitive 
•	Limited features (no delete or update options) 
•	Basic user interface (console only) 

 Possible Improvements
•	Add file handling for data persistence 
•	Implement update and delete features 
•	Improve search (case-insensitive, partial matching) 
•	Add a graphical user interface (GUI) 
•	Use advanced structures like trees or hash maps 



Conclusion
The Staff Management System is a basic yet functional application that demonstrates essential programming and data management concepts. It effectively shows how structured data can be stored, accessed, and manipulated using C++.
Although simple, the system provides a strong foundation for building more advanced management systems in real-world applications.




