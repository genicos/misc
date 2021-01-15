Intended for a Windows 10 environment
Written by Nicolas Ayala

For it to work:
	-Ensure that "Gradient_Decent.jar", Networks folder, and MNIST folder are in the same directory

First thing to check out:
	-Run "Gradient_Decent.jar" (double-click)
	-Click on "View old neural network"
	-Select "Softmax, No hidden layer (untrained)"
	-Click "Choose File"
	-Adjust Step size to ~0.5
	-Adjust Sample size to ~100
	-Click "Randomize Parameters[R]"
	-Click "Learn[U]", the network is now training on the dataset
	-Observe the falling cost in the console and on the graph on the top right(the purpose of training is to minimize cost)
	-Once cost is reasonably below 0.3, Click "Learn[U]" again to stop training
	-Click "Test[T]", this will test the network on 10,000 samples it had not trained on
	-Press "Sample[C]" many times to see how it classifies some digits

How it works:
	For a given training example, the network attempts to classify it. The outputs of the network are then compared
to the ground truth(what they are supposed to equal) and a partial derivative of the cost function in terms of each output node
is calculated. Then, using the chain rule, the partial derivatives of the cost function in terms of the weights and nodes of the previous layer
are calculated. Finally, this process (Back Propagation) is recursively repeated for each subsequent layer.

TIPS:
(safe means that the network changes less between iterations of learning,
	this allows it to converge more precisely to a local minimum, but less likely to escape that local minimum)
-The lower the step size, the safer and slower the learning becomes.
-The larger the sample size, the safer and slower the learning becomes.

-The more complex the network architecture, the safer its learning should be.
-The later into the learning process, the safer the learning should be.