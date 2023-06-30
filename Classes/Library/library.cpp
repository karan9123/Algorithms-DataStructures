#include <iostream>
#include <unordered_map>

enum Genre {
    HORROR,
    COMEDY,
    THRILLER,
    ROMANTIC,
    BIOGRAPHY
};

std::string genreNames[5] = {"Horror", "Comedy", "Thriller", "Romantic", "Biography"};

class Book {
private:
    std::string title;
    std::string author;
    Genre genre;

public:
    /**
     * @brief Constructs a Book object with the given title, author, and genre.
     * 
     * @param name The title of the book.
     * @param auth The author of the book.
     * @param gen The genre of the book.
     */
    Book(std::string name, std::string auth, Genre gen) : title(name), author(auth), genre(gen) {}

    /**
     * @brief Prints the details of the book, including title, author, and genre.
     */
    void printDetails() const {
        std::cout << title << " by " << author << ". Genre: " << genreNames[genre] << std::endl;
    }

    /**
     * @brief Returns the genre of the book.
     * 
     * @return The genre of the book.
     */
    Genre getGenre() {
        return genre;
    }

    /**
     * @brief Returns the author of the book.
     * 
     * @return The author of the book.
     */
    std::string getAuthor() {
        return author;
    }

    /**
     * @brief Returns the title of the book.
     * 
     * @return The title of the book.
     */
    std::string getTitle() {
        return title;
    }

    /**
     * @brief Custom hash function for the Book class.
     */
    struct BookHash {
        std::size_t operator()(const Book& book) const {
            std::size_t titleHash = std::hash<std::string>{}(book.title);
            std::size_t authorHash = std::hash<std::string>{}(book.author);
            std::size_t genreHash = std::hash<int>{}(static_cast<int>(book.genre));
            return (titleHash ^ authorHash ^ genreHash);
        }
    };

    /**
     * @brief Checks if two books are equal by comparing their title, author, and genre.
     * 
     * @param otherBook The other book to compare with.
     * @return True if the books are equal, false otherwise.
     */
    bool operator==(const Book& otherBook) const {
        return title == otherBook.title && author == otherBook.author && genre == otherBook.genre;
    }
};

class Library {
private:
    std::unordered_map<Book, int, Book::BookHash> books;

public:
    /**
     * @brief Constructs a Library object with the given array of books and its size.
     *        Initializes the library with the books and their counts.
     * 
     * @param bookArray An array of books.
     * @param size The size of the bookArray.
     */
    Library(Book* bookArray, size_t size) {
        for (size_t i = 0; i < size; i++) {
            books[bookArray[i]]++;
        }
    }

    /**
     * @brief Adds a new book to the library.
     * 
     * @param newBook The book to add.
     */
    void addBook(Book newBook) {
        books[newBook]++;
    }

    /**
     * @brief Displays the books in the library along with their counts and details.
     */
    void displayBooks() const {
        for (const auto& book : books) {
            std::cout << "Count: " << book.second << "  ";
            book.first.printDetails();
        }
    }
};

int main() {
    // Create some book objects
    Book book1("Book 1", "Author 1", HORROR);
    Book book2("Book 2", "Author 2", COMEDY);
    Book book3("Book 3", "Author 3", THRILLER);
    Book book4("Book 4", "Author 4", ROMANTIC);
    Book book5("Book 5", "Author 5", BIOGRAPHY);

    // Create an array of books
    Book bookArray[] = {book1, book2, book3, book4, book5};
    size_t bookArraySize = sizeof(bookArray) / sizeof(bookArray[0]);

    // Create a library object and initialize it with the book array
    Library library(bookArray, bookArraySize);

    // Add some more books to the library
    library.addBook(book1);
    library.addBook(book2);

    // Display the books in the library
    library.displayBooks();

    return 0;
}