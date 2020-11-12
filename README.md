# Vst3VisualStudioExample
A simple windows VST3 example plugin using Visual Studio

The is a sample Visual Studio project to build a simple VST3 plugin. It creates a plugin with a single parameter that performs a simple gain adjustment.

# Building

You will need to have CMake (https://cmake.org) installed.

From a shell, run the following:

```bash
git clone --recursive https://github.com/mikeoliphant/Vst3VisualStudioExample
cd Vst3VisualStudioExample
mkdir vstbuild
cd vstbuild
cmake.exe -G "Visual Studio 16 2019" -A x64 ../vst3sdk
cmake --build . --config Debug
cmake --build . --config Release
```

Then you can load "VST3Test.sln" in Visual Studio and build the plugin.
