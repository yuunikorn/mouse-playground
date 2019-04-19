
//calculate optimistic distance from one cell to another cell
int calcDist(byte x, byte y, byte goalX, byte goalY) {
  return abs(goalY - y) + abs(goalX - x);
}
void printMaze() {
  for (int j = 0; j < Y; j++) {
    for (int i = 0; i < X; i++) {
//      Serial.print(maze[j][i].walls);
//      Serial.print(" ");
    }
    //Serial.println();
  }
}

void printFlood() {
  for (int j = 0; j < Y; j++) {
    for (int i = 0; i < X; i++) {
      Serial.print(maze[j][i].distance);
      Serial.print(" ");
    }
    Serial.println();
  }
}

// optimistic distance from one cell to the square in the center
int calcDistToGoal(byte x, byte y, byte maze_dimension) {
  int center = maze_dimension / 2;
  int dist = 0;

  //  if (y < center){
  //    if (x < center){
  //      //top left of the maze
  //      dist = calcDist(x,y, (center-1),(center-1)); //distance to top left center
  //    } else{
  //      //top right
  //      dist = calcDist(x,y, (center),center-1);
  //    }
  //  } else{
  //    if (x > center){
  //      //bottom right
  //      dist = calcDist(x,y,center,center);
  //    } else{
  //      //top left
  //      dist = calcDist(x,y,center-1,center);
  //    }
  //  }

  int minXDis = min(abs(center - x), abs(center - x - 1));
  int minYDis = min(abs(center - y), abs(center - y - 1));
  dist = minXDis + minYDis;

  return dist;
}

//get new coordinate based on the current coord and the heading
coord getNewCoordinate(coord current, int orientation) {
  coord newCoord = {0, 0};

  if (orientation == 1) {
    newCoord.y = current.y;
    newCoord.x = current.x - 1;
  } else if (orientation == 2) {
    newCoord.y = current.y;
    newCoord.x = current.x + 1;
  } else if (orientation == 4) {
    newCoord.y = current.y + 1;
    newCoord.x = current.x;
  } else if (orientation == 8) {
    newCoord.y = current.y - 1;
    newCoord.x = current.x;
  }

  return newCoord;
}

//get neighbors' minimum distance
int getMinimumNeighbors(coord current) {
  int minVal = -1;

  for (int i = 0; i < 4; i++) {

    //check if accessbile

    if (byte(maze[current.x][current.y].walls & orientation[i]) != 0) {
      coord neighbor = getNewCoordinate(current, orientation[i]);

      //if valid cell

      if (isValid(neighbor)) {
        if (minVal == -1) {
          minVal = maze[neighbor.x][neighbor.y].distance;
        } else {
          if (maze[neighbor.x][neighbor.y].distance < minVal) {
            minVal = maze[neighbor.x][neighbor.y].distance;
          }
        }
      }
    }
  }

  return minVal;
}

//check if a coord is valid
bool isValid(coord current) {
  if (current.x < 0 || current.x >= X || current.y < 0 || current.y >= Y) {
    return false;
  }
  return true;
}

//check if a cell is bounded on three sides
bool isDeadEnd(coord current) {
  if (isValid(current)) {
    int walls = maze[current.x][current.y].walls;

    if (walls == 1 || walls == 2 || walls == 3 || walls == 4) {
      return true; //bounded on three sides
    }
    return false;
  }
  return false;
}

bool win(coord current, coord goals[]) {
  if (isValid(current)) {
    for (int i = 0; i < sizeof(goals); i++) {
      if (current.x == goals[i].x && current.y == goals[i].y) {
        return true;
      }
    }
    return false;
  }
  return false;
}

//add a wall to a cell
void updatecoord(coord current, int walldir) {
  if (isValid(current)) {
    if (byte(maze[current.x][current.y].walls & walldir) != 0) {
      if (walldir == 2) {
        walldir == 1;
      } else if (walldir == 1) {
        walldir == 2;
      }
      maze[current.x][current.y].walls -= walldir;
    }
  }
}

