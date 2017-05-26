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
<b>Implementation</b>: Iterate the price from 0 to the sum of all prices (maximum posible price). The goal is to find for each price <img style="margin-bottom: 0px;" src="rucksack-algo/assets/images/alpha.gif"></img>, the smallest posible weight <img style="margin-bottom: -4px;" src="rucksack-algo/assets/images/fi_alpha.gif"></img> using the weights 1.. i. To achive that each <img style="margin-bottom: -4px;" src="rucksack-algo/assets/images/fi_alpha.gif"></img> must be saved into a table for a later lookup of since <img style="margin-bottom: -4px;" src="rucksack-algo/assets/images/fi_formel.gif"></img>.<br>
For a very simple example with four items: (1€, 2kg), (2€, 3kg), (3€, 4kg), (2€, 6kg) and a maximum of 10kg, this is the resulting table:
<img style="display: block;margin-top:5px;margin-bottom:5px;" src="rucksack-algo/assets/images/example_table.png"></img>
The left column is the price <img style="margin-bottom: 0px;" src="rucksack-algo/assets/images/alpha.gif"></img> = 0.. 7€, the following 4 columns are <img style="margin-bottom: -4px;" src="rucksack-algo/assets/images/fi_alpha.gif"></img> with i = 0.. 3. The table shows that the result is 6€ with 9kg since it is reaches the highest price while being <= 10kg. 

## How to use the programm
On programm start two parameters must be provided. 1.) the file name with the data for the specific Rucksackproblem. 2.) the speedup <i>k</i> for the PTAS algorithm. You can chose from the three existing files: test.txt, test_2.txt, greedy_bad.txt or create your own file. The format is like that:<br>
<i>Line 1: </i>MAX_WEIGHT<br>
<i>Line 2: </i>WEIGHT_1 WEIGHT_2 WEIGHT_3<br>
<i>Line 3: </i>PRICE_1 PRICE_2 PRICE_3<br>
e.g.:<br>
<i>Line 1: </i>10<br>
<i>Line 2: </i>3 5 7<br>
<i>Line 3: </i>2 1 4<br>
<br><br>