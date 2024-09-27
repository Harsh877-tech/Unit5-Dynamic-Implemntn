# Unit5-Dynamic-Implemntn
# Longest Common Substring Finder

This C++ program finds the longest common substring between two input strings of equal length. It uses a dynamic programming approach and visualizes the process with a 2D table.

## Key Components

1. printLCSTable function:
   - Displays the dynamic programming table used to find the longest common substring.
   - Shows the input strings along the top and left sides of the table.
   - Uses a horizontal line to separate the table header from its contents.

2. findLCS function:
   - Implements the core algorithm to find the longest common substring.
   - Creates and fills a 2D table using dynamic programming.
   - Keeps track of the maximum length substring and its ending position.
   - Calls printLCSTable to display the filled table.

3. main function:
   - Handles user input for the two strings.
   - Checks if the input strings have equal length.
   - Calls findLCS to find the longest common substring.
   - Displays the result and its length.

