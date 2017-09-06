This program calculated statistical probability using T tests. Specifically a one sample T test and a paired T test. Before running the programs they must be compiled using the included Makefile. Instructions on how to run each program can be found below.

One Sample T Test:
--------------------------------------------------------------------------------
To run the one sample T test enter the data set into the  oneSampleInput.txt file. On each line there should be a single integer, positive or negative. 
Example:
11300
9890
10400
9900
10545
12334

Then execute the program with the expected value as the first argument.
Example:
./obj64/oneSampleTtest 10000

The output should look something like this.
Expected value: 10000

Input dataset:
11300
9890
10400
9900
10545
12334

 Results: 
Mean: 10728.166667
Standard Deviation: 941.840645
T_Value: 1.895036


Paired T Test:
--------------------------------------------------------------------------------
To run the paired T test first enter the sample data into the pairedInput.txt file. Each line should have two integers, positive or negative, separated by a comma.
Example:
11300, 11400
9890, 9800
10400, 11345
9900, 9739
10545, 10787
12334, 12555

Then execute the program.
Example: 
./obj64/pairedTtest

The output should look something like this.
Input dataset:
11300, 11400
9890, 9800
10400, 11345
9900, 9739
10545, 10787
12334, 12555

Results: 
Mean Difference: -209.500000
Standard Deviation 395.248782
Standard Error: 161.359640
T_Value: 1.298342