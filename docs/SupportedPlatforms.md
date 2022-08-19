# Supported Platforms

Here are the details for the platforms the Acrylic currently supports.

If you cannot find your particular platform here that means that Acrylic does not currently (*and possibly will not ever*) support it.

You can also find out what IDEs/Toolchains aresupported by reading the [Supported Editors](#supported-editors) section.

## Fully Supported
This is a list of platforms that Acrylic has been built, run, and tested on. These platforms should work without and serious platform specific problems.

If you find any issues relating to one of these platforms. You can open an issue on Github here https://github.com/marc-cr1810/Acrylic-Engine/issues
 * Windows 10 (64-bit)
 * Windows 11 (64-bit)
> Currently Acrylic only supports 64-bit versions of Windows and it is unlikely that 32-bit version support will ever be added

## Unsupported Platforms
This is a list of platforms that Acrylic does not support and probably won't run on.
 * Windows 7
 * MacOS
 * Linux (*Planned to be eventually supported in the future*)
 * iOS
 * Android
 * Consoles (*Such as XBox, PS4, Switch, etc.*)

## Supported Editors

Acrylic should be able to support and IDE or toolchain that [Premake5](https://premake.github.io/) supports (You can view that list [here](https://premake.github.io/docs/Using-Premake/#using-premake-to-generate-project-files)). You can change the build action by changing **vs2022** inside of the **scripts/Win-GenProjects.bat** file to the appropriate action for your IDE/Toolchain. Be mindful though that the below list are the currently tested and working IDEs/Toolchains.
 * Visual Studio 2022
 * Visual Studio 2019