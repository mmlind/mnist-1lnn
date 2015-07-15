/**
 * @file mnist-utils.h
 * @brief Utitlies for handling the MNIST files
 * @see http://yann.lecun.com/exdb/mnist/
 * @author Matt Lind
 * @date July 2015
 */

#include <stdint.h>
#include <stdio.h>


#define MNIST_TRAINING_SET_IMAGE_FILE_NAME "data/train-images-idx3-ubyte" ///< MNIST image training file in the data folder
#define MNIST_TRAINING_SET_LABEL_FILE_NAME "data/train-labels-idx1-ubyte" ///< MNIST label training file in the data folder

#define MNIST_TESTING_SET_IMAGE_FILE_NAME "data/t10k-images-idx3-ubyte"  ///< MNIST image testing file in the data folder
#define MNIST_TESTING_SET_LABEL_FILE_NAME "data/t10k-labels-idx1-ubyte"  ///< MNIST label testing file in the data folder



#define MNIST_MAX_TRAINING_IMAGES 60000                     ///< number of images+labels in the TRAIN file/s
#define MNIST_MAX_TESTING_IMAGES 10000                      ///< number of images+labels in the TEST file/s
#define MNIST_IMG_WIDTH 28                                  ///< image width in pixel
#define MNIST_IMG_HEIGHT 28                                 ///< image height in pixel



typedef struct MNIST_ImageFileHeader MNIST_ImageFileHeader;
typedef struct MNIST_LabelFileHeader MNIST_LabelFileHeader;

typedef struct MNIST_Image MNIST_Image;
typedef uint8_t MNIST_Label;



/**
 * @brief Data block defining a MNIST image
 * @see http://yann.lecun.com/exdb/mnist/ for details
 */
struct MNIST_Image{
    uint8_t pixel[28*28];
};




/**
 * @brief Data block defining a MNIST image file header
 * @attention The fields in this structure are not used.
 * What matters is their byte size to move the file pointer
 * to the first image.
 * @see http://yann.lecun.com/exdb/mnist/ for details
 */

struct MNIST_ImageFileHeader{
    uint32_t magicNumber;
    uint32_t maxImages;
    uint32_t imgWidth;
    uint32_t imgHeight;
};




/**
 * @brief Data block defining a MNIST label file header
 * @attention The fields in this structure are not used.
 * What matters is their byte size to move the file pointer
 * to the first label.
 * @see http://yann.lecun.com/exdb/mnist/ for details
 */

struct MNIST_LabelFileHeader{
    uint32_t magicNumber;
    uint32_t maxImages;
};




/**
 * @brief Read MNIST IMAGE file header
 * @see http://yann.lecun.com/exdb/mnist/ for definition details
 */

FILE *openMNISTImageFile(char *fileName);




/**
 * @brief Read MNIST label file header
 * @see http://yann.lecun.com/exdb/mnist/ for definition details
 */

FILE *openMNISTLabelFile(char *fileName);



/**
 * @brief Returns the next image in given MNIST image file
 */

MNIST_Image getImage(FILE *imageFile);




/**
 * @brief Returns the next label in given MNIST label file
 */

MNIST_Label getLabel(FILE *labelFile);
