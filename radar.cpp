#include <iostream>
//-----------------------------------------------------------------------------------------------------------
//Copyright By Shinnachot Jeerakan
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------SHORTLY DESCRIPTION-----------------------------------------------------
//
//Developing a computer visualisation program for displaying air vehicles on a radar screen. 
//Each vehicle will be displayed as a small icon made up of a number of pixels.
//
//-----------------------------------------------------------------------------------------------------------
//A major objective of this project is to understand why and how object-oriented programming techniques are used in modern software.
//This exercise is our first hands on experience of designing and implementing basic objects of our own
//-----------------------------------------------------------------------------------------------------------
//Input arguments:This program does not require input but the define value has to be in main
//Display the pixels or vehicle in the radar
//Return value: the number of icon that is stored in radarDisplay , the location and brightness of pixel that is stored in icon class

//class pixel which can be modified through constructor
class pixel {   
    public:
    float x; //coordinates X
    float y; //coordinates Y
    short brightness; //brightness for pixels

    // Constructor that initialise x y and brightness to 0
    pixel() : x(0), y(0), brightness(0) {}

    // Destructor invoke when object is going to be destroyed
    ~pixel() {}
};

//icon class which will store the data of pixel
class icon {
    public:
    pixel container[16]; //declare so that the pixel can only store 16 of the pixels
    int id_vehicle; //id for each vehicles
    int id_pixel;  //id for each pixel

    // Constructor and initialise each object to have 0
    icon() : id_vehicle(0), id_pixel(0) {}  // Initialize id_pixel and id_vehicle to 0 here

    // Destructor invoke when object is going to be destroyed
    ~icon() {}

    //add pixel function which will add pixel into the array of container
    void addPixel(pixel add_pixel) {
        //the if was set so that the number is not more than 16 and warn the user that
        //the pixel is adding more than 16
        if (id_pixel < 16) {
            //set the location in array of container to be a pixel that pass in as an arguments
            container[id_pixel] = add_pixel;
            id_pixel++;
        } else {
            std::cout << "container is full";
        }
    }
    //display the detail of pixels
    void displayPixels() {
        for(int i = 0; i < id_pixel; i++) {  // Change 16 to id_pixel
            std::cout << "\nPixel " << i+1 << "\nX: " << container[i].x << "\nY: " << container[i].y << "\nBrightness: " << container[i].brightness;
        }
    }
};

//radarDisplay class will mainly focus on display icon that is also store pixels in it
class radarDisplay {
    public:
    int noActiveIcons;
    icon* iconsToDisplay[100];

    // Constructor which initialise number of active icons, for initial will be set to 0
    radarDisplay() : noActiveIcons(0) {}

    // Destructor invoke when object is going to be destroyed
    ~radarDisplay() {}

    //function to add icon to array of iconToDisplay
    void addIcon(icon* add_icon) {
        if (noActiveIcons < 100) {
            iconsToDisplay[noActiveIcons] = add_icon;
            noActiveIcons++;
        } else {
            //warn the user when there is more than 100 icon added
            std::cout << "Display is full";
        }
    }
    //This function will display details for icon that is stored in iconsToDisplay array
    void displayIcons() {
    for(int i = 0; i < noActiveIcons; i++) {
            std::cout << "\nIcon " << i+1 << "\nVehicle ID: " << (*iconsToDisplay[i]).id_vehicle;
            (*iconsToDisplay[i]).displayPixels(); //access the member of an object through pointer
        }
    }

};
//function to show the pixel details
void showPixelDetail(pixel &variable) {
    std::cout << variable.x << " " << variable.y << " " << variable.brightness;
}
//function to show the icon details
void showIconDetail(icon &variable) {
    std::cout << "\nID Vehicle " << variable.id_vehicle;
}
//function to show the pixel details
void initialiseAsDefaultDiagonalLine(icon & bigIcon) {
    for (int i = 1; i<= 15; i++) {
        pixel p;
        p.x = i;
        p.y = i;
        p.brightness = 15;
        bigIcon.addPixel(p);
    }
}
//function to define the icon called RedPlane which have unique value
void initialiseRedPlaneIcon(icon& anIcon) {
    anIcon.id_vehicle = 1;
    pixel p;
    p.x = 2.1;
    p.y = 0.1;
    p.brightness = 15;
    anIcon.addPixel(p);
}
//function to define the icon called yellow heli which have unique value
void initialiseYellowHeliIcon(icon& anIcon) {
    anIcon.id_vehicle = 3;
    pixel p;
    p.x = 4.2;
    p.y = 9.8;
    p.brightness = 15;
    anIcon.addPixel(p);
}

