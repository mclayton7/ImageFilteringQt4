// Noise Removal From Images
// Mac Clayton
// ECE3090, Spring 2012

#include <iostream>
#include "qt4display.h"
#include <vector>
#include <deque>

using namespace std;

int main(int argc, char **argv)
{
    
    //Create QT Application called "a"
    QApp a(argc, argv); // Required by Qt library
    
    //Create a QT Window in application a called "d"
    QDisplay d(a);
    
    //Load the Image pointed to by argv[1]
    d.Load(argv[1]);
    // Pointer to the data loaded in the image
    unsigned char* data = d.ImageData();
    //Get Width and Height:
    int width = d.width();
    int height = d.height();
    
    d.Show();
    d.UpdateRate(40);

    //Set the number of pixels in the image:
    int nPixels = width * height;
    //Instantiate some misc variables to help with readability:
    int top, bottom, left, right, pixel, temp;
    //Creates a byte from 0-255
    unsigned char color;
    //Create a vector to know if a pixel has been visited or not:
    std::vector<bool> visited(nPixels, false);
    //Create pending deque:
    std::deque<int> pending;
    //Create region vector:
    std::vector<int> region;
    //Iterate over all the pixels in the visited vectors
    for(int i = 0; i < nPixels; i++)
    {
        if(visited[i] == false)
        {
            //Mark as visited:
            visited[i] = true;
            
            //Store pixel color:
            color = data[i];
                        
            //Push onto pending:
            pending.push_back(i);
            
            //While pending que isn't empty:
            while(!pending.empty())
            {
                //Get the first pixel off the pending deque:
                pixel = pending.front();
                pending.pop_front();
                
                //Add to current region vector:
                region.push_back(pixel);
                
                //Check Top Pixel:
                //Not on the top row, same color, not visited
                top = pixel - width;
                if((top > 0) && (data[top] == color) && (visited[top] == false))
                {
                    //Mark as visited:
                    visited[top] = true;
                    
                    //Add to back of pending vector:
                    pending.push_back(top);
                }
                
                //Check Bottom Pixel:
                //Less than the last row, same color, not visited
                bottom = pixel + width;
                if((bottom < (nPixels - width)) && (data[bottom] == color) && (visited[bottom] == false))
                {
                    //Mark as visited:
                    visited[bottom] = true;
                    
                    //Add to back of pending vector:
                    pending.push_back(bottom);
                }
                
                //Check Left Pixel:
                //Greater than 0, not on the left edge, same color, not visited
                left = pixel - 1;
                if((left > 0) && (left % width != 0) && (data[left] == color) && (visited[left] == false))
                {
                    //Mark as visited:
                    visited[left] = true;
                    
                    //Add to back of pending vector:
                    pending.push_back(left);
                }
                   
                //Check Right Pixel:
                //Greater than 0, not on the right edge, same color, not visited
                right = pixel + 1;
                if((right < nPixels) && (right % width != (width - 1)) && (data[right] == color) && (visited[right] == false))
                {
                    //Mark as visited:
                    visited[right] = true;
                    
                    //Add to back of pending vector:
                    pending.push_back(right);
                }
            }//End While loop
            
            //Empty the Region vector:
            //If the region is noise:
            if(region.size() < 10)
            {
                while(!region.empty())
                {
                    //Pop an index value off the back of region
                    temp = region.back();
                    region.pop_back();
                    //Invert the color:
                    data[temp] = 0xff - color;
                    //Update the individual Pixel:
                    d.Update((temp % width), (temp/width));
                }
            }
            else
            {
            //If it's not noise, empty the vector
                region.clear();
            }
        }//End if visited false
    }//End iterating over every pixel
    
    //Keep the Window Loaded
    a.Run();
    //The End
}
