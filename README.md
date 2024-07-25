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

Regression is a supervised learning problem that aims at estimating the relationships between a dependent variable (target) and one or more independent variables (features). Artificial neural networks are widely used in regression as they can learn the complex non-linear relationship between the features and target.

### What You Are Required to Do

Implement a feedforward neural network (from scratch) that predicts the cement strength. This FFNN should have 3 layers: input, hidden, and output.

- Use only ONE hidden layer.
- Use the Sigmoid activation function for the hidden layer.

<div align="center">
  <img src="https://github.com/user-attachments/assets/b92251ed-bd31-4da4-9a54-032c88ca908c" alt="Neural Network Diagram">
</div>

You will be given the `concrete_data.xlsx` file which contains 700 records of concrete construction data. Each record is composed of 5 columns representing the cement, water, superplasticizer, age, and the target to be predicted, which is concrete strength.

### Important Remarks to Help You Solve the Problem

1. **Data Loading**: Load the data from the file into appropriate structures. The features and targets should be in two separate arrays because the neural network only uses the features as its input in the forward propagation step, while the targets are used as the actual outputs in the backpropagation step. The length of each of these arrays should be equal to the number of data records. Each entry in the features array should also be an array storing the numbers in the first four columns of a record.
   
2. **Data Normalization**: (Optional) Normalize the data to potentially achieve better results.

3. **Data Splitting**: Split the data into training `(75% of the data)` and testing `(25% of the data)` sets.

4. **Neural Network Implementation**: Implement the class `NeuralNetwork` with any necessary attributes. The class must have methods to:
   - **Set Architecture and Hyperparameters**: Configure the architecture and hyperparameters of the NN, such as the number of neurons in each layer, number of epochs, etc.
   - **Training**: Train the NN for a number of epochs by performing forward and backward propagation on each training example (each data record in the training set).
   - **Prediction**: Predict the target value of new data if the user chooses to enter a new data record to get the cement strength. This can be done by performing forward propagation using the final weights. (Note: This method could take one or more training examples)
   - **Error Calculation**: Calculate the error of the NN model.

Note: You can implement any additional classes you need (e.g., `Layer`, `Neuron`) to be used by the `NeuralNetwork` class.

### Assignment Submission Notes

- The deadline is on Wednesday, 20/12 at 11:59 PM.
- Please submit one compressed folder. The folder name should follow this structure: `ID_Major_GROUP.zip` (Major should be CS, BIO, or SWE).
- Cheating students will receive negative grades, and no excuses will be accepted. If you encounter any problems during your submission, contact your TA, but do not share your code with or take the code from your friends.
