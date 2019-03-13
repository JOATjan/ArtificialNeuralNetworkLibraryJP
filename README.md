## About the project

During summer I have spent some time writing a library capable of building, training, and evaluating artificial neural networks in C#.
Thanks to my great patron, Bartłomiej Hebda, a great, skilled developer, I have managed to do so, and with good results. I've gained a quite good understanding of machine learning mechanisms inside neural networks.
When I thought about my own project, an obvious way to go was writing the same library again, but in a different language. I haven't written anything bigger in C++ before, and wanted to learn something new.
And here You can see the results.

If I did something wrong, any tips will be very appreciated.
If anyone wants to see the project files to compile the library, please contact me and I will gladly send You compressed project files.

## Future plans
- Adding input data dimensions check and error handling
- Adding more activation functions
- Optimizing backprop and ff algorithms

## Usage of the library

# Initializing Neural Net components:
- First, you will need a net instance and activation functions that you'd like to use in the training process.

```cpp
  	NeuralNet *Net = new NeuralNet;
	ReLu *reLu = new ReLu;
	Sigmoid *sigmoid = new Sigmoid;
```

- Next, you want to fill our net with some layers: in this case, initialize 3 layers, with 8,6 and 1 neurons, add them to the Net, and connect them.

```cpp
  	Layer *InputLayer = new Layer(8,reLu);
	Layer *HiddenLayer = new Layer(6, sigmoid);
	Layer *OutputLayer = new Layer(1, sigmoid);
	Net->AddLayer(InputLayer);
	Net->AddLayer(HiddenLayer);
	Net->AddLayer(OutputLayer);
	Net->ConnectLayers();
```

- Load the data to our data set (in this case I have prepared class that loads the data from HIV protease cleavage data set) and initialize our coach: he will train the network. Then we simply train the net with coach.Train(). The last three parameters are: number of epochs, learning rate and net's error margin.

```cpp
  	HIVDataSet *dataSet = new HIVDataSet(0.8);
	dataSet->LoadData();
	Coach coach;
	coach.Train(Net, dataSet->GetTrainingInputs(), dataSet->GetTrainingOutputs(), 1000, 0.06, 0.4);
```

## Example results
I have managed to get about 90% accuracy after 100 epochs training with 3 layers (sigmoid layers) in HIV protease cleavage dataset classification problem.
