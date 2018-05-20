#include "CImg.h"
#include <iostream>

#ifdef cimg_verbosity
#undef cimg_verbosity
#define cimg_verbosity 3

using namespace std;
using namespace cimg_library;

int main() {
    CImg<unsigned char> image(3,2,1,1,0);
   
    image(0,0) = (unsigned char)14;
    image(1,0) = (unsigned char)20;
    image(2,0) = (unsigned char)15;
    image(0,1) = (unsigned char)17;
    image(1,1) = (unsigned char)22;
    image(2,1) = (unsigned char)16;

    image.save_jpeg("yo.jpeg");

    cimg_forY(image, y) {
        cimg_forX(image, X) {
            cout<<"("<<X<<","<<y<<") : "<<image(X,y)<<endl;
        }
    }

    return 0;
}

#endif
