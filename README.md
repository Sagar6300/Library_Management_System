# Library Management System

The **Library Management System** is a simple console-based C++ application to manage books and users in a library. It allows adding books and users, borrowing and returning books, and searching for books or users. The program tracks whether a book is borrowed and who borrowed it, ensuring proper management of library resources.

---

## Features

1. **Add Books and Users**:
   - Add new books to the library.
   - Register new users in the library system.

2. **Borrow and Return Books**:
   - Users can borrow available books.
   - Users can return borrowed books, updating the library's status.

3. **Validation**:
   - Ensures only valid users and books are processed.
   - Displays appropriate error messages for invalid inputs.

4. **Search Functionality**:
   - Search for a book by its ID to get details.
   - Search for a user by their ID to get their information.

---

## Classes

### 1. **Book Class**
   - Represents a book in the library.
   - **Attributes**: `book_id`, `title`, `author`, `is_borrowed`, and `borrowed_by`.
   - **Methods**:
     - `toString()`: Returns a string representation of the book.
     - Overloaded `operator==`: Compares books by their ID.

### 2. **User Class**
   - Represents a user in the library.
   - **Attributes**: `user_id`, `name`, and `borrowed_books`.
   - **Methods**:
     - `borrowBook(Book &book)`: Adds a book to the user's borrowed list.
     - `returnBook(Book &book)`: Removes a book from the user's borrowed list.
     - `toString()`: Returns a string representation of the user.

### 3. **Library Class**
   - Manages books and users.
   - **Attributes**: Lists of books and users, and maps for quick ID-based lookups.
   - **Methods**:
     - `addBook(Book &book)`: Adds a book to the library.
     - `addUser(User &user)`: Registers a user in the library.
     - `borrowBook(int user_id, int book_id)`: Processes a borrowing request.
     - `returnBook(int user_id, int book_id)`: Processes a return request.
     - `searchBook(int book_id)`: Searches for a book by ID.
     - `searchUser(int user_id)`: Searches for a user by ID.

---

## How to Use

1. **Add Books**:
   - Use the `addBook` method to add books to the library.

2. **Add Users**:
   - Use the `addUser` method to register users in the library.

3. **Borrow Books**:
   - Call the `borrowBook` method with a valid user ID and book ID.

4. **Return Books**:
   - Use the `returnBook` method to return a borrowed book.

5. **Search**:
   - Use `searchBook` to search for a book by ID.
   - Use `searchUser` to search for a user by ID.

---

## Example Input

### Adding Books:
```cpp
Book book1(15, "The Great Gatsby", "F. Scott Fitzgerald");
Book book2(19, "To Kill a Mockingbird", "Harper Lee");
library.addBook(book1);
library.addBook(book2);
```
### Adding Users:
```cpp
User user1(1, "Alice");
User user2(2, "Bob");
library.addUser(user1);
library.addUser(user2);
```
### Borrowing and Returning Books:
```cpp
library.borrowBook(1, 15);  // Alice borrows "The Great Gatsby"
library.borrowBook(1, 17);  // Invalid book ID
library.borrowBook(3, 15);  // Invalid user ID
library.borrowBook(3, 20);  // Invalid user ID and book ID
library.returnBook(1, 15);  // Alice returns "The Great Gatsby"
library.returnBook(1, 17);  // Invalid book ID
library.returnBook(3, 15);  // Invalid user ID
library.returnBook(3, 20);  // Invalid user ID and book ID
library.borrowBook(2, 19);  // Bob borrows "To Kill a Mockingbird"
library.borrowBook(1, 19);  // Already borrowed by Bob
library.returnBook(2, 15);  // "The Great Gatsby" was not borrowed by Bob
library.returnBook(2, 19);  // Bob returns "To Kill a Mockingbird"
library.borrowBook(1, 19);  // Alice borrows "To Kill a Mockingbird"
library.borrowBook(1, 15);  // Alice borrows "The Great Gatsby"
```
### Searching:
```cpp
cout << library.searchBook(15) << endl;  // Search for book with ID 15
cout << library.searchBook(19) << endl;  // Search for book with ID 19
cout << library.searchUser(2) << endl;   // Search for user with ID 2
cout << library.searchUser(1) << endl;   // Search for user with ID 1
```
---
## Output
![image](https://github.com/user-attachments/assets/c9c1ad1d-727b-47b5-8006-4a63d6c98063)

