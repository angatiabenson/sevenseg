# Seven Segment Display Project

## Overview

This project presents a C program capable of rendering numbers in a seven-segment display style within the console. It uses asterisks (`*`) to visually represent the segments that are 'on' for each digit of a user-entered number. The program allows for customization of the segment lengths, both horizontal and vertical, providing flexibility in the display size and shape. This README provides all necessary information to understand, compile, and execute the program, alongside an explanation of its structure and customization options.

## Prerequisites

To run this program, you need:

- A C compiler (e.g., GCC or Clang)
- A standard C library
- A terminal or command-line interface to execute the program

## Compilation

To compile the program, use the following command in your terminal:

```bash
make
```

This will compile `sevenseg.c` and create an executable named `sevenseg`.

## Usage

After compilation, you can run the program using:

```bash
./sevenseg
```

Upon execution, the program will guide you through the following steps:

1. **Enter Horizontal Segment Length**: Input the length for the horizontal segments (between 3 to 40). This defines how wide the digits will appear.
2. **Enter Vertical Segment Length**: Input the length for the vertical segments (between 3 to 40, but within a sensible range in relation to the horizontal length) to define the height of the digits.
3. **Enter a Number**: Type a positive integer to see its seven-segment display representation. The program supports handling of long integers within the limits of the input buffer.

To exit the program, press Ctrl + D (EOF on most systems) after a number input prompt.

## Customization

The program can be easily modified to change the display characteristics. For instance, changing the representation characters (`*` for segments and spaces for gaps), adjusting the space between digits, or modifying the input limits for segment lengths. These adjustments can be made in the respective functions or variables within the code.

## Limitations

- The program is designed to work within console limitations and might not display large numbers properly if the terminal width is exceeded.
- Vertical segment length should be chosen with consideration to the terminal's height to avoid display issues.

## License

This project is open-source and free to use or modify. No specific licensing is applied, making it suitable for educational purposes or as a base for more complex projects.
