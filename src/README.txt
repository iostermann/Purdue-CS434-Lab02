I have implemented all the required pieces of Lab 2 as well as the extra credit movie generator.

I am fairly certain that all dependencies are either statically linked or included in this distribution.
This includes:
	lodePNG for an export library
	glm headers for vector manipulation
	antlr4-runtime which I compiled from source and runs the parser that is generated
	ffmpeg for creating the final movie

I have also stripped out my git repo and .vs precompiled headers for submission size but there is still a lot 
of space taken up by the inclusion of ffmpeg and precompiled antlr runtime binaries

The source is in a directory called ../Lab2/
The solution is split into two projects. The first is Ray Tracer which generates an exe
	Ray Tracer by default takes in the (altered) cornell2.txt scene description provided and optionally takes
	command line arguments of either the scene description filepath, or the scene description filepath followed by the output filename.
	Should you desire and have a working antlr4 environment, the command to compile the parser is in the .g4 file
	
The second is Movie Maker which is also an exe
	It traces each frame independently and renders a movie at 60fps from the frames with very low compression for visual fidelity.
	By default it will render 60 frames for a second of video to prove it works but the number of frames is the first command line
	argument if you want to specify.
	
This directory is called ../Release/
I have provided both a directory for the lab2 project as well as as standalone directory with only the exe's and dependencies
so that you can just run them. In the standalone presentation dir there is also a 1 minute video that I prerendered overnight.

