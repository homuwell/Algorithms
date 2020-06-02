#include <iostream>
#include <cstring>
#include "headers/Item.h"
#include "additional/exceptions.cpp"
using namespace std;
void findAns(int **A, int i, int j, Item *items_, int *arr) {
  if (A[i][j] == 0) {
    return;
  } else if (A[i - 1][j] == A[i][j]) {
    findAns(A, i - 1, j, items_, arr);
  } else {
    findAns(A, i - 1, j - items_[i].weight, items_, arr);
    arr[items_[i].name]++;
  }
}

int BackPackFunc() {
  int BackpackWeight;
  int ItemsNum;
  cout << "Enter the number of intems: ";
  cin >> ItemsNum;
  try {
    if (ItemsNum < 0 || (int) ItemsNum != ItemsNum) {
      throw ItemsNumError();
    }
  }
  catch (ItemsNumError) {
    cout << "Number of Items must be number and positive";
    return 0;
  }
  cout << endl;
  int numberOfItems = (int) ItemsNum;

  Item *items = new Item[numberOfItems + 1];
  float tmpW;
  float tmpP;
  float tmpB_;
  string name;
  string NameArr[ItemsNum];
  for (int i = 1; i <= numberOfItems; i++) {
    cout << "Enter the name of " << i << ' ' << "item: ";
    cin >> name;
    cout << "Enter the weight of " << i << ' ' << "item: ";
    cin >> tmpW;
    try {
      if (tmpW < 0 || tmpW != (int) tmpW) {
        throw WeightError();
      }
    }
    catch (WeightError) {
      cout << "weight must be number and positive";
      return 0;
    }
    items[i].weight = (int) tmpW;
    cout << endl;
    cout << "Enter the cost of " << i << ' ' << " item: ";
    cin >> tmpP;
    try {
      if (tmpP < 0 || tmpP != (int) tmpP) {
        throw PriceError();
      }
    }

    catch (PriceError) {
      cout << "price must be number and positive";
      return 0;
    }
    items[i].cost = (int) tmpP;
    cout << endl;
    cout << "Enter a pieces of the number" << i << ' ' << "item: ";
    cin >> tmpB_;
    try {
      if (tmpB_ <= 0 || tmpB_ != (int) tmpB_) {
        throw ItemsLimitError();
      }
    }
    catch (ItemsLimitError) {
      cout << "limit must be number and positive";
      return 0;
    }
    items[i].pieces = (int) tmpB_;
    cout << endl;
    items[i].name = i;
    items[i].NameOfItem = name;
  }
  int firstNum = numberOfItems;
  int tmpweight;
  int tmpPrice;
  int tmpB;
  int tmpNameOfItem;
  for (int i = 1; i <= firstNum; i++) {
    if (items[i].pieces > 1) {
      tmpPrice = items[i].cost;
      tmpweight = items[i].weight;
      tmpB = items[i].pieces;
      tmpNameOfItem = i;
      while (tmpB != 1) {
        numberOfItems++;
        Item *new_ptr = new Item[numberOfItems + 1];
        memmove(new_ptr, items, sizeof(Item) * (numberOfItems));
        delete[] items;
        items = new_ptr;
        items[numberOfItems].weight = tmpweight;
        items[numberOfItems].cost = tmpPrice;
        items[numberOfItems].name = tmpNameOfItem;
        tmpB--;
      }
    }
  }
  cout << "Enter the maximum weight of the backpack: ";
  cin >> BackpackWeight;
  try {
    if (BackpackWeight <= 0 || BackpackWeight != (int) BackpackWeight) {
      throw BackpackWeightError();
    }
  }
  catch (BackpackWeightError) {
    cout << "backpack weight must be number and positive";
    return 0;
  }
  int backpackweight = (int) BackpackWeight;
  cout << endl;
  int **NewArrOfItems = new int *[numberOfItems + 1];
  for (int i = 0; i < numberOfItems + 1; i++)
    NewArrOfItems[i] = new int[backpackweight + 1];

  for (int i = 0; i < backpackweight + 1; i++)
    NewArrOfItems[0][i] = 0;
  for (int i = 0; i < numberOfItems + 1; i++)
    NewArrOfItems[i][0] = 0;
  for (int i = 1; i < numberOfItems + 1; i++) {
    for (int j = 1; j < backpackweight + 1; j++) {
      if (j >= items[i].weight) {
        if (NewArrOfItems[i - 1][j] >= (NewArrOfItems[i - 1][j - items[i].weight] + items[i].cost)) {
          NewArrOfItems[i][j] = NewArrOfItems[i - 1][j];
        } else {
          NewArrOfItems[i][j] = NewArrOfItems[i - 1][j - items[i].weight] + items[i].cost;
        }
      } else {
        NewArrOfItems[i][j] = NewArrOfItems[i - 1][j];
      }
    }
  }
  int *arr = new int[firstNum + 1];
  for (int i = 0; i <= firstNum; i++)
    arr[i] = 0;
  for (int i = 0; i < numberOfItems + 1; i++) {
    for (int j = 0; j < backpackweight + 1; j++) {
      cout << NewArrOfItems[i][j] << ' ';
    }
    cout << endl;
  }

  findAns(NewArrOfItems, numberOfItems, backpackweight, items, arr);
  int finalweight = 0;
  for (int i = 1; i <= firstNum; i++) {
    if (arr[i] != 0) {
      cout << "Took the " << items[i].NameOfItem << " item " << arr[i] << " times.\n";
      finalweight = finalweight + items[i].weight * arr[i];
    }
  }
  cout << "The final weight of a backpack is " << finalweight;

  for (int i = 0; i < numberOfItems + 1; i++)
    delete[] NewArrOfItems[i];
  delete[] NewArrOfItems;
  return 0;
}



