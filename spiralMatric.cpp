#include<iostream>
#include <map>
using namespace std;

enum Direction {
  LEFT,
  RIGHT,
  UP,
  DOWN
};

class SpiralPattern
{
  private:
    int top, bottom, left, right, patternVal, i,j; int **arr;
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    bool updateCoordinates(int&, int&, Direction d);
  public:
    SpiralPattern(){};
    void initialise(int val)
    {
      patternVal=val;
      top = -1; bottom = val; left = -1, right = val;
      arr = (int **) new int*[val];
      for(int i=0;i<val;i++)
        arr[i]= new int[val];
    };
    void readPatternval()
    {
      cout <<  "Enter value of Pattern ";
      cin >> patternVal;
      initialise(patternVal);
    };
    void drawPattern();
};
bool SpiralPattern::updateCoordinates( int &i, int &j, Direction d) {
  bool retVal = true;
  if(d == RIGHT) {
    i = top+1;
    j = left+1;
  } else if(d == DOWN) {
    i = top+1;
    j = right-1;
  } else if(d == LEFT) {
    i = bottom-1;
    j = right-1;
  } else if(d == UP) {
    i = bottom-1;
    j = left+1;
  } else {
    retVal = false;
  }
  if(top+1 == bottom or left+1==right)
    retVal = false; //this is final condition to stop the drawing
  return retVal;
}

void SpiralPattern::drawPattern() {
  int i=0,j=0,k=1;
  while(1) {
    //
    if(updateCoordinates(i,j,RIGHT) == false) break;
    while(j<right) {
      arr[i][j++] = k++;
    }
    top++;
    //
    if(updateCoordinates(i,j,DOWN) == false) break;
    while(i<bottom) {
      arr[i++][j] = k++;
    }
    right--;
    //
    if(updateCoordinates(i,j,LEFT) == false) break;
    while(j>left) {
      arr[i][j--] = k++;
    }
    bottom--;
    //
    if(updateCoordinates(i,j,UP) == false) break;
    while(i>top) {
      arr[i--][j] = k++;
    }
    left++;
    //
  }
  for(i=0;i<patternVal;i++) {
    for(j=0;j<patternVal;j++) {
      cout << arr[i][j] << " ";
    }
    cout <<"\n";
  }
}

int main()
{
  SpiralPattern p;
  p.readPatternval();
  p.drawPattern();
  return 0;
}
