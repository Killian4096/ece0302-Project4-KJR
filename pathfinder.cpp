#include "image.h"
#include "deque.hpp"
#include <vector>
#include <iostream>




#define MAZE_WALL BLACK
#define MAZE_AIR WHITE
#define MAZE_START RED
#define MAZE_END GREEN

struct ImagePos{
  intmax_t x;
  intmax_t y;
};

//Prototypes
ImagePos initial(Image<Pixel>& image);
bool goal(Image<Pixel>& image, ImagePos point);
std::vector<ImagePos> actions(Image<Pixel>& image, ImagePos currentState);
bool containsPosition(std::vector<ImagePos>& array, ImagePos pixel);
ImagePos breadth_first_search(Image<Pixel>& image);
Image<Pixel> loadImage(std::string argv);
bool inBounds(Image<Pixel>& image, ImagePos pixel);

int main(int argc, char *argv[])
{

  //Try to run it all
    //Load Image
    Image<Pixel> image = loadImage(argv[1]);
    breadth_first_search(image);
    writeToFile(image, argv[2]);
/*  //Catch one of the many errors
  catch(const std::exception & ex){
    std::cout << ex.what() << std::endl;
    //Return failure
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;*/
}



ImagePos breadth_first_search(Image<Pixel>& image){
  //Find start pixels
  ImagePos start = initial(image);

  //Check if start is goal
  if(goal(image, start)){
    return start;
  }

  //Create frontier and explored arrays
  Deque<ImagePos> frontier;
  frontier.pushBack(start);
  std::vector<ImagePos> explored;

  while(true){
    //Check that frontier is not empty
    if(frontier.isEmpty()){
      ImagePos r;
      r.x=0;
      r.y=0;
      std::cout << "No solution found\n";
      return r;
      //throw "No Solution Found";
    }

    //Pop top from frontier
    ImagePos s = frontier.front();
    frontier.popFront();

    //Add s to explored
    explored.push_back(s);

    //Get list of next actions
    std::vector<ImagePos> next_actions = actions(image, s);

    //Iterate over each next action
    for(intmax_t i=0;i<next_actions.size();i++){
      //Check if not in explored
      if(!(containsPosition(explored, next_actions[i]))){
        //if goal, we found it
        if(goal(image, next_actions[i])){
          return next_actions[i];
        }
        //insert into frontier
        frontier.pushBack(next_actions[i]);
      }
    }
    
  }



}

//Function to load image from file
Image<Pixel> loadImage(std::string argv){
  //Read image and throw if error
  Image<Pixel> image;
  try{
    image = readFromFile(argv);
  }catch(...){
    throw "Error";
  }

  //If any pixel other than the 3 standard colors throw
  for(intmax_t i=0;i<image.width();i++){
    for(intmax_t j=0;j<image.height();j++){
      if(!(
        image(i,j)==MAZE_AIR ||
        image(i,j)==MAZE_WALL ||
        image(i,j)==MAZE_START
      )){
        throw "Error";
      }
    }
  }


  return image;
}

//Traverse image and find start pixel
ImagePos initial(Image<Pixel>& image){
  //Traverse image and find starts
  std::vector<ImagePos> starts;
  for(intmax_t i=0;i<image.width();i++){
    for(intmax_t j=0;j<image.height();j++){
      if(image(i,j)==RED){
        ImagePos r;
        r.x = i;
        r.y = j;
        starts.push_back(r);
      }
    }
  }
  //If the number of starts invalid, create null return
  if(starts.size()!=1){
    throw "Error";
  }
  return starts[0];
}

//Returns true if we found the goal
bool goal(Image<Pixel>& image, ImagePos point){
  //Check if on border
  if(
    point.x == 0 || point.y ==0 ||
    point.x == image.width()-1 || point.y == image.height()
  ){
    //Draw green square
    image(point.x, point.y) = MAZE_END;
    //True if on border
    return true;
  }
  //False if not on border
  return false;
}

std::vector<ImagePos> actions(Image<Pixel>& image, ImagePos currentState){
  //Create vector to hold possible steps
  std::vector<ImagePos> steps;

  //For each step, determine if valid and add to steps
  for(short int i=-1;i<2;i=i+1){
    //Make next step
    ImagePos nextstep;
    nextstep.x = currentState.x+i;
    nextstep.y = currentState.y;
    //Determine if valid
    if(image(nextstep.x, nextstep.y)==MAZE_AIR){
      steps.push_back(nextstep);
    }
  }
  //For each step, determine if valid and add to steps
  for(short int i=-1;i<2;i=i+1){
    //Make next step
    ImagePos nextstep;
    nextstep.x = currentState.x;
    nextstep.y = currentState.y+i;
    //Determine if valid
    if(image(nextstep.x, nextstep.y)==MAZE_AIR){
      steps.push_back(nextstep);
    }
  }
  return steps;
}


//Function to check if item in vector
bool containsPosition(std::vector<ImagePos>& array, ImagePos pixel){
  for(std::size_t i=0;i<array.size();i++){
    if(array[i].x==pixel.x && array[i].y==pixel.y){
      return true;
    }
  }
  return false;
}