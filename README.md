# **RLE Compression Program**

## **Overview**
This program implements a **Run-Length Encoding (RLE)** algorithm to compress text. It replaces sequences of repeated characters with the character followed by the number of repetitions. For example, the input `aaabbbcc` compresses to `a3b3c2`.

If the compression process doesn't reduce the size of the input, the program simply returns the original text to ensure efficiency.

---

## **Usage**

### **1. Compile the Program**
Use the provided `Makefile` to compile the program:

```bash
make
```

To clean compiled files:

```bash
make clean
```

To rebuild the project from scratch:

```bash
make re
```

### **2. Run the Program**
To run the program, pass an input file and an output file as arguments:

```bash
./rle_compressor <input_file> <output_file>
```

#### **Input Example**
If the input file contains:
```
aaabbbbcccdde
```

#### **Output Example**
The output file will contain:
```
a3b4c3d2e1
```

If the input contains no repeated characters, the program will simply return the original string.

---

## **Limitations**
- If the input text contains no repeated characters, the compressed result will not be smaller.
- The program is not designed for binary or non-printable data.
- Proper error handling is implemented for invalid input files.

---

## **Files in the Project**
- `main.c`: Contains the implementation of the compression logic.
- `Makefile`: Automates the build process.
- `README.md`: Documentation for the program.

---

## **Author**
This project was entirely developed by [**Joker Joe**].