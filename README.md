# SimulationCovid
This is my attempt to model and simulate the spread of Covid-19.

![alt text](https://github.com/djeada/SimulationCovid/blob/master/CovidSimulation/img/Capture.PNG)

<h1>What does the simulation represent?</h1>
Squares in the simulation represent individual people.
Their colors represent their health.
<li>Green for healthy.</li>
<li>Red for infected.</li>
<li>Black for dead.</li>

</br>
The numbers are scaled, since showing millions of squares is not possible. 
Their ratios however are initially the same, as in the country of your choice.
You can choose the country in the <i>main</i> file.

<h1>Initial Conditions</h1>
<li>Number of cases in your country.</li>
<li>Number of people that passed away because of Covid-19 in your country.</li>
<li>Total population of your country</li>

</br>
Initial conditions are taken from two files:

<i>4.14.2020.2020</i>
Source: https://data.europa.eu/euodp/pl/data/dataset/covid-19-coronavirus-data

<i>population</i>
Source:https://data.worldbank.org/indicator/sp.pop.totl

We are currently working on making them update themselves automatically.

<h1>Progress of the disease</h1>
Each person has a stage of disease associated with them.
<li>healthy</li>
<li>infected</li>
<li>dead</li>

</br>
Each person has a life counter associated with them.
We assume that healthy people never die.
We assume that progress of the disease will take the same number of iterations for everyone.
If the life counter for infected person reaches zero, there are two options:
1. They survived the disease and their state is changed to healthy.
2. They didn't survive the disease and their state is changed to dead.

How is this decided?
There is 80% of chance that they will survive. 
Source: https://www.worldometers.info/coronavirus/

We also keep track of the total number of cases. 
There is a possibility that the health system in a given country collapses.
It happens when the total number of cases is greater than the maximum capacity of the health system.
If the health system collapsed chances of survival decrease.
You can set your countries health system capacity in the <i>simulation</i> file.

<h1>How are people getting infected?</h1>
If two or more people are at the same time within a range define in the <i>person</i> file
and at least one of them is infected then there is a possibility that others will get infected as well.
There are contradictory theories on how the virus spreads, so we decided that there is always a chance
of getting infected when meeting infected person, but not hundred percent.
You can set your countries health system capacity in the <i>simulation</i> file.

<h1>Cooperativeness of the people</h1>
Not everyone stays in quarantine.
Every person has boolean field called cooperativeness associated with them.

Cooperative people rarely live their homes and don't go far.

<h1>Statistics</h1>
We keep track of the following statistics.
<li>Total number of cases.</li>
<li>Total number of deaths.</li>
