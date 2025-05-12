# Logical Gate Project

This project implements various logical gates (AND, OR, NOT, XOR, If Then, If AND Only If) using character inputs `'t'` and `'f'` to represent true and false. The program allows users to input values for `P` and `Q`, select a logical operation, and displays the result.

## Files

- **src/LogicalGate.c**: Contains the implementation of the logical gates and the main function for user interaction.

## Features

- **Logical Gate Simulation**: The software simulates the behavior of six logical gates (AND, OR, NOT, XOR, If Then, If AND Only If) using user-provided inputs. It evaluates the logical relationship between two boolean values (`P` and `Q`) and displays the result.
- **Case Insensitivity**: The program accepts both uppercase (`T`, `F`) and lowercase (`t`, `f`) inputs for `P` and `Q`. All inputs are automatically converted to lowercase.
- **Input Validation**: The program ensures that only valid inputs (`t` or `f`) are accepted for `P` and `Q`. Invalid inputs prompt the user to re-enter the values.
- **Interactive Menu**: Users can select from six logical operations or exit the program.

## Usage

1. Clone the repository to your local machine.
2. Navigate to the `src` directory.
3. Compile the `LogicalGate.c` file using a C compiler:
   ```bash
   gcc LogicalGate.c -o LogicalGate
   ```
4. Run the compiled program.
5. Follow the prompts to enter values for `P` and `Q`, and select the desired logical operation.

## Logical Operations

- **AND**: Returns true if both `P` and `Q` are true.
- **OR**: Returns true if at least one of `P` or `Q` is true.
- **NOT**: Returns the negation of `P` and `Q`.
- **XOR**: Returns true if `P` and `Q` are different.
- **If Then**: Returns false if `P` is true and `Q` is false.
- **If AND Only If**: Returns true if both `P` and `Q` are either true or false.

## Contributing

Feel free to submit issues or pull requests for improvements or bug fixes.
