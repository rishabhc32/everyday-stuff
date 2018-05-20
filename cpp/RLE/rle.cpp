#include <iostream>
#include <vector>
#include <exception>
#include <climits>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

class RLE {
    CImg<int> image;
    vector<vector<pair<int,int> > > rle;

    static const char* check_image_path(const char *im_path) {
        if(cimg::is_file(im_path)) 
            return im_path;
        else
            throw std::invalid_argument("File does not exist");
    }

public:
    RLE() {}
    RLE(const char *im_path): 
        image(check_image_path(im_path)), rle(image.height()) {
            this->encode();
        }
    RLE(const CImg<int>& arg_im):
        image(arg_im), rle(arg_im.height()) {
            this->encode();
        }

    void encode() {
        bool flag = false;
        int previous_pixel = INT_MAX, pixel_count = 0;

        cimg_forY(image, y) {
            cimg_forX(image, x) {
                const int current_pixel = image(x,y);
                switch((int)flag) {
                    case 0: 
                        flag = true;
                        previous_pixel = current_pixel;
                        pixel_count = 1;
                        break;
                    case 1:
                        if(current_pixel == previous_pixel)
                            ++pixel_count;
                        else {
                            rle.at(y).push_back(make_pair(previous_pixel, pixel_count));
                            previous_pixel = current_pixel;
                            pixel_count = 1;
                        }
                        break;   
                }
            }
            rle.at(y).push_back(make_pair(previous_pixel, pixel_count));
            flag = false;
            previous_pixel = INT_MAX;
            pixel_count = 0;
        }
    }

    CImg<int> decode() {
        CImg<int> org_im(image.width(), image.height(), 1, 1);
        int x=0, y=0;

        for(const vector<pair<int, int> > &v : rle ) {
            for(const pair<int, int> &p : v) {
                for(int i=0; i< p.second ; ++i) {
                    org_im(x, y) = p.first;
                    ++x;
                }   
            }
            ++y;
            x=0;
        }

        return org_im;
    }

    void display_encoded() {
        for(const vector<pair<int, int> > &v : rle) {
            for(const pair<int, int> &p : v) 
                cout<<p.first<<","<<p.second<<"  ";
        
            cout<<endl;
        }
    }

    const CImg<int>& getImage() {
        return image;
    }

};

void print_error(char **);

int main (int argc, char *argv[]) {
    if(argc != 2) {
        print_error(argv);
        return 0;
    }
    
    RLE rle(argv[1]);
    //rle.display_encoded();

    CImg<int> new_im = rle.decode();

    if(rle.getImage() == new_im)
        cout<<"Decode Successful\n";
    else
        cout<<"Decode Unsuccessful\n";

    //RLE r(new_im);
    //r.display_encoded();

    return 0;
}

void print_error(char *argv[]) {
    cerr<<"Error: Required 1 argument"<<endl;
    cerr<<"Usage: "<<argv[0]<<" <image_path>"<<endl;
}
