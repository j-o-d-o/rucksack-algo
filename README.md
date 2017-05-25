# Rucksack Problem

This is an entry for a code competition by <a href="https://www.it-talents.de/foerderung/code-competition/code-competition-05-2017">it-talents.de</a>. The task was to write some sort of implementation solving the <a href="https://en.wikipedia.org/wiki/Knapsack_problem">Rucksack Problem</a>.

A lot of algorithms have been found to solve this Problem by now. I decided to implement 3 different versions. A blunt Brutforce Algorithm, a Greedy Algorithm and a PTAS Algorithm, which can also be a FPTAS if the input is set acordingly. 

## Brut Force
With <i>n</i> objects that can be chosen to be put inside the rucksack there are <img src="rucksack-algo/assets/images/pow2n.png"></img>. To get every posible combination of objects an index can be iterated from 0 to <img src="rucksack-algo/assets/images/pow2n.png"></img>. In binary expression each bit of the number is mapped to an object. If it is <i>1</i> it is packed inside the rucksack, for <i>0</i> it will be left out.<br>
This algorithm will always return the correct result, but with a polonomyal complexity of <img style="margin-bottom: -3px;" src="rucksack-algo/assets/images/opow2n.png"></img>, the algorithm is not practicable for larger inputs sizes. <br>

## Greedy Algrithm
For each object a ratio of price/weight is created. Then the array of ratios is sorted from large to small. Starting with the objects of high value the objects are put into the rucksack until no more objects fit into the rucksack. The complexity of this algorithm is <img style="margin-bottom: -5px;" src="rucksack-algo/assets/images/olognn.png"></img> (depending on the sorting algorithm used). This makes it very fast. The downside is, for an uperbound rucksackproblem where objects can not be cut down, this algorithm can get arbitrary bad results. <br>
Example: max input = 300kg, input items (price, weight) : [(1€, 1kg), (299€, 300kg)]<br> The greedy algorithm will put the first item into the rucksack as the ratio 1/1=1 is greater than 299/300=0.99. Thus the second object will not fit anymore and the algorithm far off the optimum. <br>

## PTAS (Polynomial-time approximation scheme)
A PTAS is a type of approximation algorithm for optimzation problems. It is polynomial in n but not necessarily in its input length. For the implemented PTAS the complexity is <img style="margin-bottom: -3px;" src="rucksack-algo/assets/images/CodeCogsEqn.gif"></img>, which seems to be polynomial on first sight, but is not polyomial in its input length (max price). This is also called pseudo polynomial. <br>
The algorithm can be speed up by a faktor of <i>k</i> with a resulting relativ error of   <img style="margin-left: 4px;margin-bottom: -4px;" src="rucksack-algo/assets/images/CodeCogsEqn2.gif"></img>. If for a specific relativ error the k is calculated and used, a FPTAS can be created which is also polynomial in its input with the complexity <img style="margin-bottom: -4px;" src="rucksack-algo/assets/images/CodeCogsEqn3.gif"></img><br>
<b>Implementation</b>: Iterate the price from 0 to the sum of all prices (maximum posible price). For each price look for the smallest posible capacity to reach the value of that price and save that result into a table. When interating through the items, look if it is better to use 
