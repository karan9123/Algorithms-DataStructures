#include <iostream>
#include <unordered_map>
#include <vector>

/**
 * @brief Converts a string to lowercase.
 * @param str The input string.
 * @return The lowercase version of the input string.
 */
std::string toLower(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        c = std::tolower(c);
    }
    return result;
}

/**
 * @brief Represents a student with name, roll number, and grades.
 */
class Student {
private:
    static long roll; /**< Static variable to generate unique roll numbers. */
    std::string name; /**< Name of the student. */
    long rollNo; /**< Roll number of the student. */
    std::unordered_map<std::string, int> marks; /**< Map to store subject grades. */

    /**
     * @brief Updates the grades of the student.
     * @param newMarks A map containing subject grades to update.
     */
    void updateGrades(const std::unordered_map<std::string, int>& newMarks) {
        marks = newMarks;
    }

public:
    /**
     * @brief Constructor to initialize a Student object with a name.
     * @param n The name of the student.
     */
    Student(const std::string& n) : name(n), rollNo(++roll) {}
    /**
     * @brief Prompts the user to enter subject grades and updates them for the student.
     */
    void getGrades() {
        std::unordered_map<std::string, int> newMarks;
        std::string subject;
        int mark;
        std::cout << "Enter the subject name and marks (to stop input of marks, enter q or quit instead of subject name):\n";
        while (true) {
            std::cout << "Subject: ";
            std::cin >> subject;
            if (toLower(subject) == "q" || toLower(subject) == "quit") {
                break;
            }
            std::cout << "Marks: ";
            std::cin >> mark;
            while (mark > 100 || mark < 0) {
                std::cout << "Invalid input for marks, please enter marks again between 0 and 100: ";
                std::cin >> mark;
            }
            newMarks[subject] = mark;
        }
        updateGrades(newMarks);
    }

/**
 * @brief Takes input for subject marks and updates them for the student.
 * @param subjects An array of strings representing the subjects.
 * @param size The size of the subjects array.
 */
void enterMarks(std::string* subjects, size_t size) {
    std::unordered_map<std::string, int> newMarks;
    std::cout << "Enter marks for the given subjects:\n";
    int mark;
    std::cout<<"size of arr: " << size << std::endl;
    for (size_t i = 0; i < size; i++) {
        std::cout << subjects[i]<<": ";
        std::cin >> mark;
        while (mark > 100 || mark < 0) {
            std::cout << "Invalid input for marks, please enter marks again between 0 and 100: ";
            std::cin >> mark;
        }
        newMarks[subjects[i]] = mark;
    }
    updateGrades(newMarks);
}


    /**
     * @brief Calculates and returns the average grades of the student.
     * @return The average grades of the student.
     */
    float getAverageGrades() const {
        int sum = 0;
        int count = marks.size();
        for (const auto& grade : marks) {
            sum += grade.second;
        }
        return (count == 0) ? 0 : static_cast<float>(sum) / count;
    }


    /**
     * @brief Displays the student's details including name, roll number, and average grades.
     */
    void displayStudentDetails() const {
        std::cout << "Name: " << name << "\nRoll Number: " << rollNo << "\nAverage Grades: " << getAverageGrades() << std::endl;
    }
};

long Student::roll = 10000;

int main() {
    std::string subjects[5] {"English", "Maths", "Science", "Hindi", "Physical Education"};
    Student karan("Karan");
    karan.enterMarks(subjects, (sizeof(subjects) / sizeof(subjects[0])));

    karan.displayStudentDetails();

    Student ishita("Ishita");
    ishita.getGrades();
    ishita.displayStudentDetails();
    return 0;
}
