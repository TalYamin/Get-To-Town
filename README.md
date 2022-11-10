# Get To Town

### Problem Description:

Given a number of cities in a distant country, where different cities are connected by one-way roads to the other cities.
It is forbidden to drive in contrast to direction of traffic, not all cities are connected to the other cities.

![image](https://user-images.githubusercontent.com/44345318/201055858-120cc822-be11-4128-8f3e-9751ee3a2cbe.png)


A citizen who wants to reach his destination can pass through any of the cities connected to his city, and from there continue to the cities
to which those cities are connected.
For a citizen in a certain city, we would like to understand what all the cities are that he is able to reach.
We will use the following settings:

Moked - a citizen in a certain city.
Moked's accessible-group - the group of cities that the citizen can reach.

For example, in the drawing - if a citizen in city 1 can get to city 4 and 4 - can get to 5 -, let's say that Moked - his accessible group is { 1,4,5}
Another example - for the 3 call center, its accessible group is { 3,2,4,5}
