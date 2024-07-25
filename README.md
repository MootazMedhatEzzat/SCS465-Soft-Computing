# SCS465-Soft-Computing
---

<div align="center">
  <table width="100%">
    <tr>
      <td colspan="2" align="center"><strong>{ Assignment 2: Smooth Curve Fitting Problem }</strong></td>
    </tr>
    <tr>
      <td align="left"><strong>Name</strong>: Mootaz Medhat Ezzat Abdelwahab</td>
      <td align="right"><strong>Id</strong>: 20206074</td>
    </tr>
    <tr>
      <td align="left"><strong>Program</strong>: Software Engineering</td>
      <td align="right"><strong>Group</strong>: B (S4)</td>
    </tr>
    <tr>
      <td align="center" colspan="2"><strong>Delivered To:</strong><br>DR. Sabah Sayed<br>TA. Norhan Sweed</td>
    </tr>
  </table>
</div>

---

## Assignment 2

Cairo University  
Faculty of Computers and Artificial Intelligence  
Soft Computing Course (Spring 2024) 

### Assignment 2: Smooth Curve Fitting Problem

<div align="center">
  <img src="https://github.com/user-attachments/assets/182f2dd1-c856-4004-aff1-07329213c618" alt="image">
</div>

---

### About the Problem

Curve fitting is the process of constructing a curve, or mathematical function (polynomial equation), that best fits a series of data points, possibly subject to constraints. In smooth curve fitting, the function is constructed to approximately fit the data. Given a set of points, the goal is to fit a curve to them using a polynomial equation.

### What You Are Required to Do

Write a genetic algorithm to find the best coefficients that minimize the distance between the polynomial function and the points. A solved example is provided in lab (Floating point genetic algorithms).

### Input Format

You’ll be given an input file with the following format:

- First line: Number of datasets (must be at least 1)

For each dataset:
- Number of data points and polynomial degree separated by space

For each point:
- x-coordinate and y-coordinate separated by space

Example:

```
1  
4 2 
1 5 
2 8 
3 13 
4 20
```

Note: In the example above, we have 1 dataset containing 4 points and we want to fit a 2nd degree polynomial (a0, a1, a2).

### Important Remarks

1. Think about how you will encode the solution in your chromosome and what the objective function will be.
2. Use a floating-point representation of the chromosome.
3. Try different population sizes to see how this affects your results. The maximum number of generations is up to you.
4. Initialize the genes such that their values are in the range [-10,10].
5. Implement tournament selection, 2-point crossover, non-uniform mutation, and elitist replacement.
6. Read the input from the given file and write the output to a file. The output should consist of the dataset index, the coefficients of the polynomial function, and its mean square error.

### Assignment Submission Notes

- You can use any programming language.
- The deadline is on Wednesday, 15/11 at 11:59 pm. No late submissions are allowed.
- Submit one compressed folder named in the following structure: ID_MAJOR_GROUP.
- Cheating students will receive negative grades. Contact your TA if you have any problems during submission. Do not, under any circumstances, share or take code from your friends.

### Grading Criteria (5 marks)

- Representation and initialization: 0.5
- Fitness function: 1
- Selection: 0.75
- Crossover: 0.75
- Mutation: 0.5
- Replacement: 0.5
- Output: 1

Good luck!
