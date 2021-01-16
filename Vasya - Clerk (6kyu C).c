#include <stdlib.h>
#include <stdio.h>

int tickets(size_t length, const int people[length]) {
    int bills[2] = {0,0};
    for (size_t i = 0; i < length; ++i) {
      if (people[i] == 25) {
        bills[0]++;
      } else if (people[i] == 50) {
        bills[0]--;
        bills[1]++;
      } else if (people[i] == 100) {
        bills[0]--;
        if (bills[1]>0) {
          bills[1]--;
        } else {
          bills[0] -= 2;
        }
      }
      
      if (bills[0] < 0 || bills[1] < 0) 
        return 0;
    }
    return 1;
}
