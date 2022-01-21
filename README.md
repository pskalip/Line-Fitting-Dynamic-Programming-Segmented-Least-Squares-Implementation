
# Dynamic Programming: Segmented Least Squares

The following is the list of team members:

1.	Pranav V Grandhi
2.	Rahul R Shevade
3.	Vamshi Kasam
4.	Shanmukh Kali Prasad

## How To Run

1) Navigate to the source file directory.
2) _Note: The test case in consideration has to be in the same directory as the C++ source code files._
3) Compile the source file using the command:  **g++ sourcecode.cpp**
4) Execute the file and input the file names for input and output files respectively.
5) To visualize the test cases and corresponding outputs, make the necessary changes in the Visualization Jupyter Notebook.
6) For a more convenient web view of the report and analysis, dowload the entire folder and open the DAA2.html file in a browser of your choice.

## Introduction:

The problem statement is- given a set of points, find a sequence of lines that minimises a function f(x), where f(x) = E + cL and-
	E= sum of squared errors in each segment
	L= the number of lines in the sequence
	c= Penalty for using each line segment
This approach helps us solve a multi-objective problem of accuracy and parsimony with a single function.

## Approach to the Problem:

Let OPT(j) denote the minimum cost for points p1, p2, …, pj. Let e(i, j) denote the minimum squared error for points pi, pi+1, …, pj. The crucial observation is that the last point pj for some subproblem OPT(j) belongs to a single segment in the optimal partition, and that segment begins at some earlier point pi. Thus, if we knew OPT(i-1), we could compute OPT(j). This leads to the following recursion:
	
			OPT(j) = min1 ≤ i ≤ j(e(i,j) + C + OPT[i-1])

## Discussion:

Generally seen in the linear regression problem, the best fit line is obtained through a series of derivatives finally resulting in a slope intercept form where -

	a (slope) = Σ( xi – X)*Σ(yi-Y)/Σ((xi-X)^2)
	b (y-intercept) = Y – aX
					where X and Y are means of x and y respectively.
 
This is a problem approached with dynamic programming. While the earlier approach suggests a time complexity of O(n^3), pre-computing the summations of the terms of the error i.e Σ(y^2), Σ(xy), Σ(x^2) etc, reduces the complexity significantly to O(n^2) (our implementation does this). Space complexity of the algorithm is O(n^2) due to the error matrix.

The algorithm is prevented from using too many line segments to fit the data points with the help of the penalty term, ‘C’- which increases the total error.  
Issues in coding-

As mentioned earlier, decreasing the time complexity required the making of an array to store all the precomputed values (prefix sums).  We have implemented using the C++ language. The STL library was used to implement many structures. Visualization for large test cases is not very feasible as plotting greater than 500 points fills the whole plot completely. As the test cases get larger, the comprehensibility of the segments decreases rapidly. Henceforth, we checked the correctness of the algorithm for small cases, while visualizing them. Since visualization libraries are easier to use in python, the visualization was implemented in python.

## Analysis Based on Penalty Values

As the penalty value increases, we observe an increase in the error. The number of lines are directly proportional to the penalty value because, penalty value is the cost of adding a new line. When the penalty is zero, the optimal solution is formed by the points themselves i.e each point is a line. As the penalty increases, the number of lines tend towards one.

## Time Taken

input1.txt – 0.000681s\
input2.txt – 0.000479s\
input3.txt – 0.000486s\
input4.txt – 0.000595s\
input5.txt – 0.000817s\
input6.txt – 0.002044s\
input7.txt – 0.001115s\
input8.txt – 0.000864s\
input9.txt – 0.001931s\
input10.txt – 0.002296s\
input11.txt – 0.128989s\
input12.txt – 0.052519s\
input13.txt – 0.105718s

## Memory Taken

input1.txt – 0.859375 kB\
input2.txt – 0.859375 kB\
input3.txt – 0.859375 kB\
input4.txt – 3.28125 kB\
input5.txt – 3.28125 kB\
input6.txt – 19.92188 kB\
input7.txt – 19.92188 kB\
input8.txt – 19.92188 kB\
input9.txt – 78.90625 kB\
input10.txt – 7820.313 kB\
input11.txt – 7820.313 kB\
input12.txt – 7820.313 kB\
input13.txt – 7820.313 kB\
input14.txt – 9.84375 kB


