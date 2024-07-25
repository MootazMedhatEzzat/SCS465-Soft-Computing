# SCS465-Soft-Computing
---

<div align="center">
  <table width="100%">
    <tr>
      <td colspan="2" align="center"><strong>{ Assignment 1: Knapsack Problem }</strong></td>
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

## Assignment 1

Cairo University  
Faculty of Computers and Artificial Intelligence  
Soft Computing Course (Spring 2024) 

### Assignment 1: Knapsack Problem

<div align="center">
  <img src="https://github.com/user-attachments/assets/5f9fc849-4fc5-4e2b-b3b5-b45fbfea1279" alt="image">
</div>

---

### About the Problem

The knapsack problem is a well-known optimization problem. Given a knapsack that can carry weights up to a certain amount and a number of items, each item having a weight and a value, the goal is to select the items to carry in the knapsack to maximize the total value.

### What You Are Required to Do

Write a genetic algorithm to solve the knapsack problem. A solved example is provided in lab 1.

### Input Format

You’ll be given an input file with the following format:

- First line: Number of test cases (must be at least 1)

For each test case:
- Size of the knapsack
- Number of items

For each item:
- Weight and value separated by space

Example:

```
2 
10 
3 
4 4 
6 6 
5 3 

15 
5 
12 4 
1 2 
4 10 
1 1 
2 2
```

### Important Remarks to Help You Solve the Problem

1. Use a binary, one-dimensional chromosome.
2. The population size and initialization method are up to you. Try different population sizes to see how this affects your results. The maximum number of generations is also up to you.
3. Handle infeasible solutions (solutions that violate the constraints of the problem) appropriately.
4. Use rank selection and one-point crossover. Choose the mutation and replacement methods that you find appropriate.
5. The output should consist of the test case index, the number of selected items, the total value, the total weight, and the weight and value of each selected item.

### Assignment Submission Notes

- You can use any programming language.
- The deadline is on Wednesday, 8/11 at 11:59 pm. No late submissions are allowed.
- Submit one compressed folder named in the following structure: ID_MAJOR_GROUP.
- Cheating students will receive negative grades. Contact your TA if you have any problems during submission. Do not, under any circumstances, share or take code from your friends.

### Grading Criteria (5 marks)

- Representation, structure, and initialization: 0.5
- Fitness function: 0.5
- Handling infeasible solutions: 0.5
- Selection, crossover, mutation, and replacement: 3
- Output: 0.5

Good luck!
