## Custom Binary Tree Application 
A console application implementing Dijkstra's shortest path algorithm.
- The app uses a pre-defined set of nodes. The graph is sketched and stored in the assets directory. 
- The console will output the shortest path to all nodes in the graph, using node 0 as the starting point. 
- Three of the shortest paths are sketched with a transparent background, and can be overlaid on the original graph sketch. They are stored as images in the assets directory.

### Dependencies
Have cmake installed, and accessible in your path (ie: you should be able to launch cmake from your terminal).


```bash
git clone https://github.com/glenngartner/shortest_path.git
```

### Run / Debug
If your IDE supports CMake configurations directly (using the CMakeLists.txt file), like Visual Studio 2017 or CLion, just open the project root folder in your IDE. You can then run or debug the app without running CMake. If you want to use XCode, Visual Studio with a .sln file, or another IDE, then generate your project files with cmake (next section).

### Generate Project Files
If you want to generate project files for your IDE of choice (Visual Studio solution, XCode, etc), and build from source, cd to the project root directory in your terminal. Then, change to the build directory, launch cmake, and direct cmake at the project root, like so:

```bash
{project_root}> cd build/
{project_root}/build> cmake .. # direct cmake up one directory, to the project root, where the CMakeLists.txt file resides
```

Cmake will generate project files, and deposit them in the build folder (or the folder you launched CMake from). Now you can open and compile the project in your IDE.

### Compile
Compile the project in your IDE. If you chose UNIX Makefiles during cmake configuration, then run make from the build directory: 
```bash
{project_root}/build> make .
``` 

### Binaries
If you don't want to build yourself, use the windows (.exe), OSX, or Linux binaries in the bin/ folder to run the app. 