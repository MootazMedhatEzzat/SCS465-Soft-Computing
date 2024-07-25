# SCS465-Soft-Computing
---

<div align="center">
  <table width="100%">
    <tr>
      <td colspan="2" align="center"><strong>{ Assignment 4: Regression Using a Neural Network }</strong></td>
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

## Assignment 4

Cairo University  
Faculty of Computers and Artificial Intelligence  
Soft Computing Course (Spring 2024) 

### Assignment 4: Regression Using a Neural Network

---

### About the Problem

Regression is a supervised learning problem that aims at estimating the relationships
between a dependent variable (target) and one or more independent variables (features).
Artificial neural networks are widely used in regression as they can learn the complex
non-linear relationship between the features and target.

### What You Are Required to Do

Implement a feedforward neural network (from scratch) that predicts the cement 
strength. This FFNN should have 3 layers: input, hidden, and output.
• Use only ONE hidden layer.
• Use Sigmoid activation function for the hidden layer.

<div align="center">
  <img src="https://github.com/user-attachments/assets/b92251ed-bd31-4da4-9a54-032c88ca908c" alt="image">
</div>

You will be given the “concrete_data.xlsx” file which contains 700 records of concrete construction
data.Each record is composed of 5 columns representing the cement, water, superplasticizer, age 
and the target to be predicted which is concrete strength.

### Important Remarks to Help You Solve the Problem

1. You will need to load the data from the file into the appropriate structures. The
features and targets should be in 2 separate arrays because the neural network
only uses the features as its input in the forward propagation step, while the
targets are used as the actual outputs in the backpropagation step. The length of
each of these 2 arrays should be equal to the number of data records. Each entry in 
the features array should also be an array storing the numbers in the first 4 
columns of a record.
2. You may need to normalize the data (optional step to get better results).
3. Split the data into training (75% of the data) and testing (25% of the data) sets.
4. Implement the class “NeuralNetwork”. This class can have any needed attributes
and it must have methods to:
a. set the architecture and hyperparameters of the NN such as number of
neurons in each layer, number of epochs, etc.
b. train the NN for a number of epochs by performing forward and backward
propagation on each training example (each data record in the training
set).
c. predict the target value of a new data if the user chooses to enter new data
record to get the cement strength.You can do this by performing forward
propagation using the final weights. (Note: This method could take a one or 
more training examples)
d. calculate the error of the NN model.
Note: You can implement any classes you want (Layer, Neuron, etc.) to be used by the
“NeuralNetwork” class.

### Assignment Submission Notes

- The team could be from different labs but the same TA.
- The deadline is on Wednesday 20/12 at 11:59 PM.
- Please submit one compressed folder. The folder name should follow this
structure: ID_Major_GROUP.zip (Major should be CS or BIO or SWE)
- Cheating Students will take negative grades and no excuses will be accepted. If 
you have any problems during your submission, contact your TA, but don’t give 
your code to or take the code from your friends
