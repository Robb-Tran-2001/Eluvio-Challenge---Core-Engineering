# Eluvio-Challenge---Core-Engineering

In the original solution, sol_old.cpp, I intended to solve the challenge in C++. The initial attempt was to use dynamic programming, which is very much similar to the
problem of finding the longest common substring between 2 strings. However, this approach had a significantly long runtime, as I have to iterate over every possible
pair of files to read in as an array of bytes (a string), then call the algorithm on each pair. Worst case, the runtime would have been O(n^2) for choosing pairs of strands
from n (n = 10 in the sample) files and each iteration would take O(m*k), m and k being the lengths of each strand in the pair. Thus, it would have been O(n^2 * m * k).

I did some thinking and came up with the idea of using suffix trees, which had a significantly faster runtime by taking advantage of the data structure. However, implementing
a suffix tree from scratch in C++ would require a large amount of time, so I decided to go with Python, which had a built in suffix tree that supports finding the longest
common substring. After reading in the files and constructing the suffix tree, I ran lcs() (the provided function) to determine the longest common substring (and therefore the
sequence of bytes) between 2 files. Then I find the position of said substring across those files to find where the offset was.

The python approach was much faster and also supported the longest common substring between ALL strands (denoted by lcs1 by my code). I wrote the function get_offset to determine
the offset of the LCS across all strands for general purpose use (-1 if there is none), but it definitely would have been just as easy to find the subtring offset just for the 2 
files that my algorithm determined to have the longest common substring. This approach reduces runtime to O(n^2) and finding the LCS takes O(m + k), m and k being the length
of each string in the pair. Thus, it was O(n ^ 2 * (m+k)), a significant improvement.
