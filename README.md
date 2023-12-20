# P1 Project- Optimizing pathfinding and maneuverability in minefields

### Guide to using the program
To start the program, build the program and run it. It is a console 
application. You will be prompted to answer 3 questions: 
1. The troop type
2. The risk factor
3. The size of the matrices

The scale of the bitmaps used in our program are scaled to 100x100, 
thus the only sensible size of the matrices is a 100. Write '100' as the 
program understands the matrices as quadratic. The program should 
still run given a matrix size of less than 100, as long as your start 
and end positions are within the valid borders of a reduced matrix size.
The start and end positions can be chosen from the main.c file.

### Unused Code
Within the different C files there exists code and 
functions not used by our program. Examples of this 
includes 'relate_mineslope' from the RelationshipMethods folder, 
or the additional user settings showcased but commented out 
in the userPreferences files within the User Preferences folder.

In a finalized version of our software, these settings ought to 
be included for a more accurate and customizable determining of 
the optimal route.

### Python visualization
The optimal route can be visualized by running the CreateVisualization.py 
function from the Visualization folder. In order run the script, 
a valid python interpreter must be installed and setup correctly. If Python
is installed on your machine, you should be prompted with a setup notification
when viewing the Python script in Clion. 