from math import exp

def sigmoid(x):
    return 1/(1+exp(-x))

def der_sigmoid(x):
    return x*(1-x) # Let's S(x) = 1/(1+exp(-x)), so S'(x) = exp(-x)/(1+exp(-x))^2 = (1+exp(x)-1)/(1+exp(x))^2 = 1/(1+exp(x)) - 1/(1+exp(x))^2 = S(x) - S^2(x) = S(x)(1-S(x))

samples = [
    [0.6, 0.1],
    [0.2, 0.3]
] # inputs

labels = [
    [1,0],
    [0,1]
] # perfect output (our outputs will be equal to them at 0% error)

lvl1_wt = [
    [0.1, 0, 0.3],
    [-0.2, 0.2, -0.4]
] # weights from input layer to hidden layer

lvl2_wt = [
    [-0.4, 0.2],
    [0.1, -0.1],
    [0.6, -0.2]
] # weights from hidden layer to output layer

learning_rate = 0.1

for i in range(50000):
    t_error = 0
    outputs = []
    for p in range(len(samples)):
        lvl1_ip = [0,0,0]
        lvl1_op = [0,0,0]
        for j in range(3):
            lvl1_ip[j] = (
                samples[p][0]*lvl1_wt[0][j] +
                samples[p][1]*lvl1_wt[1][j]
            ) # Output of perceptrons from input layer to hidden layer
            lvl1_op[j] = sigmoid(lvl1_ip[j]) # Activation of output at lvl 1
        lvl2_ip = [0,0]
        lvl2_op = [0,0]
        for j in range(2):
            lvl2_ip[j] = (
                lvl1_op[0]*lvl2_wt[0][j] +
                lvl1_op[1]*lvl2_wt[1][j] +
                lvl1_op[2]*lvl2_wt[2][j]
            ) # Output of perceptrons from hidden layer to output layer
            lvl2_op[j] = sigmoid(lvl2_ip[j]) # Activation of output at lvl 2, actual output
        lvl2_error = [
            labels[p][0] - lvl2_op[0],
            labels[p][1] - lvl2_op[1]
        ] # computing error in output received by output layer based on label
        t_error += sum(abs(e) for e in lvl2_error) # Check overall error
        lvl2_delta = [
            lvl2_error[0] * der_sigmoid(lvl2_op[0]),
            lvl2_error[1] * der_sigmoid(lvl2_op[1])
        ] # computing factor for lvl 2 weight updations / lvl 1 error computations
        lvl1_error = [0,0,0]
        lvl1_delta = [0,0,0]
        for j in range(3):
            lvl1_error[j] = (
                lvl2_delta[0]*lvl2_wt[j][0] +
                lvl2_delta[1]*lvl2_wt[j][1]
            ) # computing error in output received by hidden layer based on computed factor
            lvl1_delta[j] = lvl1_error[j]*der_sigmoid(lvl1_op[j]) # computing factor for lvl 1 weight updations
        for j in range(3):
            for k in range(2):
                lvl2_wt[j][k] += learning_rate*lvl1_op[j]*lvl2_delta[k] # updation of lvl 2 weights
        for j in range(2):
            for k in range(3):
                lvl1_wt[j][k] += learning_rate*samples[p][j]*lvl1_delta[k] # updation of lvl 1 weights
        outputs.append(lvl2_op)
    # The above loop to be executed 50000 times
    if i==0 or i==1 or i==49 or i==49999: # Weight values at Iteration 1, 2 and 50
        print("Iteration {}".format(i+1))
        print("Level 1")
        print("W_1->3: {}, W_1->4: {}, W_1->5: {}".format(lvl1_wt[0][0],lvl1_wt[0][1],lvl1_wt[0][2]))
        print("W_2->3: {}, W_2->4: {}, W_2->5: {}".format(lvl1_wt[1][0],lvl1_wt[1][1],lvl1_wt[1][2]))
        print("Level 2")
        print("W_3->6: {}, W_3->7: {}".format(lvl2_wt[0][0],lvl2_wt[0][1]))
        print("W_4->6: {}, W_4->7: {}".format(lvl2_wt[1][0],lvl2_wt[1][1]))
        print("W_5->6: {}, W_5->7: {}".format(lvl2_wt[2][0],lvl2_wt[2][1]))
        print("Error at output: {}".format(t_error))
        print("Outputs: {}".format(outputs))