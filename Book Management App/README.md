# Overview
This assignment is to practice manipulating linked lists. The program msut read
text files, each of which contains information about books in a particular category, such
as history or science. Create a linked list of books in each category, and then
manipulate these lists in various ways. The program should not make any
assumptions about which categories of books, the number of categories, or the number
of books. A separate text file will contain the names of the categories.
Implement singly-linked lists for this assignment, where each node of the list has a link to
the next node. Do not use the list template from the Standard Template Library. 

## Input file categories.txt
Input text file categories.txt will contain the names of the book categories, one
name (a single word) per line. Your program should not make any assumptions in
advance about which categories and how many of them.

## Category book lists
For each category, such as history, there will be a corresponding text file, such as
history.txt, that contains information about books in that category, one book per line.
Each line has the format
isbn,last,first,title

Create a linked list of books for each book file. Each category book list must be sorted
by ISBN, so as you read each book, insert it into the list at the proper position. Do not
insert a book if the list already contains the book’s ISBN. After you’ve created each
category book list, print the list and include the count of books in the list.
Overload the >> and << operators to read and write a book.
childrens.txt
history.txt
science.txt
mystery.txt

## Merged list
Next, merge all the category book lists into a single linked list, sorted by ISBN. Print the
merged list and include the count of books in the list.

## Author lists
Finally, split the merged list into two new lists, each sorted by ISBN. One list should
contain books with authors whose last names start with A – M, and the other list should
contain books with authors whose last names start with N – Z. Print each author list and
include the count of books in the list.
