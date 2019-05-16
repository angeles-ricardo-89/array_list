arrayed_list
============

arrayed_list it's a simple c-header that implements a list over a void* array using macros.

I developed this some years ago in order to use in embedded devices with limited RAM and serious memory fragmentation problems.

I tried to port some memory management libraries to that device, but it was taking more than expected, so I decided to indentify parts in the code where I could improve memory access, and this library helped me a lot.

It worked for me and I hope it works for you.

Use instructions
================

Just copy arrayed_list.h to your include directory and include it in your source(s) file(s), it does not require any special compilation flag.

array_list.c is an example of use of this library.

I've only tested it with gcc, and armcc compilers.

thanks for your interest,
Ricardo Angeles
