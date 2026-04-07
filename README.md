_*This project has been created as part of the 42 curriculum by dishagia.*_

## Description

Push_swap is an algorithmic challenge requiring a C program that sorts a stack of unique integers using only 12 specific stack operations (sa/sb/ss, pa/pb, ra/rb/rr, rra/rrb/rrr). The goal is to output the **shortest sequence** of instructions to sort stack A in ascending order, with stack B starting empty. Performance targets: 100 numbers in <700 operations, 500 numbers in <5500 operations for full marks.

This implementation features:
- Circular doubly-linked list stacks with manual size tracking
- Robust argument parsing (multiple args or space-separated string)
- Index normalization (values → ranks 0 to n-1) for radix sort
- Custom optimal sorting for 2-5 elements
- Bitwise radix sort for larger stacks

## Instructions

### Compilation
```bash
make                 # Standard build
make fclean && make  # Clean rebuild
```

### Usage Examples
```bash
# Basic usage
./push_swap 2 1 3 6 5 8

# Single argument with spaces
./push_swap "2 1 3 6 5 8"

# Test operation count
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Test with checker (provided by 42)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

### Error Handling

./push_swap 0 one 2 # → Error (non-numeric)
./push_swap 1 1 2 # → Error (duplicates)
./push_swap 2147483648 # → Error (INT overflow)
./push_swap # → (no output, exits cleanly)


## Files Structure

| File | Purpose |
|------|---------|
| `push_swap.h` | Structures + function prototypes |
| `main.c` | Program entry + initialization |
| `parser.c` | Argument validation + stack filling |
| `indexes.c` | Rank assignment via bubble sort |
| `radix.c` | Main radix sorting algorithm |
| `sorting.c` | Small case optimizations (2-5 elements) |
| `op1.c/op2.c/op3.c` | 12 push_swap operations |
| `operations_helpers.c` | Low-level stack manipulation |
| `split.c` | Custom `ft_split` implementation |
| `utils.c` | Numeric validation helpers |
| `error_and_free.c` | Error handling + memory cleanup |

## Algorithm Overview

1. **Parse**: Validate integers, check duplicates/overflow
2. **Index**: Replace values with ranks (0=smallest, n-1=largest)
3. **Sort**:
   - ≤2 elements: Simple check/swap
   - 3 elements: Hardcoded optimal cases (1-2 ops max)
   - 4-5 elements: Push 1-2 smallest to B, sort 3, push back
   - >5 elements: **Radix sort** on index bits (log₂(n) passes)

## Performance Status
| Size | Target | Current | Status |
|------|--------|---------|--------|
| 100  | <700   | ~1100   | Minimal pass ✓ |
| 500  | <5500  | ~8500   | Minimal pass ✓ |

*Chunk-based optimization needed for full marks.*

## Resources

- **42 Push_swap Subject PDF** - Official project specification
- **Doubly-linked lists** - Core data structure reference
- **[Bitwise operations in C](https://en.wikipedia.org/wiki/Bitwise_operations_in_C)** - Used for radix sort (`>>` bit shift, `& 1` bit test)
- **Radix sort algorithm** - Sorting theory documentation
- **42 Checker documentation** - Validation binary usage

**AI Usage**: 
- Algorithm research (radix sort vs chunk strategies)
- Debugging assistance for rotate function bugs
- **No code generation** - All implementation written manually
- README structure and performance analysis suggestions