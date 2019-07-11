# jpb358_CS283_lab1
This is the repo for jpb358's Lab 1 Assignment for CS283.
This assignment was worked on in junction with Josh Kirschner(jak423).

Run a.out after compiling with gcc; should do all parts at once. Did basic strings for part 2, basic nums for all else that needed nums.

This particular week I had the most trouble with the swap function-it took a while to figure out the basic swap functionality that we should use, and then how to implement it in C. We managed to get the basic swap functionality working, but then got stuck with the data values disappearing-caused by us not resetting the pointer of the head val, which meant we essentially had a weirdly organized list. Eventually that got resolved and part 5 was easy enough, even if I'm not sure why the remove and get functions are even needed, as the basic intent of the question was to learn how to realloc at the end.