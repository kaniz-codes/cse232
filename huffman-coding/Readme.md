# Huffman coding
Huffman coding is a technique of compressing data to reduce its size without losing any of the details.

## Example

![practice](huffman-coding\notes\practice-ques.png)

## Huffman Coding vs Fixed-Length Coding

| Character | Frequency | Fixed-Length Code | Variable-Length Code (Huffman) |
|-----------|-----------|-------------------|---------------------------------|
| a         | 45        | 000               | 0                               |
| b         | 13        | 001               | 101                             |
| c         | 12        | 010               | 100                             |
| d         | 16        | 011               | 111                             |
| e         | 9         | 100               | 1101                            |
| f         | 5         | 101               | 1100                            |


## Why we use huffman coding

1. **Optimal Compression:**
 Huffman coding produces the shortest possible average code length for a given set of charecter frequencies, making it "space efficent".

2.  **Lossless Encoding:**
 It preserves 100% of the original data

3. **Real world Application**
- File compression tools (e.g. ZIP)
- Image formats (e.g. JPEG)
- Audio compression
- Text compression and transmission