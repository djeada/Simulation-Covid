# SimulationCovid
This is my attempt to model and simulate the spread of Covid-19.

![alt text](https://github.com/djeada/SimulationCovid/blob/master/CovidSimulation/img/Capture.PNG)

<h1>What does the simulation represent?</h1>
Individual people are represented by squares in the simulation.
Their health is represented by their colors.
<li>Green for healthy.</li>
<li>Red for infected.</li>
<li>Black for dead.</li>

</br>
Since it's impossible to display millions of squares, the numbers are scaled.
However, their initial ratios are the same as in the nation of your choosing.
The country can be selected in the <i>main</i> file.

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

Making them update themselves automatically  is on our TODO list.

<h1>Progress of the disease</h1>
Each individual has a disease stage assigned to them.
<li>healthy</li>
<li>infected</li>
<li>dead</li>

</br>
A life counter is assigned to each person.
We take it for granted that healthy people will never die.
We presume that everyone will go through the same number of iterations as the disease progresses.
If the infected person's life counter approaches zero, there are two options:
1. They have recovered from the illness and are now in a stable state.
2. They died as a result of the illness, and their status has been changed to that of a deceased person.

<h3r>How is this decided?</h3>
There is 80% of chance that they will survive. 
Source: https://www.worldometers.info/coronavirus/

We also keep track of how many cases there are in total.
There is a chance that a country's health-care system could fail.
It occurs when the total number of cases exceeds the health system's full capability.
If the health-care system fails, the chances of survival are reduced.
In the <i>simulation</i> file, you can set the capability of your country's health system.

<h1>How are people getting infected?</h1>
Since there are conflicting hypotheses on how the virus spreads, we concluded that there is always a risk of being infected when you encounter an infected person, but risk is not 100%.
In the <i>simulation</i> file, you can set the capability of your country's health system.

<h1>Cooperation among people</h1>
Quarantine does not apply to all.
Every individual is associated with a boolean field called cooperativeness.

People who are cooperative seldom leave their homes and don't travel far.

<h1>Statistics</h1>
The following statistics are kept track of by us:
<li>Total number of cases.</li>
<li>Total number of deaths.</li>
