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

## Assignment 3: Fuzzy Logic Toolbox

Cairo University  
Faculty of Computers and Artificial Intelligence  
Soft Computing Course (Spring 2024) 

---

### 📉 About the Problem

A “Fuzzy Logic Toolbox” provides functions and apps for designing and simulating fuzzy logic systems. It lets the user specify and configure input variables, output variables, membership functions, rules, and defuzzification methods. An example of such a toolbox is MATLAB’s Fuzzy Logic Toolbox™.

<div align="center">
  <img src="https://github.com/user-attachments/assets/03fba8ca-d367-42cb-92a5-32acf253e352" alt="image">
</div>

### 📝 What You Are Required to Do

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

### 🔑 Important Remarks

1. 🛠️ **Create the appropriate classes and data structures** to store the system’s data.
2. The expected **fuzzy set shapes** are either **triangular** or **trapezoidal**.
3. In the **"run simulation"** step:
   - Perform **fuzzification** 🌀
   - Conduct **inference** 🔄
   - Complete **defuzzification** using the **weighted average method** ⚖️.
4. ❗ Show **error messages** if there is:
   - Missing input 🔍
   - Invalid input ❌
5. 🧪 **Test** your program using the **example provided in the lab**.

### 📤 Assignment Submission Instructions

- 📅 The **deadline** is on Friday, 8/12 at 11:59 pm. No late submissions are allowed.
- 📂 Submit one compressed folder named in the following structure: **ID_MAJOR_GROUP.zip**.
- ❌ Cheating students will get negative grades. No excuses will be accepted. If you have any problems during submission, contact your TA. **Do no**t share or take code from your friends.

### 🛠️ Programming Language and Development Tools Used

<table align="center" border="1" cellpadding="10">
  <thead>
    <tr>
      <th>Programming Language</th>
      <th>Development Tool</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td align="center">
        <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" title="C++" alt="C++" width="40" height="40"/>
      </td>
      <td align="center">
        <img src="https://github.com/user-attachments/assets/1db36f07-698f-400f-bdd7-b3ad8f936f5d" title="Code::Blocks" alt="Code::Blocks" width="40" height="40"/>
      </td>
    </tr>
    <tr>
      <td align="center">
        C++
      </td>
      <td align="center">
        Code::Blocks IDE
      </td>
    </tr>
  </tbody>
</table>

---

## 💬 Let's Connect
Feel free to reach out to me if you'd like to collaborate on a project or discuss technology! As a Software Engineer, I'm always open to tackling new challenges, sharing knowledge, and growing through collaborative opportunities.

**Mootaz Medhat Ezzat Abdelwahab**  
🎓 Software Engineering Graduate | Faculty of Computers and Artificial Intelligence, Cairo University  

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/mootaz-medhat-ezzat-abdelwahab-377a60244)
