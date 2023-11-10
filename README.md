# Palindrome
A palindrome is any word, phrase, or sentence that reads the same forward and backward. 
Here are some well-known palindromes: 
* Able was I, ere I saw Elba 
* A man, a plan, a canal, Panama 
* Desserts, I stressed 
* Kayak    
We will write two programs to determine if a string argument is a palindrome.
The first will be an iterative solution that uses a queue and a stack,
the second will be a recursive solution. For this project,
we will ignore any non-alphanumeric characters (space, punctuation, non-printable characters).

 ## Iterative Version  
Add the characters of the string being tested to both a stack and a queue. Since each data structure 
removes items from the opposite ends, the proper characters are tested at each step. 

## Recursive solution  
Test_string returns -1 for a palindrome, 1 otherwise. Implemented the recursive test as follows: 
* Strings of length 1 or less are palindromes; and
* For larger strings, if the first and last characters agree, strip these two characters from the string and test the remaining characters.
