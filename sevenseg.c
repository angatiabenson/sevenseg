#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void print_horizontal_segment(int digit, int segments[10][7], int segment_index, int length)
{
    if (segments[digit][segment_index])
    {
        printf(" "); // Space before the segment
        for (int i = 0; i < length; i++)
        {
            printf("*"); // The segment itself
        }
        printf(" ");
    }
    else
    {
        for (int i = 0; i < length + 2; i++)
        {
            printf(" "); // Space for the missing segment
        }
    }
}

void print_vertical_segment(int digit, int segments[10][7], int left_index, int right_index, int length, int vertical_space)
{
    for (int line = 0; line < length; line++)
    {
        if (segments[digit][left_index])
            printf("**"); // Two asterisks for the left segment
        else
            printf("  "); // Space for the missing left segment

        for (int j = 0; j < vertical_space; j++)
            printf(" "); // Space in the middle

        if (segments[digit][right_index])
            printf("**"); // Two asterisks for the right segment
        else
            printf("  "); // Space for the missing right segment
    }
}

void print_digits(char *str, int horiz_length, int vert_length)
{
    int segments[10][7] = {
        {1, 1, 1, 0, 1, 1, 1}, // 0
        {0, 0, 1, 0, 0, 1, 0}, // 1
        {1, 0, 1, 1, 1, 0, 1}, // 2
        {1, 0, 1, 1, 0, 1, 1}, // 3
        {0, 1, 1, 1, 0, 1, 0}, // 4
        {1, 1, 0, 1, 0, 1, 1}, // 5
        {1, 1, 0, 1, 1, 1, 1}, // 6
        {1, 0, 1, 0, 0, 1, 0}, // 7
        {1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 1, 1, 0, 1, 1}  // 9
    };

    int length = strlen(str);

    // Loop over each row of the digit representation
    for (int row = 0; row < 2 * vert_length + 3; row++)
    {
        bool isSegmentHorizontal = false;

        if ((row == 0) || (row == vert_length + 1) || (row == 2 * vert_length + 2))
        {
            isSegmentHorizontal = true;
            for (int hr = 0; hr <= 1; hr++)
            {
                for (int j = 0; j < length; j++)
                {
                    int digit = str[j] - '0';

                    if (row == 0)
                    { // Top horizontal segment
                        print_horizontal_segment(digit, segments, 0, horiz_length);
                    }
                    else if (row == vert_length + 1)
                    { // Middle horizontal segment
                        print_horizontal_segment(digit, segments, 3, horiz_length);
                    }
                    else if (row == 2 * vert_length + 2)
                    { // Bottom horizontal segment
                        print_horizontal_segment(digit, segments, 6, horiz_length);
                    }
                    printf("    ");
                }

                if (hr == 0)
                {
                    printf("\n");
                }
            }
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                int digit = str[i] - '0';

                if (row > 0 && row < vert_length + 1)
                { // Upper vertical segments
                    print_vertical_segment(digit, segments, 1, 2, 1, horiz_length - 2);
                }
                else if (row > vert_length + 1 && row < 2 * vert_length + 2)
                { // Lower vertical segments
                    print_vertical_segment(digit, segments, 4, 5, 1, horiz_length - 2);
                }

                // Add spacing between digits
                if (i < length - 1)
                {
                    printf("    ");
                }
            }
        }

        printf("\n");
    }
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int main()
{
    int horiz_length, vert_length;

    // Input for horizontal segment length
    do
    {
        printf("This is a 7-segment display! Press Enter after providing any number on the keyboard.\n");
        printf("Please enter the length of horizontal segments (from 3 to 40): ");
        if (scanf("%d", &horiz_length) != 1 || horiz_length < 3 || horiz_length > 40)
        {
            printf("Length is not acceptable. Please try again.\n");
            clear_input_buffer();
        }
        else
        {
            break;
        }
    } while (true);

    // Input for vertical segment length
    do
    {
        printf("Now, enter the length of vertical segments (from 3 to 40): ");
        if (scanf("%d", &vert_length) != 1 || vert_length < 3 || vert_length > 40 ||
            vert_length > 2 * horiz_length || vert_length < horiz_length / 2)
        {
            printf("Length is not acceptable. Please try again.\n");
        }
        else
        {
            break;
        }
    } while (true);

    char input_buffer[20]; // Maximum length for the input
    clear_input_buffer();

    while (true)
    {
        printf("Enter a positive integer (or press Ctrl + D to exit): ");

        if (!fgets(input_buffer, sizeof(input_buffer), stdin))
        {
            printf("\n\nExiting the program...\n\n");
            break; // Exit loop if fgets returns NULL, which means EOF was encountered
        }

        // Remove the newline character from the input buffer
        char *newline_char = strchr(input_buffer, '\n');
        if (newline_char)
        {
            *newline_char = '\0';
        }

        int num;
        if (sscanf(input_buffer, "%d", &num) != 1 || num < 0)
        {
            printf("\nInput is not acceptable. Please try again.\n\n");
            continue; // Ask for input again
        }

        printf("\n");
        // Display the seven-segment representation of the entered number
        print_digits(input_buffer, horiz_length, vert_length);
    }

    return 0;
}