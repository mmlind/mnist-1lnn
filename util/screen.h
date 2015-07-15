/**
 * @file screen.h
 * @brief Utitlies for advanced input and output to terminal screen
 * @author Matt Lind
 * @date July 2015
 */

typedef enum Color {WHITE, RED, GREEN, YELLOW, BLUE, CYAN} Color;

static const Color DEFAULT_TEXT_COLOR = WHITE;




/**
 * @brief Clear terminal screen by printing an escape sequence
 */

void clearScreen(void);




/**
 * @brief Set text color in terminal by printing an escape sequence
 */

void setColor(Color c);




/**
 * @brief Set cursor position to given coordinates in the terminal window
 * @param row Row number in terminal screen
 * @param col Column number in terminal screen
 */

void locateCursor(const int row, const int col);
