from math import exp

def sigmoid(x):
    return 1/(1+exp(-x))

def der_sigmoid(x):
    return x*(1-x) # Let's S(x) = 1/(1+exp(-x)), so S'(x) = exp(-x)/(1+exp(-x))^2 = (1+exp(x)-1)/(1+exp(x))^2 = 1/(1+exp(x)) - 1/(1+exp(x))^2 = S(x) - S^2(x) = S(x)(1-S(x))

dataset = [
    [1,0,0,1,1],
    [1,0,0,0,1],
    [0,0,1,1,0],
    [0,1,0,0,0],
    [1,1,0,0,1],
    [0,0,1,1,1],
    [0,0,0,1,0],
    [0,0,1,0,0]
] 
# Our input, for each sample in dataset,
# sample[0]: if patient has loss of smell
# sample[1]: if patient has weight loss
# sample[2]: if patient has runny nose
# sample[3]: if patient suffers from body pain
# sample[4]: RESULT: if patient is tested positive for contracting the virus

weights = [0.1,0.2,0.3,0.4] # Any random weight works
bias = 0.5 # Any random bias works
learning_rate = 0.01 # Lower learning_rate brings more accuracy, but we need more samples and iterations for that

for _ in range(5000):
    for sample in dataset:
        actual = bias # Considered bias beforehand
        for j in range(4):
            actual += weights[j]*sample[j] # Calculate weighted sum
        actual = sigmoid(actual) # Activation
        delta = (sample[4] - actual)*der_sigmoid(actual) #compute delta
        for j in range(4):
            weights[j] += learning_rate*delta*sample[j] # updation of weights
        bias += learning_rate*delta # updation of bias (sample value for bias is always 1)

# The above nested loop runs 5000 times for each sample in dataset

print(weights)

testdata = [
    [1,0,0,1],
    [0,0,1,0],
    [1,0,1,0]
]

for i,test in enumerate(testdata):
    actual = bias # Consider bias already
    for j in range(4):
        actual += weights[j]*test[j] # calculate weighted sum
    actual = sigmoid(actual) # activation
    result = "positive" if actual > 0.5 else "negative" # decide result based on output
    print("Subject {} likely {}, output: {}".format(i+1,result,"%.4f"%actual))
