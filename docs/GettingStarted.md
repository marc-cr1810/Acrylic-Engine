# Getting Started

This guide should hopefully get you started on how to build and run the Acrylic Engine. Make sure to read eveything and follow the guide correctly.
Do note that currently Acrylic can only be setup for **Visual Studio 2022** currently.

## Requirements

Here is a list of the third-party tools and SDKs required to be able to build and run Acrylic.
Make sure that you add everything except for the .NET Framework SDK to your PATH environment variable.
 - [Git](https://git-scm.com/downloads)
 - [Python 3](https://www.python.org/downloads/)
 - [Vulkan SDK](#vulkan)
 - [.NET Framework 4.7.2](#net-framework)

## Downloading the Repository

Start by cloning the repository with **git clone --recursive https://github.com/marc-cr1810/Acrylic-Engine**

If the repository was cloned non-recursively previously, use **git submodule update --init** clone the necessary submodules.

## Setting Up

After the repository is cloned, you can then proceed with the following.
 1. Run the **scripts/Setup.bat** file. This will download the required libraries and assist you with having everything setup.
    * One requirement is the Vulkan SDK. If you do not have this installed then please follow [this section](#vulkan) once the Vulkan installer shows up.
 2. Open the **Acrylic.sln** file to load Visual Studio 2022. By default **Acrylic-Editor** should be the startup program.
 3. Make sure to build **Acrylic-ScriptCore** as it is essential for scenes that use scripts to function.

## Building and Running

You should be able to now build and run Acrylic! Click the **Local Windows Debugger** button or press **F5** to build and debug the **Acrylic-Editor**.

## Vulkan

Acrylic requires the Vulkan SDK 1.3.x to be installed and you must have the **VULKAN_SDK** environment variable set to your installation path.
The setup script run in [Setting Up](#setting-up) will automatically download the Vulkan SDK installer and run it for you.

Once you have the Vulkan SDK installer open. You **must** install the *Debuggable Shader API Libraries - 64 bit* as these are required for Acrylic to build and run in it's Debug configuration. Without this, Debugging Acrylic will not work and it will not compile. You can only run the Release build of Acrylic.

![VulkanDebugLibs](/Images/VulkanDebugLibs.jpg)

You can also [download and install the Vulkan SDK](https://vulkan.lunarg.com/sdk/home) yourself if you choose to or if the setup scripts did not work correctly.

## .NET Framework

Acrylic uses C# as a scripting language, because of this a **Acrylic-ScriptCore** project is included which contains all of the Acrylic C# Scripting API. However this does mean that to build Acrylic you must have the .NET Framework SDK installed. Acrylic uses the .NET Framework 4.7.2 version.

If you do not have the .NET Framework installed, open the Visual Studio Installer program and click on the modify button. The next step is to select the ".NET desktop development" workload inside the "Workloads" tab.

![NETFrameworkWorkload](/Images/NETFrameworkWorkload.jpg)

You may be required to restart your computer after installing.

## Pulling the Latest Code

The **master** branch is required to be stable and there should be no build errors or major faults and you should always be able to get a working build of Acrylic with it. Regardless of branch, after pulling the latest code do make sure to re-run the **scripts/Setup.bat** file again to make sure any and all new files or configuration changes have been applied to your own local development environment.