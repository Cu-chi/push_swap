*This project has been created as part of the 42 curriculum by equentin, cpietrza.*

# Description
The goal of the project is to learn about algorithmic complexity by sorting 2 stacks with a defined set of operations to manipulate both stacks.
This project has to be a program that calculates and displays on the standard output the smallest program made of [Push swap language](#push-swap-language) operations, that sorts the integers received as arguments.   
We have to implement 3 algorithm of different complexity (see [algorithms selected](#algorithms-selected)).  
Bonus: checker  
We also implemented a seperate program that checks if the instructions sorts the stacks.

# Instructions

TODO

# Resources
[Analysis of algorithms](https://en.wikipedia.org/wiki/Analysis_of_algorithms)  
[Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
#### Push swap language
sa (swap a): Swap the first two elements at the top of stack a.  
Do nothing if there is only one or no elements.

sb (swap b): Swap the first two elements at the top of stack b.  
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.  
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.  
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by one.  
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by one.  
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by one.  
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by one.  
The last element becomes the first one.

rrr : rra and rrb at the same time.

# Algorithms selected
**Simple algorithm $`O(n^2)`$:**  
TODO

**Medium algorithm $`O(n\sqrt{n})`$:**  
TODO

**Complex algorithm $`O(n\log{n})`$:**  
TODO
