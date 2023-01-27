# Input Tracker
This project is intended to track keyboard events visually for pc gamers

# Building and Running the Project
## Windows
In order to build the project, you'll need ```cmake version 3.25``` or higher. Then you can build the project with the following commands
```bash
mkdir build/
cd build
cmake ../ -G "Unix Makefiles"
make
```

This will generate an executable along with the required resource files in the top level output directory
```
output/
    tracker.exe
    fonts/
        Arial.ttf
```

Then you can run the executable
```bash
./tracker
```

The running application should look like this
![alt text](https://raw.githubusercontent.com/BeckSM64/input-tracker/master/images/tracker-screenshot.png)
