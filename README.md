# Input Tracker
This project is intended to track keyboard events visually for PC gamers. It is meant to be used as an overlay in OBS or any other broadcast software to display input on screen during gameplay streams/recordings. The project is written in C++ and uses SFML for graphics.

# Dependencies
In order to build the project, you'll need ```cmake version 3.25``` or higher as well as SFML installed.

## Windows
The CMake installer for Windows can be downloded [here](https://cmake.org/download/)
SFML will be pulled automatically when building the project for Windows

## Linux
Run the following to install CMake and SFML on Ubuntu
```bash
sudo snap install cmake --classic
sudo apt-get install libsfml-dev
```

# Building and Running the Project
Once you have the dependencies installed, you can build the project
```bash
mkdir build/
cd build
cmake ../ -G "Unix Makefiles"
make
```

Then you can run the executable
```bash
cd ../output/
./tracker
```

The running application should look like this
![alt text](https://raw.githubusercontent.com/BeckSM64/input-tracker/master/images/tracker-screenshot.png)
