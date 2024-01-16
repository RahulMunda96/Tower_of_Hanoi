The Tower of Hanoi is a classic mathematical puzzle that involves moving a set of disks from one rod to another, following some simple rules. The puzzle was invented by the French mathematician Édouard Lucas in the 19th century, and it is also known as the Tower of Brahma or the Lucas Tower12.
The puzzle consists of three vertical rods and a number of disks of different sizes, which can slide onto any rod. The disks are initially stacked on one rod in order of decreasing size, with the smallest disk on top. The objective of the puzzle is to move the entire stack to another rod, obeying the following rules:

1 Only one disk can be moved at a time.
2 Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
3 No disk may be placed on top of a smaller disk.

The puzzle can be solved using a recursive algorithm, which can be implemented in various programming languages. The algorithm works as follows:

To move n disks from rod A to rod C, using rod B as an auxiliary rod:

If n is 1, then move the disk from A to C and return.
Otherwise, move n-1 disks from A to B, using C as an auxiliary rod.
Then move the remaining disk from A to C.
Finally, move n-1 disks from B to C, using A as an auxiliary rod.



The minimum number of moves required to solve the puzzle is 2n−1
, where n is the number of disks