int main() {
    //testing adding and show pixel
    pixel aPixel;
    aPixel.x = 3.9;
    aPixel.y = 4.1;
    aPixel.brightness = 7;
    showPixelDetail(aPixel);

    icon myIcon;
    pixel pixelOne;
    pixelOne = aPixel;

    //testing new icon
    icon newIcon;
    newIcon.id_vehicle = 7;
    initialiseAsDefaultDiagonalLine(newIcon);
    showIconDetail(newIcon);

    icon allTheIcons[500];
    initialiseRedPlaneIcon(allTheIcons[0]);
    initialiseYellowHeliIcon(allTheIcons[1]);

    // Add the icons to the radar displays
    radarDisplay displayOne;
    radarDisplay displayTwo;
    displayOne.addIcon(&allTheIcons[0]); // Add the red plane icon to displayOne
    displayOne.addIcon(&allTheIcons[1]); // Add the yellow heli icon to displayOne
    displayTwo.addIcon(&allTheIcons[0]); // Add the red plane icon to displayTwo
    displayTwo.addIcon(&allTheIcons[1]); // Add the yellow heli icon to displayTwo

    // Display the icons and their pixels
    std::cout << "\nDisplayOne Icons and Pixels:";    
    displayOne.displayIcons();
    std::cout << "\nNumber of active icons in displayOne: " << displayOne.noActiveIcons;

    std::cout << "\nDisplayTwo Icons and Pixels:";
    displayTwo.displayIcons();
    std::cout << "\nNumber of active icons in displayTwo: " << displayTwo.noActiveIcons;
    return 0;
}

//---------------------------------------------TEST DATA 1 -----------------------------------------------------

// void initialiseRedPlaneIcon(icon& anIcon) {
//     anIcon.id_vehicle = 1;
//     pixel p;
//     p.x = 3.2;
//     p.y = 10.4;
//     p.brightness = 15;
//     anIcon.addPixel(p);
// }

// void initialiseYellowHeliIcon(icon& anIcon) {
//     anIcon.id_vehicle = 2;
//     pixel p;
//     p.x = 6.2;
//     p.y = 2.1;
//     p.brightness = 15;
//     anIcon.addPixel(p);
// }
// DisplayOne Icons and Pixels:
// Icon 1
// Vehicle ID: 1
// Pixel 1
// X: 3.2
// Y: 10.4
// Brightness: 15
// Icon 2
// Vehicle ID: 2
// Pixel 1
// X: 6.2
// Y: 2.1
// Brightness: 15
// Number of active icons in displayOne: 2
//-----------------------------------------------------------------------------------------------------------
//---------------------------------------------TEST DATA 2 -----------------------------------------------------
// void initialiseRedPlaneIcon(icon& anIcon) {
//     anIcon.id_vehicle = 1;
//     pixel p;
//     p.x = 2.1;
//     p.y = 0.1;
//     p.brightness = 15;
//     anIcon.addPixel(p);
// }

// void initialiseYellowHeliIcon(icon& anIcon) {
//     anIcon.id_vehicle = 3;
//     pixel p;
//     p.x = 4.2;
//     p.y = 9.8;
//     p.brightness = 15;
//     anIcon.addPixel(p);
// }
// DisplayOne Icons and Pixels:
// Icon 1
// Vehicle ID: 1
// Pixel 1
// X: 2.1
// Y: 0.1
// Brightness: 15
// Icon 2
// Vehicle ID: 3
// Pixel 1
// X: 4.2
// Y: 9.8
// Brightness: 15
// Number of active icons in displayOne: 2
//-----------------------------------------------------------------------------------------------------------
//---------------------------------------------TEST DATA PIXEL -----------------------------------------------------
// pixel aPixel;
// aPixel.x = 3.9;
// aPixel.y = 4.1;
// aPixel.brightness = 7;
// showPixelDetail(aPixel);

// 3.9 4.1 7
//-----------------------------------------------------------------------------------------------------------
//---------------------------------------------TEST DATA PIXEL 2 -----------------------------------------------------
// pixel aPixel;
// aPixel.x = 2.1;
// aPixel.y = 9.8;
// aPixel.brightness = 8;
// showPixelDetail(aPixel);

// 2.1 9.8 8
//-----------------------------------------------------------------------------------------------------------