int optimalDirection(coord current, int heading) {
  coord leastNext = {0, 0};

  int leastNextVal = X * Y;
  int leastDir = heading;
  //Serial.println(byte(maze[current.x][current.y].walls & (byte)heading) != 0);
  //Serial.println(byte(maze[current.x][current.y].walls & heading) != 0);

  if (byte(maze[current.x][current.y].walls & heading) != 0) {

    coord leastnextTemp = getNewCoordinate(current, heading);

    if (isValid(leastnextTemp)) {
      leastNext = leastnextTemp;
      leastNextVal = maze[leastNext.x][leastNext.y].distance;
    }
  }

  for (int i = 0; i < 4; i++) {
    int dir = orientation[i];

    //Serial.println(byte(maze[current.x][current.y].walls & dir) != 0);
    if (byte(maze[current.x][current.y].walls & dir) != 0) {
      coord dirCoord = getNewCoordinate(current, dir);

      if (isValid(dirCoord)) {
        if (maze[dirCoord.x][dirCoord.y].distance < leastNextVal) {
          leastNextVal = maze[dirCoord.x][dirCoord.y].distance;
          leastNext = dirCoord;
          leastDir = dir;
        }
      }
      Serial.println(leastDir);
    }
  }
  Serial.println(leastDir);
  return leastDir;
}

byte updateWalls() {
  byte res = 15;
  byte forward = 0;
  byte backward = 0;
  byte left = 0;
  byte right = 0;

  switch (globalHeading) {
    case 1:
      if (analogRead(FRONT) >= 150) {
        backward = 1;
      }

      if (analogRead(LEFT) >= 150) {
        left = 8;
      }

      if (analogRead(RIGHT) >= 150) {
        right = 4;
      }

      res -= backward + left + right;
      break;
    case 2:
      if (analogRead(FRONT) >= 150) {
        forward = 2;
      }

      if (analogRead(LEFT) >= 150) {
        right = 4;
      }

      if (analogRead(RIGHT) >= 150) {
        left = 8;
      }

      res -= forward + left + right;
      break;
    case 4:
      if (analogRead(FRONT) >= 150) {
        right = 4;
      }

      if (analogRead(LEFT) >= 150) {
        backward = 1;
      }

      if (analogRead(RIGHT) >= 150) {
        forward = 2;
      }

      res -= forward + backward + right;
      break;
    case 8:
      if (analogRead(FRONT) >= 150) {
        left = 8;
      }

      if (analogRead(LEFT) >= 150) {
        forward = 2;
      }

      if (analogRead(RIGHT) >= 150) {
        backward = 1;
      }

      res -= backward + left + forward;
      break;
  }

  return res;
}

void floodfill(coord current, coord goals[]) {
  StackArray<coord> coords;

  maze[current.x][current.y].walls = updateWalls();
  //Serial.println(current.x);
  //Serial.println(current.y);
  //Serial.println(maze[current.x][current.y].walls);
  //printMaze();
  //printFlood();
  delay(1000);
  coords.push(current);

  for (int i = 0; i < 4; i++) {
    //if there is a wall in this direction
    if (byte(maze[current.x][current.y].walls & orientation[i] == 0)) {
      coord temp = {current.x, current.y};

      //add walls to a cell
      switch (orientation[i]) {
        case 1:
          temp.x = temp.x - 1;
          updatecoord(temp, 2);
          break;
        case 2:
          temp.x = temp.x + 1;
          updatecoord(temp, 1);
          break;
        case 4:
          temp.y = temp.y + 1;
          updatecoord(temp, 8);
          break;
        case 8:
          temp.y = temp.y - 1;
          updatecoord(temp, 4);
          break;
      }

      //if the coord is a valid entry and not the goal, push it onto the stack
      if ((isValid(temp) && !win(temp, goals))) {
        coords.push(temp);
      }
    }
  }

  while (!coords.isEmpty()) {
    coord cur = coords.pop();
    int neighCheck = getMinimumNeighbors(cur);
    //if the least neighbor of the current is not one less than the current
    if (neighCheck + 1 != maze[cur.x][cur.y].distance) {
      maze[cur.x][cur.y].distance = neighCheck + 1;

      for (int i = 0; i < 4; i++) {
        byte dir = orientation[i];
        //no walls in this direction
        if (byte(maze[cur.x][cur.y].walls & dir != 0)) {
          coord next = getNewCoordinate(cur, dir);
          if (isValid(next)) {
            if (!win(next, goals)) {
              coords.push(next);
            }
          }
        }
      }
    }
  }
}

