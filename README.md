# Egg-Assembly-Line-Sorted

Overview:
The Egg Sorting System is a C++ program designed to process input from a text file representing a conveyor belt with trays of eggs. Each tray may contain a random number of eggs, and the eggs are differentiated by symbols based on their weight. The program utilizes linked lists for the Tray and Conveyor classes, incorporating a max-heap data structure to efficiently sort the eggs by weight. The Egg files hold the egg class which creates an egg object, the Tray files hold the tray class which allow for eggs to be put into the trays, the Conveyor files hold the conveyor class and harness structure which when combined are able to create an assembly line with mutliple trays linked together, the Factory_utils files hold the functions in order to create a visual report of the conveyor belt when given a text file as input, the Big_time files holds the functions for the max-heap in order to sort each tray, and the 01.txt file is an example input which can be given into the sorted_vert_report file.

Key Features:

Input Processing:
The program reads input from a text file, interpreting the data to construct a virtual conveyor belt with trays. The trays are represented as linked list nodes, facilitating dynamic management of varying tray sizes.

Egg Representation:
Eggs on the conveyor belt are symbolized based on their weight categories. The program distinguishes between egg weights and assigns corresponding symbols for easy identification during sorting.

Linked List Implementation:
The program leverages the flexibility of linked lists to represent both trays and the conveyor belt. This allows for dynamic allocation and deallocation of memory, accommodating variable tray sizes.

Max-Heap for Sorting:
To efficiently sort eggs by weight, the program employs a max-heap data structure. This ensures that the heaviest eggs are prioritized during sorting, enhancing the overall performance of the sorting algorithm.

Sorting Algorithm:
The sorting process involves extracting eggs from trays and inserting them into the max-heap. The max-heap algorithm rearranges the eggs based on their weights, and the program updates the trays with the sorted eggs, producing a conveyor belt with eggs arranged in descending order of weight.

Output Display:
The program generates a human-readable output, displaying the updated conveyor belt with trays of eggs sorted by weight. The output includes symbols representing different weight categories, providing a clear visual representation of the sorting process.

Technical Details:

Programming Language: The program is implemented in C++ for efficiency and flexibility.
Data Structures: Linked lists are utilized for the Tray and Conveyor classes, while a max-heap is employed for sorting eggs based on weight.
File Input/Output: The program supports reading input from a text file, allowing for easy integration with various datasets.
