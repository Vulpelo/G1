## G1 Game engine 
#### Implementation technology:
* C++17
* library [SFML-2.3.2 32bit](https://www.sfml-dev.org/)  
* library [boost-1.71.0](https://www.boost.org/)

#### Used IDE:
* [Visual Studio 2017](https://visualstudio.microsoft.com/products/)  

#### Compilation:
Download and link required libraries. 
##### Linking in Visual Studio: 
Project -> Properties -> C/C++ -> General -> AdditionalIncludeDirectories, add paths to libraries
`C:\path\to\library\boost_1_71_0;C:\path\to\library\SFML-2.3.2 32bit\include;`

Project -> Properties -> Linker -> General -> Additional Library Directories, add path to library
`C:\path\to\library\SFML-2.3.2 32bit\lib;`

Project -> Properties -> Linker -> Input, for debug configuration enter `sfml-audio-d.lib;sfml-graphics-d.lib;` and for release configuration add `sfml-audio.lib;sfml-graphics.lib;`

Project -> Properties -> C/C++ -> Language -> C++ Language Standard, make sure it is setted to `C++17 Standard`

### Architecture

Most basic class is a GameObject. It has properties like: transform, life time, activity, layer, and multiple methods to override. 

### Input/Output

Classes from the SFML library were used to operate the keyboard and mouse. They allow you to check which keyboard and mouse buttons are currently pressed and to retrieve the current position of the mouse cursor in relation to the upper left corner of the window.
The game engine contains a singleton class named ControlInput. During its initialization, you should pass the pointer to the application window, from which all events such as pressed keys on the keyboard, mouse position or window resizing will be captured. It is possible to check which keyboard or mouse button is currently pressed, and whether the selected button has just been pressed or released in a given frame. The function checking whether a given key has been pressed is particularly helpful when we want to call a given application code once, e.g. we want to jump with a character, but only once, after pressing the key.

### Collision

For collision detection, game engine uses colliders which may be circular or rectangular in shape. Depending on the type of collision between two game objects, the corresponding functions listed below are triggered. However, they only work when the colliders are non-physical, that is, physics algorithms are not applied to them. In this case, the "Overlappable" parameter in the collider should be set to false.
The functions that are triggered in the event of a collision are:
    • startOverlapping() – triggered when the collision of two different game objects in the game begins
    • isOverlapping() – triggered every time, when a game object is colliding with other game object
    • endOverlapping() – triggered when the game object has just stopped colliding with that object
The above functions are located in the game object (GameObject class). If we want to use a given function, it should be implemented.

### Physics

G1 uses colliders to verify physical objects. As mentioned in the "Collision" section, they are used to detect collisions. However, when setting the 'Overlappable' parameter to false, when two collidors with the same parameter from two different objects collide with each other, an algorithm will be executed that will prevent their further collision.
Objects with colliders are classified into two types: dynamic and static. A static object is one that does not move. Dynamic is one that has a Rigidbody component. Thanks to it, an object can move, has its own speed, mass and is influenced by the laws of physics, such as gravity. The fact that static objects cannot move means they cannot collide with another dynamic object, let alone a static one. Thus, for static objects, part of the computation can be omitted, thereby overall reducing the computation per frame.

### Rendering

To draw anything on the screen, create an instance of the drawing component and add it to the selected game object. Drawing components are all components that inherit from the Renderer class. Belong to them:
    • CircleRenderer - draws a circle on the screen with a given radius;
    • RectangleRenderer - draws a rectangle with the selected height and length;
    • Sprite - draws a texture on the rectangle area with the selected length and height. By default, the beginning of the texture starts in the upper left corner of the area. When the rectangle is smaller than the texture resolution, it is clipped to the size of the area. In case the texture has a lower resolution than the area on which it is to be drawn, the texture may be stretched or remain in its original size, but the rest of the area will be filled with the last pixels of the right and bottom edges of the texture.
Additionally, for classes inheriting from Renderer, you can set the displacement of the drawn element relative to the position of the game object. So you can add multiple drawing components to one game object.
If you use Sprite to draw a texture, remember to load the texture into memory then. The Assets class is used for this. It uses two classes from the SFML library: Texture, which is a memory representation of texture, and SoundBuffer, which is a sound representation. To load the texture, you must enter a path that is relative to the location of the compiled executable file. Alternatively, instead of the full path, you can use the abbreviated name that we will use when referring to the resource. This is especially useful for long paths with complicated names.
Ultimately, the game object should be added to the currently working map. At this point, with each map update, the selected shapes and / or textures will appear on the screen. They will be drawn in a place depending on the location of the game object.
As we know, the drawing order in 2D engines is important. So we should make sure that the background is drawn first, then the platforms on which we will move, and finally our character. For this purpose, the so-called sort layer (named in the engine as sortingLayer) of integer type. The layer determines the order: objects with the lowest number are drawn first, ending with those with the highest. However, when there are more objects with the same layer number (highly likely since by default each game object has a sort layer equal to zero), they are drawn in the order in which they were added to the map. Of course, the layer numbers can be changed at any time during engine operation.
In the case of components, it is not possible to directly change their drawing order while the engine is running. So when adding drawing components to an object, keep in mind the order in which they should be drawn. It is recommended to create a separate game object that will store all the drawing components, and then position it as a child to the main object that will be our character.

#### Camera

The camera, like any other component, must be added to the game object. However, its mode of operation is slightly different. Each camera created and activated is added to a static container. The engine module responsible for drawing takes cameras from the container and, depending on the settings of each camera, draws selected areas of the map.
Due to the fact that there can be more than one camera, we can display several different areas of the map simultaneously in one window. For example, in a cooperative game where we control two different characters. Each character is assigned a separate camera and the areas seen by the cameras are displayed in a window divided into two parts.
The camera can also be deactivated, i.e. it will not be taken into account when drawing map areas. This allows, for example, to have multiple cameras, each responsible for displaying a different area of the map instead of having one and manipulating its position.

#### UI - User Interface

The game engine also has simplified user interface support. First of all, it allows you to update the position of the object in relation to the current position of the camera. Thanks to this, objects will always be in the camera's field of view even after changing its position.
To create a simple interface, you need two components that are allocated to two different game objects:
    • Container - objects with this component must be at the beginning of the UI hierarchy tree. From the component, you can download the global corners of the displayed image for one of the selected cameras.
    • ContainerElement - objects with this component become UI element. Each such object must be a child of an object that has a Container component. ContainerElement manipulates the position of the game object so that its new position aligns with the point of the displayed area. The point can be one corner of the window, the center of the window, or half the distance between two corners of the screen.

### Animations

In the case of animations, support for stop motion animations has been implemented. A sprite sheet is used for this, in which each frame of the animation must be the same size and they must be arranged in one row, in the order of playback. To run a stop-motion animation in the engine, it is enough to use the so-called the SpriteAnimation class. It allows you to pause the animation, start, restart, set the display time for one frame, the number of frames and the start frame.
The same animation cannot be displayed with the same class. For this, the so-called component is required. Animator, i.e. a simple animation manager with a state machine. It allows you to manage multiple animations related to each other (e.g. walking, running, jumping animation) using a state machine. It defines which animations will be played and the criteria for transitions between specific animations.

### Audio

For sound handling, I used the Sound class from the SFML library. It allows you to load a music file and basic operations on it, such as starting playback, restarting, pausing, starting with a shift or looping. What's more, each SFML track that is running is played in a separate thread. This means that each song is independent and does not affect the operation of the main program code.
In the G1 engine, the Audio class is used to run songs. It allows you to run several tracks at the same time and loop them. Before running any song, you must first load it into memory. This is done with the Resources class, specifying the path to the music file and, alternatively, an abbreviated name. Same as for loading images.
Additionally, to make it easier to enjoy multiple audio tracks simultaneously, the G1 has an audio mixer. Thanks to it, it is possible to group sounds and manage their volume together. An example of using a mixer is having groups: music and dialogue. Naturally, we don't want the dialogues to be drowned out by the music. So before starting each dialogue, we turn down the volume of the music.

### Additional Functionalities

#### Loading level from xml file

Creating a map is one of the most time consuming and repetitive parts of creating a game. It is very easy to make a mistake when adding new features, such as setting them the wrong position on the map.
In G1, you can create objects and add them to the map directly in the application code. As a result, the amount of code increases rapidly with more complex maps. Thus, the code becomes unreadable and repetitive, with only a few differences between objects. Additionally, a recompilation of the application is required, even after a small change.
Therefore, the G1 engine offers the possibility of adding objects to the map saved in an xml file. Image and sound file paths can also be saved in the file. This solution means that recompilation of the program is not required. All you need to do is read the xml file again, i.e. reload the map using the map manager in the engine. Thus, it allows for faster creation of maps and prevents the creation of a large amount of similar code.
The xml file defines the list of game objects to be added to the map. Objects can be created from scratch, i.e. the entire object is defined only in the xml file. You can also use a previously created game object class in the engine. For example, in the game code, we defined the game object as the hero. It has its own components, variables and functions. To use it in an xml file, it must additionally inherit from the IPrefab interface and add it to the "list" of objects that can be added via the xml file. To add an object to the "list", you need to modify the getInstanceOf() function in the PrefabFameObjects class by adding three similar lines presented in the code to it.

```
if (prefabName == "MyGameObject") {
	return new MyGameObject(args);
}
```

Now in the xml file, when defining the game object we want to use, we give the name of our class (the game object using the class we created looks like this: <gameObject prefab = "Game Object">).
You can freely add predefined components to an object with any parameters, as well as modify the game object itself by setting its position or setting the layer to which it belongs. Additionally, if the object was created on the basis of the class, you can pass a list of arguments to the class constructor. Such a list is a map of names with values ​​assigned to them. The value can be integer, floating point, string, or true / false. The arguments are passed to the constructor as a map. The map key is the name of the variable and the value is a variable of one of four types.
As I mentioned, you can also enter paths to graphics and sound files. A short name for the file can also be specified in the xml file. However, it should be remembered that this name is then used in the application code. So when we refer to a file whose path was loaded from the xml file, we must give the name we defined there. In the case of textures, you can also set whether the texture should be in duplicate mode

```
<GameMap>
	<resources>
		<texture>
			<path>./assets/environment/tiles/grass_ul.png</path>
			<name>grass_ul</name>
			<repeted>true</repeted>
		</texture>
		...
	</resources>
	<gameObjects>
		<gameObject prefab="MapTile9">
			<args>
				<x type="int">-10</x>
				<y type="int">0</y>
				...
			</args>
		</gameObject>
		<gameObject>
			<transform>
				<position>
					<x>50</x>
					<y>-50</y>
				</position>
				<rotationX>0</rotationX>
				<scale>
					<x>1</x>
					<y>1</y>
				</scale>
			</transform>
			<components>
				<component type="sprite">
					<texture>bridgeEnd</texture>
					<imageSize>
						<x>30</x>
						<y>30</y>
					</imageSize>
					<startPosition>
						<x>0</x>
						<y>0</y>
					</startPosition>
				</component>
				<component type="rectangleCollider">
					<size>
						<x>50</x>
						<y>50</y>
					</size>
					<overlappable>false</overlappable>
					<physicMaterial>
						<friction>0</friction>
						<bounciness>1</bounciness>
						<frictionCombine>AVERAGE</frictionCombine>
						<bouncyCombine>MAXIMUM</bouncyCombine>
					</physicMaterial>
				</component>
				...
			</components>
		</gameObject>
		...
	</gameObjects>
</GameMap>

```

### Example game

Engine contains also a simple platformer game. 
To run it, in main.cpp file, simply initialize and start "ExamplePlatformerGame" class

```
int main()
{		
	using namespace G1;

	ExamplePlatformerGame engine;
	engine.start();

	return 0;
}
```

--------------------------------------------------------------------------------------------------------------------
## Classes documentation

#### Classes

[Map](#map)  
* [MapManager](#MapManager)  
* [GameMap](#GameMap)  
* [GameObject](#GameObject)  

[Rendering](#Rendering)  
* [RenderManager](#RenderManager)
* [Camera](#Camera)  
* [CircleRenderer](#CircleRenderer)  
* [RectangleRenderer](#RectangleRenderer)  
* [Sprite](#Sprite)  
* [Animator](#Animator)  
* [SpriteAnimation](#SpriteAnimation)

[Physics](#Physics)  
* [CircleCollider](#CircleCollider)  
* [RectangleCollider](#RectangleCollider)  
* [Rigidbody](#Rigidbody) 

[Other](#other)    
* [Assets](#Assets)  
* [Audio](#Audio)  
* [ControlInput](#ControlInput)
* [Time](#Time)  

#### Other engine functions
* [Layer](#layer)
* [SortingLayer](#SortingLayer)

--------------------------------------------------------------------------------------------------------------------

### Layer - for grouping GameObjects
   Each Object has enum Layer variable called layer. Engine can have up to 32 different layers. Each layer is a seperate integer's bit (that is why up to 32 layers).
Layers are allowing to group many different GameObjects. That makes easier to, for example to check if some objects can colliding with others.

Usage:

	// GameObject* gameObject;
	if( gameObject->isLayer(Layer::DEFAULT) ) {
		// true if gameObject belongs only to layer DEFAULT
	}

	int layers = Layer::DEFAULT | Layer::Layer3 | Layer::Layer4;
	if(object->inLayer(layers)) {
		// 'true if gameObject belongs to one of the given layers	
	}
	

---------------------------------------------------------------------------------------------------------------------
<a name="spawnableclasses"/>

## Map

### **GameObject** : inherits public Transformable, public ISpawnable

 Public Methods                      | Description
 ------------------------------------|-----------------------------------------------------------------------------------------
 `getLayer(): Layer` |
 `setLayer(Layer)` |
 `inLayer(int): bool` | Check if GameObject's layer is one of the given layers
 `isLayer(Layer): bool` | Check if those are the same layers
 `setSortingLayer(int)` | Sets sortingLayer
 `getSortingLayer(): int` | Returns actual SortingLayer
 `destroy(float = 0.0f)`              | Destroys this Object in established time, or before next tick if time not specified
 `shouldBeDestroyed(): bool`               | Return's boolean teling if this Object is going to be destroyed before next tick
`getComponents(): std::vector<Component*>&` | Return's reference to container with all GameObject's components
`template <class T> getComponents(): std::vector<Component*>*` | Return's list of components that inherite from given class
`template <class T> getComponent(): T*` | Return's first component in list of components that inherite from given class or NULL if no component found
 `addComponent(Component* component)` | Adds new component to GameObject
 `startPlay()` |
 `beginPlay()` |
 `eventTick()` |
 `fixedEventTick()` |
 
 Public Messages           	| Description
 -------------------------------|-----------------------------------------------------------------------------------------
 `startOverlaping(GameObject*)`	| Called when some other's Object colliders just overlaped any of this Object's colliders 
 `isOverlaping(GameObject*)`    | Called when some of other's Object colliders is still overtaping this Object's colliders
 `endOverlaping(GameObject*)`	| Called when all other's Object Colliders exited all Colliders of this Object

--------------------------------------------------------------------------------------------------------------------------

## Rendering

<a name="SortingLayer"/>

### SortingLayer - rendering order of GameObjects
Allowes to order GameObjects in which they should be rendered. GameObject in the lowerest layer is drawn first. With the highest is drawn last and will be on top of all rendered objects. If there are multiple GameObjects with the same SortingLayer will be drawn in order in which the they where added/created.
	
Usage:
	
	// GameObject* gameObject;
	int newSortingLayer = 5;
	gameObject->setSortingLayer(newSortingLayer);
	
---------------------------------------------------------------------------------------------------------------------

## Physics

### Rigidbody
An component, that gives control of na object's position. 
Used in physics calculations like new velocity direction on colision, fraction, bounce, gravity. When GameObject has Rigidbody then is considered as a dynamic object, otherwise as static.
