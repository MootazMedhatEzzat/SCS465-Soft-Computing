Based on the uploaded PDF, here's the completed README.md for the SCS465-Soft-Computing Assignment 3:

# SCS465-Soft-Computing
---

<div align="center">
  <table width="100%">
    <tr>
      <td colspan="2" align="center"><strong>{ Assignment 3: Fuzzy Logic Toolbox }</strong></td>
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

## Assignment 3

Cairo University  
Faculty of Computers and Artificial Intelligence  
Soft Computing Course (Spring 2024) 

### Assignment 3: Fuzzy Logic Toolbox

---

### About the Problem

A “Fuzzy Logic Toolbox” provides functions and apps for designing and simulating fuzzy logic systems. It lets the user specify and configure input variables, output variables, membership functions, rules, and defuzzification methods. An example of such a toolbox is MATLAB’s Fuzzy Logic Toolbox™.

### What You Are Required to Do

Build a simple fuzzy logic toolbox and test it on a well-known problem. In this fuzzy logic toolbox, the user can:

1. Define a new fuzzy logic system.
2. Define the system’s variables.
3. Define each variable’s range and fuzzy sets.
4. Define the input variables’ crisp values.
5. Define the rules.
6. Get the predicted output.

### Example

```
Fuzzy Logic Toolbox
===================

1- Create a new fuzzy system
2- Quit

1

Enter the system’s name and a brief description:

Project Risk Estimation

The problem is to estimate the risk level of a project based on the project funding and the technical experience of the project’s team members.

Main Menu:
==========

1- Add variables.
2- Add fuzzy sets to an existing variable.
3- Add rules.
4- Run the simulation on crisp values.

1

Enter the variable’s name, type (IN/OUT) and range ([lower, upper]):
(Press x to finish)

proj_funding IN [0, 100]
exp_level IN [0, 60]
risk OUT [0, 100]
x

Main Menu:
==========

1- Add variables.
2- Add fuzzy sets to an existing variable.
3- Add rules.
4- Run the simulation on crisp values.

4

CAN’T START THE SIMULATION! Please add the fuzzy sets and rules first.

Main Menu:
==========

1- Add variables.
2- Add fuzzy sets to an existing variable.
3- Add rules.
4- Run the simulation on crisp values.

2

Enter the variable’s name:

exp_level

Enter the fuzzy set name, type (TRI/TRAP) and values: (Press x to finish)

beginner TRI 0 15 30
intermediate TRI 15 30 45
expert TRI 30 60 60
x

Main Menu:
==========

1- Add variables.
2- Add fuzzy sets to an existing variable.
3- Add rules.
4- Run the simulation on crisp values.

2

Enter the variable’s name:

proj_funding

Enter the fuzzy set name, type (TRI/TRAP) and values: (Press x to finish)

very_low TRAP 0 0 10 30
low TRAP 10 30 40 60
medium TRAP 40 60 70 90
high TRAP 70 90 100 100
x

Main Menu:
==========

1- Add variables.
2- Add fuzzy sets to an existing variable.
3- Add rules.
4- Run the simulation on crisp values.

2

Enter the variable’s name:

risk

Enter the fuzzy set name, type (TRI/TRAP) and values: (Press x to finish)

low TRI 0 25 50
normal TRI 25 50 75
high TRI 50 100 100
x

Main Menu:
==========

1- Add variables.
2- Add fuzzy sets to an existing variable.
3- Add rules.
4- Run the simulation on crisp values.

3

Enter the rules in this format: (Press x to finish)
IN_variable set operator IN_variable set => OUT_variable set

proj_funding high or exp_level expert => risk low
proj_funding medium and exp_level intermediate => risk normal
proj_funding medium and exp_level beginner => risk normal
proj_funding low and exp_level beginner => risk high
proj_funding very_low and_not exp_level expert => risk high
x

Main Menu:
==========

1- Add variables.
2- Add fuzzy sets to an existing variable.
3- Add rules.
4- Run the simulation on crisp values.

4

Enter the crisp values:

proj_funding: 50
exp_level: 40

Running the simulation…
Fuzzification => done
Inference => done
Defuzzification => done

The predicted risk is normal (37.5)

Main Menu:
==========

Close

Fuzzy Logic Toolbox
===================

1- Create a new fuzzy system
2- Quit

2
```

### Important Remarks to Help You Solve the Problem

1. Create the appropriate classes and data structures to store the system’s data.
2. The expected fuzzy set shapes are either triangular or trapezoidal.
3. In the “run simulation” step, perform fuzzification, inference, and defuzzification using the weighted average method.
4. Show error messages if there is missing input or if the user enters invalid input.
5. Test your program on the example in the lab.

### Assignment Submission Notes

- The deadline is on Friday, 8/12 at 11:59 pm. No late submissions are allowed.
- Submit one compressed folder named in the following structure: ID_MAJOR_GROUP.zip.
- Cheating students will get negative grades. No excuses will be accepted. If you have any problems during submission, contact your TA. Do not share or take code from your friends.

Good luck!
