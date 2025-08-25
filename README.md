# Module-8-Journal: Corner Grocer Inventory Tracker
Describes the working foundations of a C++ project aimed at users looking to find out how many items in a grocery store were sold on a certain day, and have those items visually displayed.
* This project was designed to allow a grocery store to analyze its customers' purchase history and the frequencies with which the items are purchased with a visual display. The program reads the transaction history from a file and calculates the frequency of every item that is purchased. This program provides four main features.
- 1. Search for an item → See how many times it was purchased.
- 2. List all item frequencies → View purchase counts for every item.
- 3. Visualize data in a histogram → Display each item's purchase frequency using asterisks.
- 4. Backup data → Save results to frequency.dat for reuse
* This app allows for the grocery store to automatically track items being purchased rather than manually having them counted which reduces human-prone errors.

* What I Did Particularly Well
* File Handling & Backup System.
- Designed a dual-storage approach: item counts are stored in memory using a map<string, int> and also backed up to frequency.dat for persistence.
- Implemented findFromBackup() to quickly retrieve specific item counts without recalculating everything.
- Histogram Visualization.
- Added a function starz(int num) to create asterisks based on purchase frequency.
- Made the output intuitive and easy to understand for users.
- Menu-Driven Interface for cleanliness and ease of use.
- Implemented a clean, structured menu (menuPrint class) to guide users through options.
- Ensured the program loops until the user explicitly chooses to exit.
- Error Handling.
- Included file open failure checks to ensure the program informs the user if data cannot be read or written.

* What I can do better -
- Make my code more efficient by not continuously opening frequency.dat multiple times in multiple options.
- Have better logic and organization in my program. There are many functions inside the main function. The only class created was for opening the menu for the user and calling it from the main function.
- I could have broken everything into its own class and used function calls to have main be cleaner, easier to debug, easier to test, and more efficient for use in other projects.

* Most Challenging Parts & How I Overcame Them
- Parsing was difficult for me to get right because I was dealing with different files and their formats. I solved this by using getline() to carefully strip carriage returns with
  if (!item.empty() && item.back() == '\r') item.pop_back(); I used C++ documentation for getline() and test different files.
- Implementing a histogram into my menu that prints asterisks for item counting was difficult. I wrote a function called starz(int num) with a for loop to handle each item effectively.

*Skills Gained & Transferable Knowledge-
- The skills I finally got to practice included: mapping/ frequency counting, menu UI's, error handling, and testing/ debugging.

  - These skills will allow me to do many things, including: handling data files, working with data and caches, making more user-friendly menus, and being able to validate
  different inputs that could potentially be input by the user.

*Program Maintainability, Readability, and Adaptability-
- I used many strategies to make the program easy to maintain and expand in the future.
- Maintainability: I used constants for filenames, so only one variable needs to be updated. I also separated backup handling from UI display
- Readability: I added many in-line comments to explain my logic and the logic of my code. I also followed industry practices to my best ability by having
  indentation and consistent naming convention.
- Adaptability: Made the program so that new features can be added with minimal changes to the program. These features include exporting CSV files and sorting by frequency
