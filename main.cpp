//David Strickkland
//Faith Van Wig
//Class and Section: CS53 D
//Date: December 4, 2013
//Final Assingment, OOP, Bar people vs. Comic People

#include <fstream>
#include <cstdlib>
#include <ctime>
#include "business.h"


main.cpp
{
  Customer people[PEOPLE];
  Business bar("bar"), comicShop("Comic Book Shop");
  
  string tempName;
  int tempNum, numPeople, numRounds, shuffleNum;
  float cost;
  ifstream fin, moeSet, comicSet;
  Customer tempCust;
  
  //inits the People
  
  srand(time(NULL));
  
  fin.open("people.txt");
  while(fin.good())
  {
    for(int i = 0; i < PEOPLE; i++)
    {
      getline(fin,tempName, ',');
      people[i].setName(tempName);
      getline(fin, tempNum, '\n');
      people[i].setPref(tempNum);
    }
  }
  fin.close();
  
  //inits the Products for the businesses
  
  moeSet.open("Moe_items.txt");
  while(moeSet.good());
  {
    for(int i = 0; i < (NUM_OF_ITEMS - 1); i++)
    {
      getline(moeSet, cost, ' ');
      getline(moeSet, tempName, '\n');
      bar.modProd(i, cost, tempName);
    }
  }
  moeSet.close();
  
  comicSet.open("CBS_items.txt");
  while(comicSet.good())
  {
    for(int i = 0; i < (NUM_OF_ITEMS - 1); i++)
    {
      getline(moeSet, cost, ' ');
      getline(moeSet, tempName, '\n');
      bar.modProd(i, cost, tempName);
    }
  }
  comicSet.close();
  
  for(int i = 0; i < numPeople; i++)
  {
    cout << people[i] << endl;
  }
  
  while(numPeople > 1 && numRounds <= 20)
  {
    for(int i = 0; i < numPeople; i++)
    {
      if(people.m_store == 1)
        comicShop.addCustomer(people[i]);
      else
        bar.addCustomer(people[i]);
    }
  
    //for loop in the sell stuff function
    bar.sell_stuff();
    comicShop.sell_stuff();
    
    comicShop.customers_leave(people[], numPeople);
    bar.customers_leave(people[], numPeople);
    
    //SHUFFLE ARRAY (people[])
    for(int i = 0; i < PEOPLE; i++)
    {
      shuffleNum = rand() % PEOPLE;
      tempCust = people[i];
      people[i] = people[shuffleNum];
      people[shuffleNum] = tempCust;
    }
    
    //attacking people
    for(int i = 0; i < numPeople; i++)
    {
      tempNum = rand() % 20;
      if (i = tempNum)
      else
        if (people[i].getPref() == people[tempNum].getPref())  
          steal(people[tempNum]);
        else 
          pelt(people[tempNum]);
    }
    
    //PLACEHOLDER
    for (int i = 0; i < numPeople; i++)
    {
      
      if (people[i].getHappy() < 10)
      {
        tempCust = people[numPeople-1];
        people[numPeople-1]=people[i];
        people[i] = tempCust;
        numPeople--;
        cout << people[i].getName() << " was taken to the Shelbyville House of Desperation" << endl;
      }
      
      else if (people[i].getHappy() >= 90)
      {
        tempCust = people[numPeople-1];
        people[numPeople-1]=people[i];
        people[i] = tempCust;
        numPeople--;
        cout << people[i].getName() << " went Shelbyville to lorde over those in the House of Desperation" << endl;
      }
      
    }
    
    for(int i = 0; i < numPeople; i++)
    {
      cout << people[i] << endl;
    }
  } 

  return 0;
}
