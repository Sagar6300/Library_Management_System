#include <iostream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

class Book {
public:
    int book_id;
    string title;
    string author;
    bool is_borrowed;
    string borrowed_by; // Added to track who borrowed the book

    Book(int id, string t, string a) : book_id(id), title(t), author(a), is_borrowed(false) {}

    bool operator==(const Book &other) const {
        return book_id == other.book_id;
    }

    string toString() const {
        return to_string(book_id) + " - " + title + " by " + author;
    }
};

class User {
public:
    int user_id;
    string name;
    list<Book*> borrowed_books;

    User(int id, string n) : user_id(id), name(n) {}

    void borrowBook(Book &book) {
       borrowed_books.push_back(&book);
       book.is_borrowed = true;
       book.borrowed_by = name; // Track the user who borrowed the book
    }

    void returnBook(Book &book) {
        borrowed_books.remove(&book);
        book.is_borrowed = false;
        book.borrowed_by = ""; // Clear the borrowed_by information
    }

    string toString() const {
        return to_string(user_id) + " - " + name;
    }
};

class Library {
private:
    list<Book> books;
    list<User> users;
    unordered_map<int, Book*> book_map;
    unordered_map<int, User*> user_map;

public:
    void addBook(Book &book) {
        books.push_back(book);
        book_map[book.book_id] = &book;
    }

    void addUser(User &user) {
        users.push_back(user);
        user_map[user.user_id] = &user;
    }

    void borrowBook(int user_id, int book_id) {
        bool user_exists = user_map.find(user_id) != user_map.end();
        bool book_exists = book_map.find(book_id) != book_map.end();

        if (user_exists && book_exists) {
            User *user = user_map[user_id];
            Book *book = book_map[book_id];
            if (!book->is_borrowed) {
                user->borrowBook(*book);
                cout << "Book '" << book->title << "' borrowed by " << user->name << endl;
            } else {
                cout << "Book '" << book->title << "' is already borrowed by " << book->borrowed_by<< endl;
            }
        } else {
            if (!user_exists && !book_exists) {
                cout << "Invalid user ID and book ID." << endl;
            } else if (!user_exists) {
                cout << "Invalid user ID." << endl;
            } else if (!book_exists) {
                cout << "Invalid book ID." << endl;
            }
        }
    }

    void returnBook(int user_id, int book_id) {
        bool user_exists = user_map.find(user_id) != user_map.end();
        bool book_exists = book_map.find(book_id) != book_map.end();

        if (user_exists && book_exists) {
            User *user = user_map[user_id];
            Book *book = book_map[book_id];
            if (book->is_borrowed) {
                user->returnBook(*book);
                cout << "Book '" << book->title << "' returned by " << user->name << endl;
            } else {
                cout << "Book '" << book->title << "' was not borrowed by " << user->name << endl;
            }
        } else {
            if (!user_exists && !book_exists) {
                cout << "Invalid user ID and book ID." << endl;
            } else if (!user_exists) {
                cout << "Invalid user ID." << endl;
            } else if (!book_exists) {
                cout << "Invalid book ID." << endl;
            }
        }
    }

    string searchBook(int book_id) {
        if (book_map.find(book_id) != book_map.end()) {
            return book_map[book_id]->toString();
        } else {
            return "Book not found.";
        }
    }

    string searchUser(int user_id) {
        if (user_map.find(user_id) != user_map.end()) {
            return user_map[user_id]->toString();
        } else {
            return "User not found.";
        }
    }
};

int main() {
    Library library;

    // Adding books
    Book book1(15, "The Great Gatsby", "F. Scott Fitzgerald");
    Book book2(19, "To Kill a Mockingbird", "Harper Lee");
    library.addBook(book1);
    library.addBook(book2);

    // Adding users
    User user1(1, "Alice");
    User user2(2, "Bob");
    library.addUser(user1);
    library.addUser(user2);

    // Borrow and return books
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
    // Searching
    cout << library.searchBook(15) << endl;  // Search for book with ID 15
    cout << library.searchBook(19) <<endl;   // Search for book with ID 19
    cout << library.searchUser(2)  << endl;  // Search for user with ID 2
    cout << library.searchUser(1)  << endl;  // Search for user with ID 1

    return 0;
}