# Scripting Concepts

Acrylic uses the [Mono runtime](https://www.mono-project.com/) for it's implementation of scripting in C#. This section of the documentation goes over how to create and use scripts in Acrylic.

## Creating and Using Scripts

Acrylic uses the C# programming language for its scripting.

### Creating Scripts

*Here will include the documentation of how to create scripts*

### The Script File

THe initial contents of a new script cile should look like this:

```csharp
using System;
using Acrylic;

public class NewScript : Entity
{
    void OnCreate()
    {
        
    }

    void OnUpdate(float ts)
    {
        
    }
}
```

Script files make their connecting with the internal workings of Acrylic (which is programmed in C++) through the implementation of the Entity class.

Take note of the two main functions defined inside the class. The **OnCreate** function is called by Acrylic before the gameplay begins and this is where you should do all of your initialization for your script. The **OnUpdate** function is called every frame for the **Entity**. Here you can do thing like movement, triggering actions and events, responses to the users input, etc. Really anything that needs to be handled udring gameplay over time. The **ts** variable in the **OnUpdate** function's arguments is the amount of time that has passed since the previous frame in **seconds** this can be very helpful for keeping various things such as movement speed and any custom physics consistent for different frame rates.

For experienced programmers, you might note that there is no default constructor and initlialization is done on the **OnCreate** function. This is because Acrylic handles the construction of objects internally and does not occur when gameplay starts as you would normally expect. **DO NOT** create a constructor to do your initialization as you will most likely cause major problems for your project.

### Simple Script Test

*Document here about how to attach scripts to an entity*

Once you have your script attached, you can do a simple test to see if it is working. You can easily check this just by printing something to the console. Add this code to the **OnCreate** function:

```csharp
void OnCreate()
{
    Console.WriteLine("Hello World!");
}
```

**Console.WriteLine** is a basic C# function that just prints a message to the console. This script should hopefully print how "Hello World!" to the console output.

## Important Classes

This section of the document goes over the most commonly used and important classes in Acylic that you most likely will use when scripting. This is only a brief overview of the classes containing only the main, commonly used members and does not cover all of the classes. For for imormation in regards to the C# classes and their members, have a look at the [Scripting API](/ScriptingAPI/About.md).

### Entity

The Entity class is the base class in which every Acrylic script derives from. It provides the base framework that allows you to attach the script to an Entity in the editor, along with creating the **OnCreate** and **OnUpdate** functions in which Acrylic calls to.

#### Events

Here are the common event functions that you can use in your script:

 * OnCreate - Called when the Entity is created (when the Scene is loaded when the game starts)
 * OnUpdate - Called every frame.