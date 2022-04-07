#include "image.h"
#include "deque.hpp"




#define MAZE_WALL BLACK
#define MAZE_AIR WHITE
#define MAZE_START RED
#define MAZE_END GREEN

struct ImagePos{
  intmax_t x;
  intmax_t y;
};

//Prototypes
ImagePos 


bool breadth_first_search(Image<Pixel>& image){
  //Find start pixels
  ImagePos start = initial(image);

  //Create frontier and explored arrays
  Deque<ImagePos> frontier;
  std::vector<ImagePos> explored;

  while(true){
    //Chec that frontier is not empty
    if(frontier.isEmpty()){return }
  }
}

/*//Function to load image from file
Image<Pixel> loadImage(char *argv[]){
  Image<Pixel> image = readFromFile(argv[1]);
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
    //Throw exception
  }
  r.p = starts.at(0);
  r.s = Yes;
  return r;
}*/



int main(int argc, char *argv[])
{
  // TODO
}
