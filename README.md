# Circut-Simulator-Code-Sample
Greetings viewer!

This was one of my favorite C coding projects for my Computer Architecture class which I wanted to share.

Essentially it takes in a txt file with a list of inputs, outputs, and “circuits”, such as the following:

—

INPUT 4 a b c d

OUTPUT 3 x y hello

AND c hello y

OR a b hello

XOR a d x

—

How the text above is interpreted:

There are four inputs: a, b, c, d
There are three outputs: x, y, hello

y = c && hello;

hello = a || b;

x = (a || d) && !(a && b);

The result is a truth table with every possible combination of input, so 2 ^ [number of inputs] cases.

— a more complex example — with multiplexer and decoder support —

INPUT 6 in1 in2 in3 sin1 sin2 sin3

OUTPUT 9 ou1 ou2 ou3 ou4 ou5 ou6 ou7 ou8 fout

DECODER 3 in1 in2 in3 ou1 ou2 ou3 ou4 ou5 ou6 ou7 ou8

MULTIPLEXER 3   1 0 1 0 1 0 1 0     sin1 sin2 sin3 fout

—

Feel free to modify the test documents and run it in an IDE

—

Known issue: Some platforms send back a “zsh: segmentation fault”, an issue which I still haven’t figured out despite looking into possible memory allocation problems - feedback is welcome!
