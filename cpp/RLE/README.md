# RLE
> __Run-length encoding (RLE)__ is a very simple form of lossless data compression in which runs of data (that is, sequences in which the same data value occurs in many consecutive data elements) are stored as a single data value and count, rather than as the original run. This is most useful on data that contains many such runs. Consider, for example, simple graphic images such as icons, line drawings, and animations. It is not useful with files that don't have many runs as it could greatly increase the file size.
[Read More](https://en.wikipedia.org/wiki/Run-length_encoding)

![RLE Image](https://i.imgur.com/hIJy7Kj.png)

* This is an implementation of RLE on 8-bit grayscale images.
* `CImg` library is used for image manipulation and loading.
    * Easy to use.
    * Single header, no need of runtime linking.
    * [Link](http://cimg.eu/)
* Only works for single channel images, 3 channel images will result in undefined behaviour.
* Trial images are provided in the [images](https://github.com/rishabhc32/everyday-stuff/tree/master/cpp/RLE/images) folder.
    * `./images/yo.jpeg`, `3x2` grayscale image, suitable for testing purposes while reimplementing code.
* `pixel_image_generate.cpp`, is a helper file to generate hard coded pixel images for testing/debugging purpose.
    * Compiling 
        * `g++ -o a.out pixel_image_generate.cpp -lm -lpthread -lX11`
    * Usage
        * ./a.out
    * `yo.jpeg` file will be saved in PWD.
    
__Compiling__
* `g++ -std=c++11 -o <output-file> rle.cpp -lm -lpthread -lX11`
    * `g++ -std=c++11 -o rle rle.cpp -lm -lpthread -lX11`

__Usage__
The binary executable after compiling is, `rle`
* `rle <image-path>` 
    * `rle ./images/hand.jpg`
