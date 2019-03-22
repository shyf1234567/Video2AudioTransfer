# Video2AudioTransfer
### About our target
Our target for this project is to write a program which is able to take a video as input, process its data and finally output STI.  

### Tools and library 
Our job is done with Visual Studio(2013/2015) and C++, as well as OpenCV library. 

### How we do our work
Our work is done in three parts.

#### Part 1 
We make use of OpenCV Library to read a video and process every frame of it. To be more specific, we copy over the center row from each frame, turned sideways, and put the taken data into a column of an STI. Then the STI has the same number of rows as the number of columns in the original video, and a number of columns equal to the number of frames. We make a simple mp4 file with wipe, which has obvious change in the color, with dark background in the previous half and with light background in the following half, so we get a typical STI with the diagonal.
#### Part 2 
We adopt the histogram difference method which is introduced in the project requirement. First we normalize the three-dimensional data (R,G,B) into two-dimensional chromaticity (r,g), and we set up histograms so that we put the number of points in a certain value interval into the corresponding place. Now the histogram elements contains integers, which are numbers of points. And we divide them by the total number of the points, we get a histogram H with float type data. After that, we compare Ht, which is the histogram produced by the frame at time t, with Ht-1, and with a certain equation introduced in the project requirement, we get the value I for the ith column, which is produced by the frame t and t-1. We put the value I in the position (t-1, i) of our final STI and the whole STI is made in the same way. And we want to present the look an original STI should be so we didn't resize the input video, which may result in longer running time of the program and some noise. The black points indicates that the current frame is very different from the previous one while the white points suggests the current frame is the same or very much similar to the previous frame. After we add a threshold value, i.e., we make those points whose value is larger than 0.7 white, and the others black, it becomes clear.
#### Part 3
We also try our program on video dissolves. Lastly, we make the GUI and the work is done. To point out, MFC doesn't provide a thread for itself, which can lead to the GUI's no response when our program is running, leaving the options on the GUI no use when it's processing a video. In order to fix it, we meant to make MFC an independent thread and run parallel with our program, but that can slow down the process speed hence we don't do that. We make a sample video for this program which can get a relatively obvious STI diagonal, which is 720p and 10 seconds long. To generate its STI, it can take 10 minutes to half an hour depending on the computer.

### Thoughts about this project
It's a nice project enabling us to gain a further understanding of the data structure of videos. We learn things from it. But I should say that it limited my outstanding performance since how the project should be done is determined in the requirement step by step.