command createCommand(coord current, coord next, byte heading) {
  //0: left
  //1: right
  //2: 180
  //3: stay
  int direction = 3;
  switch (heading) {
    case 1:
      if (globalHeading == 2) {
        direction = 2;
      }

      if (globalHeading == 4) {
        direction = 0;
      }

      if (globalHeading == 8) {
        direction = 1;
      }
      break;
    case 2:
      if (globalHeading == 1) {
        direction = 2;
      }

      if (globalHeading == 4) {
        direction = 1;
      }

      if (globalHeading == 8) {
        direction = 0;
      }
      break;
    case 4:
      if (globalHeading == 1) {
        direction = 1;
      }

      if (globalHeading == 2) {
        direction = 0;
      }

      if (globalHeading == 8) {
        direction = 2;
      }
      break;
    case 8:
      if (globalHeading == 1) {
        direction = 0;
      }

      if (globalHeading == 2) {
        direction = 1;
      }

      if (globalHeading == 4) {
        direction = 2;
      }
      break;
  }

  command aMove = {direction};
  return aMove;
}

void executeCommand(command cmd, int num) {
  switch (cmd.orientation) {
    case 0:
      turnLeft();
      break;
    case 1:
      turnRight();
      break;
    case 2:
      turn180();
      break;
  }
  if (num == 0) {
    forwardOneBlock();
  } else {
    forwardOneBlockFaster();
  }
  delay(100);
}

void solveMaze(coord goals[], coord current, bool isMoving) {
  coord cur = current;
  byte heading = globalHeading;

  //Serial.println(33);
  //Serial.println(maze[cur.x][cur.y].distance != 0);
  //Serial.println();
  while (maze[cur.x][cur.y].distance != 0) {
    floodfill(cur, goals);
//    Serial.println();
//    Serial.print("x is:");
//    Serial.println(cur.x);
//    Serial.print("patrick is:");
//    Serial.println(cur.y);
//    Serial.println();
    byte nextHeading = optimalDirection(cur, heading);

    coord next = getNewCoordinate(cur, nextHeading);

    if (isMoving) {
      commands.push(createCommand(cur, next, nextHeading));
      executeCommand(commands.pop(), 0);
    }

    //After executing the command update the values of the local and global variable
    cur = next;
    heading = nextHeading;

    //if the robot has moved, update the global position
    //if (isMoving){
    globalHeading = heading;
    globalCoord = cur;
    //}
  }

  globalEnd = cur;
}

void instantiate() {
  //maze[X/2-1][Y/2-1].distance = 0;
  //maze[X/2-1][Y/2].distance = 0;
  //maze[X/2][Y/2-1].distance = 0;
  //maze[X/2][Y/2].distance = 0;
  for (int i = 0; i < X; i++) {
    for (int j = 0; j < Y; j++) {
      maze[i][j].distance = calcDistToGoal(i, j, X);
      maze[i][j].walls = 15; //no wall

      if (i == 0) {
        //top row
        maze[i][j].walls = 14;
      }

      if (i == X - 1) {
        //bottom row
        maze[i][j].walls = 13;
      }

      if (j == Y - 1) {
        //rightest column
        maze[i][j].walls = 11;
      }

      if (j == 0) {
        //leftest column
        maze[i][j].walls = 7;
      }
    }
  }

  maze[0][0].walls = 4;
  maze[X - 1][0].walls = 5;
  maze[0][Y - 1].walls = 10;
  maze[X - 1][Y - 1].walls = 9;
}
