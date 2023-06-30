#include <iostream>
#include <limits>
#include <stdexcept>

/**
 * @brief The Rectangle class represents a rectangle shape with a width and breadth.
 */
class Rectangle
{
protected:
    float width;    /**< The width of the rectangle. */
    float breadth;  /**< The breadth of the rectangle. */

    /**
     * @brief Calculates the area of the rectangle.
     *
     * @return The area of the rectangle.
     * @throws std::overflow_error if an overflow occurs during the calculation.
     */
    float calculateArea()
    {
        if (width >= std::numeric_limits<float>::max() / breadth)
        {
            throw std::overflow_error("Overflow encountered while calculating area.");
        }

        float area = width * breadth;
        return area;
    }

    /**
     * @brief Calculates the perimeter of the rectangle.
     *
     * @return The perimeter of the rectangle.
     * @throws std::overflow_error if an overflow occurs during the calculation.
     */
    float calculatePerimeter()
    {
        if ((2 * (width + breadth)) >= std::numeric_limits<float>::max())
        {
            throw std::overflow_error("Overflow encountered while calculating perimeter.");
        }

        float perimeter = 2 * (width + breadth);
        return perimeter;
    }

public:
    /**
     * @brief Constructs a new Rectangle object with equal width and breadth.
     *
     * @param side The width and breadth of the square.
     */
    Rectangle(float side) : width(side), breadth(side) {}

    /**
     * @brief Constructs a new Rectangle object with the specified width and breadth.
     *
     * @param w The width of the rectangle.
     * @param b The breadth of the rectangle.
     */
    Rectangle(float w, float b) : width(w), breadth(b)
    {
        std::cout << "Width of Rectangle is: " << width << " and breadth is: " << breadth << std::endl;
    }

    /**
     * @brief Displays the area of the rectangle.
     *
     * If an overflow occurs during the calculation, an error message is displayed.
     */
    void displayArea()
    {
        try
        {
            float rectangle_area = calculateArea();
            std::cout << "Area of rectangle with width " << width << " and breadth " << breadth << " is: " << rectangle_area << std::endl;
        }
        catch (const std::overflow_error &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    /**
     * @brief Displays the perimeter of the rectangle.
     *
     * If an overflow occurs during the calculation, an error message is displayed.
     */
    void displayPerimeter()
    {
        try
        {
            float rectangle_perimeter = calculatePerimeter();
            std::cout << "Perimeter of rectangle with width " << width << " and breadth " << breadth << " is: " << rectangle_perimeter << std::endl;
        }
        catch (const std::overflow_error &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
};

/**
 * @brief The Square class represents a square shape, which is a special type of rectangle.
 */
class Square : public Rectangle
{
public:
    /**
     * @brief Constructs a new Square object with the specified side length.
     *
     * @param side The side length of the square.
     */
    Square(float side) : Rectangle(side, side)
    {
        std::cout << "Square with sides: " << side << std::endl;
    }

    /**
     * @brief Displays the area of the square.
     *
     * If an overflow occurs during the calculation, an error message is displayed.
     */
    void displayArea()
    {
        try
        {
            float square_area = calculateArea();
            std::cout << "Area of square with sides: " << width << " is: " << square_area << std::endl;
        }
        catch (const std::overflow_error &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    /**
     * @brief Displays the perimeter of the square.
     *
     * If an overflow occurs during the calculation, an error message is displayed.
     */
    void displayPerimeter()
    {
        try
        {
            float square_perimeter = calculatePerimeter();
            std::cout << "Perimeter of square with sides: " << width << " is: " << square_perimeter << std::endl;
        }
        catch (const std::overflow_error &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
};

int main()
{
    // Create a Rectangle object with maximum float value and breadth 20
    Rectangle rect1(std::numeric_limits<float>::max(), 20);
    rect1.displayArea();
    rect1.displayPerimeter();

    // Create a Square object with side length 200.3
    Square sq1(200.3);
    sq1.displayArea();
    sq1.displayPerimeter();

    return 0;
}