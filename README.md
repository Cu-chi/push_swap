*This project has been created as part of the 42 curriculum by equentin, cpietrza.*

# Description
The goal of the project is to learn about algorithmic complexity by sorting 2 stacks with a defined set of operations to manipulate both stacks.
This project has to be a program that calculates and displays on the standard output the smallest program made of [Push swap language](#push-swap-language) operations, that sorts the integers received as arguments.   
We have to implement 3 algorithm of different complexity (see [algorithms selected](#algorithms-selected)).  
Bonus: checker  
We also implemented a seperate program that checks if the instructions sorts the stacks.

# Instructions
Installation & Usage
### Compilation
This project uses a Makefile for compilation. You need `make` and `clang` (or `gcc`) installed.

1. **Clone the repository:**  
   Since this project uses external libraries as submodules, use the recursive flag:
   ```bash
   git clone --recursive https://github.com/Cu-chi/push_swap.git
   cd push_swap
   ```

2. **Build**  
	Run
	```bash
	make
	```
	This will generate the `push_swap` executable.

### Cleaning
`make clean`: Removes object files (.o) and temporary dependency files.  
`make fclean`: Removes object files and the push_swap executable.  
`make re`: Performs a full recompilation (fclean + make).

### Execution
Run the program with an optional argument and a needed list of integers as arguments  
`./push_swap [OPTIONS] <list_of_integers>`  
or  
`./push_swap [OPTIONS] <arg1> <arg2> <arg3> ...`

# Resources
[Analysis of algorithms](https://en.wikipedia.org/wiki/Analysis_of_algorithms)  
[Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))  
[Selection sort](https://en.wikipedia.org/wiki/Selection_sort)  
[Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort)  
[Radix sort](https://en.wikipedia.org/wiki/Radix_sort)  
[Radix sort visualization](https://www.cs.usfca.edu/~galles/visualization/RadixSort.html)  
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

# Algorithms Selected

### Simple Algorithm: Selection Sort ($`O(n^2)`$)
**Rationale:** We chose a stack-adapted Selection Sort for its conceptual simplicity. Since the goal is to sort a small number of elements, minimizing code complexity was prioritized over execution speed.

**Complexity Argument:** The algorithm searches for the minimum element in stack A and pushes it to stack B.  
Let $n$ be the number of elements.
* To find the minimum, we traverse the stack: cost $\approx n$.
* We repeat this operation for each element until stack A is empty: $n$ times.

The total operations can be modeled as the sum of integers from 1 to $n$:  
$\sum_{i=1}^{n} i = \frac{n(n+1)}{2} = \frac{n^2 + n}{2}$

Asymptotically, the quadratic term $n^2$ dominates. Thus, the time complexity is **$O(n^2)$**.

---

### Medium Algorithm: Chunk Sort ($`O(n\sqrt{n})`$)
**Rationale:** To handle larger sets (e.g., 100 integers), scanning for a specific minimum becomes too costly. We implemented a **Chunk Sort** (a variation of Bucket Sort). Instead of searching for a single number, we search for *any* number within a specific range (chunk). This increases the probability of finding a candidate near the top of the stack, drastically reducing rotation costs.

**Complexity Argument:** * We divide the stack A into $k$ chunks. A balanced choice is $k \approx \sqrt{n}$.
* When searching for an element of the current chunk, since elements are uniformly distributed, we perform on average $\sqrt{n}$ rotations to find one.
* We repeat this for all $n$ elements.

Total cost $\approx n \times \sqrt{n}$. Thus, the complexity is **$O(n\sqrt{n})$**.

---

### Complex Algorithm: Radix Sort ($`O(n\log n)`$)
**Rationale:** For the largest datasets (500+ integers), comparison-based sorts struggle to stay within the instruction limits. We implemented a **LSD (Least Significant Digit) Radix Sort** in Base 2 (Binary).
By pre-processing input values into simplified ranks ($0$ to $n-1$), we can process the numbers bit by bit using the two stacks as binary buckets (Stack B for 0, Stack A for 1).

**Complexity Argument:** Radix sort complexity is generally $O(n \times k)$, where $k$ is the number of bits (digits) required to represent the largest number.
* With our rank normalization (values from $0$ to $n-1$), the max value is $n$.
* The number of bits $k$ required to represent $n$ is $\log_2(n)$.
* We iterate through all $n$ elements for each of the $k$ bits.

Total operations $\approx n \times \log_2(n)$. Thus, the complexity is **$O(n\log n)$**.