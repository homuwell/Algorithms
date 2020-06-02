#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
#include "../lab3/headers/Tree.h"

using namespace std;

class stack {
 public:
  struct Node {
    int data;
    Node *prev;
  };
  Node *top;

  void push(int value) {
    Node *elem = new Node;
    elem->data = value;
    if (top == nullptr) {
      top = elem;
      top->prev = nullptr;
    } else {
      elem->prev = top;
      top = elem;
    }
  }

  int pop() {
    Node *tmp_ptr = top;
    int rmbr_data = top->data;
    top = tmp_ptr->prev;
    tmp_ptr->prev = nullptr;
    delete tmp_ptr;
    return rmbr_data;
  }
};

bool cheak_arr(int *arr1, int *arr2, size_t len) {
  bool flag;
  flag = true;
  for (int i = 0; i < len; i++) {
    if (arr1[i] != arr2[i]) {
      flag = false;
      break;
    }
  }
  return flag;
}

bool cheak_arr(char *arr1, char *arr2, size_t len) {
  bool flag;
  flag = true;
  for (int i = 0; i < len; i++) {
    if (arr1[i] != arr2[i]) {
      flag = false;
      break;
    }
  }
  return flag;
}

void gen_arr(int *arr, size_t len) {
  srand(time(NULL));
  for (int i = 0; i < len; i++) {
    arr[i] = 1 + rand() % 10000;
  }
}

bool binary_search(int *arr, size_t len, int value) {
  int start = 0;
  int end = len;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (value == arr[mid]) {
      return true;
    } else if (value > arr[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return false;

}

void qsortRecursive(int *arr, size_t len) {
  int i = 0;
  int j = len - 1;

  int mid = arr[len / 2];

  do {
    while (arr[i] < mid) {
      i++;
    }

    while (arr[j] > mid) {
      j--;
    }

    if (i <= j) {
      int tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;

      i++;
      j--;
    }
  } while (i <= j);

  if (j > 0) {

    qsortRecursive(arr, j + 1);
  }
  if (i < len) {

    qsortRecursive(&arr[i], len - i);
  }
}

void insert_sort(int *arr, size_t len) {
  int temp,
      item;
  for (int counter = 1; counter < len; counter++) {
    temp = arr[counter];
    item = counter - 1;
    while (item >= 0 && arr[item] > temp) {
      arr[item + 1] = arr[item];
      arr[item] = temp;
      item--;
    }
  }
}

void DFS(Tree::Node *elem, stack *st) {
  if (elem) {
    DFS(elem->right, st);
    st->push(elem->key);
    DFS(elem->left, st);
  }

}

void BinaryTreeSort(int *arr, size_t len) {
  Tree bint;
  for (int i = 0; i < len; i++) {
    bint.insert(arr[i]);
  }
  Tree::Node *curr = bint.head;
  stack *st = new stack;
  st->top = nullptr;
  int i = 0;
  DFS(curr, st);
  while (st->top != nullptr) {
    arr[i] = st->pop();
    i++;
  }
}

bool isSorted(int a[], int n) {
  while (--n > 0)
    if (a[n] < a[n - 1]) {
      return false;
    }
  return true;
}

void shuffle(int a[], int n) {
  for (int i = 0; i < n; i++)
    swap(a[i], a[rand() % n]);
}

void bogosort(int a[], int n) {

  while (!isSorted(a, n))
    shuffle(a, n);
}

void CountingSort(char *arr, size_t len) {
  int massiv_zero[256]{0};
  for (size_t j = 0; j < len; j++) {
    massiv_zero[arr[j]] = massiv_zero[arr[j]] + 1;
  }
  size_t b = 0;
  for (size_t j = 0; j <= 255; j++) {
    for (size_t i = 0; i < massiv_zero[j]; i++) {
      arr[b] = j;
      b++;
    }
  }
}

long int runQuickSort(int *arr, std::size_t len) {
  gen_arr(arr, len);
  auto beg_time = chrono::high_resolution_clock::now();
  qsortRecursive(arr, len);
  auto end_time = chrono::high_resolution_clock::now();
  auto time = chrono::duration_cast<chrono::nanoseconds>(end_time - beg_time);
  return time.count();

}

void testQuickSort() {
  int arr10[10];
  int arr100[100];
  int arr1000[1000];
  int arr10000[10000];
  int arr100000[100000];
  fstream f;
  f.open("/home/homuwell/CLionProjects/algorithms/lab4/files/QuickSortTests", ios::out);
  for (int i = 0; i < 10; i++) {
    if (i != 9) {
      f << runQuickSort(arr10, 10) << ' ';
    } else {
      f << runQuickSort(arr10, 10) << '\n';
    }
  }
  for (int i = 0; i < 10; i++) {
    if (i != 9) {
      f << runQuickSort(arr100, 100) << ' ';
    } else {
      f << runQuickSort(arr100, 100) << '\n';
    }
  }
  for (int i = 0; i < 10; i++) {
    if (i != 9) {
      f << runQuickSort(arr1000, 1000) << ' ';
    } else {
      f << runQuickSort(arr1000, 1000) << '\n';
    }
  }
  for (int i = 0; i < 10; i++) {
    if (i != 9) {
      f << runQuickSort(arr10000, 10000) << ' ';
    } else {
      f << runQuickSort(arr10000, 10000) << '\n';
    }
  }
  for (int i = 0; i < 10; i++) {
    if (i != 9) {
      f << runQuickSort(arr100000, 100000) << ' ';
    } else {
      f << runQuickSort(arr100000, 100000) << '\n';
    }
  }
  f.close();

}

long int runInsertSort(int *arr, std::size_t len) {
  gen_arr(arr, len);
  auto beg_time = chrono::high_resolution_clock::now();
  insert_sort(arr, len);
  auto end_time = chrono::high_resolution_clock::now();
  auto time = chrono::duration_cast<chrono::nanoseconds>(end_time - beg_time);
  return time.count();

}

void testInsertSort() {
  int arr10[10];
  int arr100[100];
  int arr1000[1000];
  int arr10000[10000];
  int arr100000[100000];
  fstream f;
  f.open("/home/homuwell/CLionProjects/algorithms/lab4/files/InsertSortTests", ios::out);
  for (int i = 0; i < 10; i++) {
    if (i != 9) {
      f << runInsertSort(arr10, 10) << ' ';
    } else {
      f << runInsertSort(arr10, 10) << '\n';
    }
  }
  for (int i = 0; i < 10; i++) {
    if (i != 9) {
      f << runInsertSort(arr100, 100) << ' ';
    } else {
      f << runInsertSort(arr100, 100) << '\n';
    }
  }
  for (int i = 0; i < 10; i++) {
    if (i != 9) {
      f << runInsertSort(arr1000, 1000) << ' ';
    } else {
      f << runInsertSort(arr1000, 1000) << '\n';
    }
  }
  for (int i = 0; i < 10; i++) {
    if (i != 9) {
      f << runInsertSort(arr10000, 10000) << ' ';
    } else {
      f << runInsertSort(arr10000, 10000) << '\n';
    }
  }
  for (int i = 0; i < 10; i++) {
    if (i != 9) {
      f << runInsertSort(arr100000, 100000) << ' ';
    } else {
      f << runInsertSort(arr100000, 100000) << '\n';
    }
  }
  f.close();

}

