import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
# used only to remove tensorflow logs

import tensorflow as tf
encode_onehot = tf.keras.utils.to_categorical
Sequential = tf.keras.models.Sequential
layers = tf.keras.layers
Input, Conv2D, MaxPooling2D, Flatten, Dense = layers.Input, layers.Conv2D, layers.MaxPooling2D, layers.Flatten, layers.Dense
# had import issues when importing as like "from tensorflow.keras.models import Sequential", hence used this method.

from sklearn.metrics import classification_report
from matplotlib import pyplot as plt

#Step1. Load and process the MNIST dataset
(xtrain,ytrain),(xtest,ytest) = tf.keras.datasets.mnist.load_data() #xtrain: images for training, xtest: images for test, ytrain: labels for training, ytest: labels for test

xtrain = xtrain.reshape(-1,28,28,1) #-1 automatically calculate dimension size based on remaining dimensions
xtest = xtest.reshape(-1,28,28,1)

xtrain = xtrain.astype('float32')/255.0 #brings the 1B integer value to a float value between 0 and 1
xtest = xtest.astype('float32')/255.0 # Done to normalise pixel values to [0,1]

ytrain = encode_onehot(ytrain,10) #one-hot encodes labels to 10 classes, one for each digit
ytest = encode_onehot(ytest,10)

print()
print("Training data shape: {}, Labels shape: {}".format(xtrain.shape,ytrain.shape))
print("Test data shape: {}, Labels shape: {}".format(xtest.shape,ytest.shape))
print()

#Step2. Build CNN Model
model = Sequential()

model.add(Input(shape=(28,28,1))) #Input layer matching shape of our data
model.add(Conv2D(32, (3, 3), activation='relu')) #ReLU : Rectified Linear Unit : max(x,0)
model.add(MaxPooling2D((2, 2)))
model.add(Conv2D(64, (3, 3), activation='relu'))
model.add(MaxPooling2D((2, 2)))
model.add(Flatten())
model.add(Dense(64, activation='relu'))
model.add(Dense(10, activation='softmax')) #signmoid would work better if it was a binary classification, plus the sum of probabilities in softmax is equal to 1, which avoids conflicts and makes sense

model.summary()

#Step3. Compile the model
model.compile(optimizer='adam',
              loss='categorical_crossentropy',
              metrics=['accuracy'])

#Step4. Train the model
print("\nTraining")
history = model.fit(xtrain, ytrain, 
                    epochs=10, 
                    batch_size=32, 
                    validation_split=0.2)

#Step5. Evaluate the model

test_loss, test_accuracy = model.evaluate(xtest, ytest) # calculation of loss and accuracy of model on test set
print()
print("Test Loss: {}".format("%.4f"%test_loss))
print("Test Accuracy: {}".format("%.4f" %test_accuracy))
print()

ypred = model.predict(xtest) # runs the test images through model and predicts probabilities
ypred_classes = ypred.argmax(axis=1) # argmax(axis=1) returns index of highest probability along axis 1 (rows)
ytrue = ytest.argmax(axis=1)

# ypred_classes -> class labels from probabilities
# ytrue -> class labels from one-hot

report = classification_report(ytrue, ypred_classes)

print(report)

#Step6. Visualising Test results

# Plot on Accuracy
plt.figure(figsize=(12,5))
plt.plot(history.history['accuracy'], label='Training Accuracy')
plt.plot(history.history['val_accuracy'], label='Validation Accuracy')
plt.title("Training and Validation Accuracy")
plt.xlabel("Epoch")
plt.ylabel("Accuracy")
plt.legend()
plt.show()

# Plot on Loss
plt.figure(figsize=(12,5))
plt.plot(history.history['loss'], label='Training Loss')
plt.plot(history.history['val_loss'], label='Validation Loss')
plt.title("Training and Validation Loss")
plt.xlabel("Epoch")
plt.ylabel("Loss")
plt.legend()
plt.show()