ImageFilteringQt4
=================

[For More Information](http://macclayton.com/projects/image-filtering)

#Intro
This application is a quick demonstration of a recursive noise filtering algorithm.

##Qt4 Library
We'll be using the [Qt Project](http://qt-project.org/) as an easy way to generate and display an image pallet. The `qt4display` library provides an interface and abstracts some of the UI generation away from the user.

#Algorithm
The algorithm works by finding contiguous sets of pixels of the same color, by visiting all neighboring pixels. If the total number of pixels in a "blob" is less than a determined threshold (we'll use 10px), then the region will be classified as noise and removed (set to white).
1. Define a boolean array with one entry for each pixel in the image (the array should be initialized to false).
2. Find the next pixel that has not been visited, starting with the initial pixel (0,0) on the first iteration.
3. Mark the pixel as visited, noting the color and pushing it onto a [deque](http://en.wikipedia.org/wiki/Double-ended_queue) (double ended queue). We use a deque so that we can push elements onto the back <em>and</em> pop elements off the front.
4. Create a vector of pixel numbers 
5. While the pending queue is not empty:
    1. Pop the pixel index from the front of pending.
    2. Push this value (pixel index) to the current region vector
    3. For each neighboring pixel (up, down, left, right, no diagonals), if the color of the neighbor matches the color of the current region and it has not been visited, mark the neighbor as visited and push it to the back of the deque. If it has already been visited, then ignore it. You must be careful about the boundary conditions.
6. At this point, the region that started with the pixel found in step #2, is in the region vector. If the size of the vector is leess than the threshold (10px), then it's noise. For this scenario, we'll toggle the color of the region (either black -> white, or white -> black).
7. When all the pixels have been visited, filtering is complete.

### Please check out the source code for a full implementation.

#Building the Application
This application has been tested on OSX 10.9 using the Qt4 library installed by [Homebrew](http://brew.sh/).
1. First, run `qmake` from the terminal to build the Makefile.
2. Then compile using `make`
3. To run: `./ImageFilteringQt4 test_in_512.pnm`