## Component

The base class for every component attached to [Entity's](#entity)

### Properties

| Name   | Description                                    |
|--------|------------------------------------------------|
| Entity | The Entity which this component is attached to |


## Entity

The base class in which every Acrylic script derives from. When creating a new C# script, it must be a subclass of the Entity class.

### Properties

| Name        | Description                                                                   |
|-------------|-------------------------------------------------------------------------------|
| ID          | The unique universal ID (UUID) associated with the Entity created by Acrylic  |
| Translation | The position of the Entity in 3D space                                        |
| Rotation    | The rotation of the Entity in 3D space                                        |

### Functions

| Name         | Description                                                           |
|--------------|-----------------------------------------------------------------------|
| HasComponent | Returns true if the Entity has the specified component class attached |
| GetComponent | Gets the specified component attached to the Entity                   |


## Input

The interface for the Acrylic C# input system. Use this class to check for inputs from the user along with the mouse position.

Also read [KeyCode](#keycode) and [MouseCode](#mousecode) to see the lists of all the key and mouse options.

### Functions

| Name                 | Description                                                    |
|----------------------|----------------------------------------------------------------|
| IsKeyDown            | Returns true if the specified KeyCode is pressed               |
| IsMouseButtonPressed | Returns true if the specified MouseCode is pressed             |
| GetMousePosition     | Gets a Vector2 of the current mouse x and y position in pixels |
| GetMouseX            | Gets the current x position of the mouse in pixels             |
| GetMouseY            | Gets the current y position of the mouse in pixels             |

## KeyCode

KeyCode is a map of every physical key on the keyboard. Use these with the [Input.IsKeyDown](#input) function to detect key presses from the user.

```csharp
using System;
using Acrylic;

public class KeyCodeExample : Entity
{
    void OnUpdate(float ts)
    {
        if (Input.IsKeyDown(KeyCode.Space))
        {
            Console.WriteLine("The space key is pressed down");
        }
    }
}
```

### Properties

| Name         | Description                            |
|--------------|----------------------------------------|
| Space        | Space key " "                          |
| Apostrophe   | Apostrophe key "'"                     |
| Comma        | Comma key ","                          |
| Minus        | Minus key "-"                          |
| Period       | Period key "."                         |
| Slash        | Forward slash key "/"                  |
| D0           | The "0" key on the top of the keyboard |
| D1           | The "1" key on the top of the keyboard |
| D2           | The "2" key on the top of the keyboard |
| D3           | The "3" key on the top of the keyboard |
| D4           | The "4" key on the top of the keyboard |
| D5           | The "5" key on the top of the keyboard |
| D6           | The "6" key on the top of the keyboard |
| D7           | The "7" key on the top of the keyboard |
| D8           | The "8" key on the top of the keyboard |
| D9           | The "9" key on the top of the keyboard |
| Semicolon    | Semicolon key ";"                      |
| Equal        | Equal key "="                          |
| A            | "A" key                                |
| B            | "B" key                                |
| C            | "C" key                                |
| D            | "D" key                                |
| E            | "E" key                                |
| F            | "F" key                                |
| G            | "G" key                                |
| H            | "H" key                                |
| I            | "I" key                                |
| J            | "J" key                                |
| K            | "K" key                                |
| L            | "L" key                                |
| M            | "M" key                                |
| N            | "N" key                                |
| O            | "O" key                                |
| P            | "P" key                                |
| Q            | "Q" key                                |
| R            | "R" key                                |
| S            | "S" key                                |
| T            | "T" key                                |
| U            | "U" key                                |
| V            | "V" key                                |
| W            | "W" key                                |
| X            | "X" key                                |
| Y            | "Y" key                                |
| Z            | "Z" key                                |
| LeftBracket  | Left bracket key "["                   |
| Backslash    | Back slash key "\"                     |
| RightBracket | Right bracket key "]"                  |
| GraveAccent  | The grave key "`"                      |
| World1       | Non-US #1                              |
| World2       | Non-US #2                              |
| Escape       | The escape key                         |
| Enter        | The enter key                          |
| Tab          | The tab key                            |
| Backspace    | The backspace key                      |
| Insert       | The insert key                         |
| Delete       | The delete key                         |
| Right        | The right arrow key                    |
| Left         | The left arrow key                     |
| Down         | The down arrow key                     |
| Up           | The up arrow key                       |
| PageUp       | The page up key                        |
| PageDown     | The page down key                      |
| Home         | The home key                           |
| End          | The end key                            |
| CapsLock     | The caps lock key                      |
| ScrollLock   | The scroll lock key                    |
| NumLock      | The num lock key                       |
| PrintScreen  | The print screen key                   |
| Pause        | The pause key                          |
| F1           | F1 function key                        |
| F2           | F2 function key                        |
| F3           | F3 function key                        |
| F4           | F4 function key                        |
| F5           | F5 function key                        |
| F6           | F6 function key                        |
| F7           | F7 function key                        |
| F8           | F8 function key                        |
| F9           | F9 function key                        |
| F10          | F10 function key                       |
| F11          | F11 function key                       |
| F12          | F12 function key                       |
| F13          | F13 function key                       |
| F14          | F14 function key                       |
| F15          | F15 function key                       |
| F16          | F16 function key                       |
| F17          | F17 fucntion key                       |
| F18          | F18 function key                       |
| F19          | F19 function key                       |
| F20          | F20 function key                       |
| F21          | F21 function key                       |
| F22          | F22 function key                       |
| F23          | F23 function key                       |
| F24          | F24 function key                       |
| F25          | F25 function key                       |
| KP0          | Numeric keypad 0                       |
| KP1          | Numeric keypad 1                       |
| KP2          | Numeric keypad 2                       |
| KP3          | Numeric keypad 3                       |
| KP4          | Numeric keypad 4                       |
| KP5          | Numeric keypad 5                       |
| KP6          | Numeric keypad 6                       |
| KP7          | Numeric keypad 7                       |
| KP8          | Numeric keypad 8                       |
| KP9          | Numeric keypad 9                       |
| KPDecimal    | Numeric keypad "."                     |
| KPDivide     | Numeric keypad "/"                     |
| KPMultiply   | Numeric keypad "*"                     |
| KPSubtract   | Numeric keypad "-"                     |
| KPAdd        | Numeric keypad "+"                     |
| KPEnter      | Numeric keypad enter                   |
| KPEqual      | Numeric keypad "="                     |
| LeftShift    | The left shift key                     |
| LeftControl  | The left control key                   |
| LeftAlt      | The left alt key                       |
| LeftSuper    | The left super key                     |
| RightShift   | The right shift key                    |
| RightControl | The right control key                  |
| RightAlt     | The right alt key                      |
| RightSuper   | The right super key                    |
| Menu         | The menu key                           |

## MouseCode

MouseCode is a map of every physical button on the mouse. Use these with the [Input.IsMouseButtonPressed](#input) function to detect key presses from the user.

```csharp
using System;
using Acrylic;

public class MouseCodeExample : Entity
{
    void OnUpdate(float ts)
    {
        if (Input.IsMouseButtonPressed(MouseCode.ButtonLeft))
        {
            Console.WriteLine("The left mouse button is pressed down");
        }
    }
}
```

### Properties

| Name         | Description                        |
|--------------|------------------------------------|
| Button0      | Mouse button 0 (Also ButtonLeft)   |
| Button1      | Mouse button 1 (Also ButtonRight)  |
| Button2      | Mouse button 2 (Also ButtonMiddle) |
| Button3      | Mouse button 3                     |
| Button4      | Mouse button 4                     |
| Button5      | Mouse button 5                     |
| Button6      | Mouse button 6                     |
| Button7      | Mouse button 7                     |
| ButtonLast   | The last mouse button (Button7)    |
| ButtonLeft   | The left mouse button              |
| ButtonRight  | The right mouse button             |
| ButtonMiddle | The middle mouse button            |

## Rigidbody2DComponent


## SpriteRendererComponent


## TransformComponent


## Vector2


## Vector3


## Vector4