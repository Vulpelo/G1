## Game engine 
#### Used libraries:
* SFML-2.3.2 32bit
#### IDE:
* Visual Studio 2015

Spis
=================================
1. Functionalities
	* Layer - for grouping GameObjects
	* SortingLayer - rendering order of GameObjects
	* overlap detection between GameObjects with colliders
2. Usable classes

---------------------------------------------------------------------------------------------------------------------

## 1. Functionalities
### Layer
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
	
### SortingLayer
Allowes to order GameObjects in which they should be rendered. GameObject in the lowerest layer is drawn first. With the highest is drawn last and will be on top of all rendered objects. If there are multiple GameObjects with the same SortingLayer will be drawn in order in which the they where added/created.
	
Usage:
	
	// GameObject* gameObject;
	int newSortingLayer = 5;
	gameObject->setSortingLayer(newSortingLayer);

---------------------------------------------------------------------------------------------------------------------
## 2. Classes
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
 
 Public Messages           	| Description
 -------------------------------|-----------------------------------------------------------------------------------------
 `startOverlaping(GameObject*)`	| Called when some other's Object colliders just overlaped any of this Object's colliders 
 `isOverlaping(GameObject*)`    | Called when some of other's Object colliders is still overtaping this Object's colliders
 `endOverlaping(GameObject*)`	| Called when all other's Object Colliders exited all Colliders of this Object

----------------------------------------------------------------------------------------------------------------------
