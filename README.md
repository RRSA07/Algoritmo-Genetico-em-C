# Algoritmo Genetico em C
Power coupling between different size waveguides have been successfully and efficiently optimized by using an evolutionary algortithm based on the artificial immune system in conjunction with the finite element method.

The proposed AIS algorithm has the following stages: 

a) Initialization: 

The initial population is randomly generated and each individual is represented as a binary sequence and the size in both algorithms was the same number of
antibodies; 

b) Selection: 

50% of the individuals are selected for cloning and their probability to be selected is proportional to its fitness, the Rank selection, has been considered; 

c) Cloning: 

Selected, the individuals are cloned to have again the same size of the initial population; 

d) Mutation: 

It has been varied the mutation rate of 1-5%; 

e)Affinity: 

The individuals resulting from the mutation are evaluated by an affinity (similarity) measured by the Hamming distance, selecting individuals with similar characteristics to the best individual of the population generated at that time; 

f) Elitism and Suppression: 

It is of great importance that the best antibody remains in the next generation to avoid a possible reduction of the fitness of its new antibody affecting the process of convergence. The two worst antibodies of the actual generation are substituted by two best of the previous generation; 

g) Updating:

Actualization of the next generation of antibodiess; 

h) Ending: 

We consider 200 generations as stop criterion in all cases.
