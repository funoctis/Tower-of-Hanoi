# Tower-of-Hanoi

**Tower of Hanoi is a puzzle game, where one has to move disks of different size (or in this case, numbers) between poles in order to complete the puzzle.**

# Functions used

- fillSrc() 
- displaylevel() 
- display() 
- push(int x) 
- pop() 
- gameWinCondition() 

# Why stacks?

Tower of Hanoi is a game in which the disks are inserted and removed on the poles only from end, i.e. top. This makes stack the ideal data structure to be used as it follows the similar principle of Last in First Out (LIFO). 

# Algorithm
```
1. Initialize the poles, with pole 0 initially having all the numbers.
2. Display the poles to the user.
3. Ask user for their move.
4. Make changes as specified by user in 3.
5. Check for Game Win Condition. 
    - if true, goto 6.
    - else goto 2.
6. Print Congratulatory message.
7. Exit.
```





