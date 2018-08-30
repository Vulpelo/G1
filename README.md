Game engine 
================================================
## Silnik graficzny
Wykorzystuje OpenGL który jest wbudowany w wykorzystywaną bibliotekę SFML. SFML upraszcza obsługę OpenGL'a.

Spis
===
## Klasy
* Object
* GameObject : Object
* Actor : GameObject
* Player : Actor

* GameMap

* Component
* Mesh : Component

* SimpleShape
* ControlInput
* Collision

* MathFunctions
* Vector2D
* Coordinate
* Transform

---

# **Object**
 Protected Variables                 | Description
 ------------------------------------|-----------------------------------------------------------------------------------------
 `int layer`                         | Layers to which this Object belongs
 `Transform wTransform`              | World Transform of this Object
 `std::vector<Component*> components`| Vector of Components attached to Object

 Public Methods                      | Description
 ------------------------------------|-----------------------------------------------------------------------------------------
 `DestroyObject(float)`              | Destroys this Object in established time, or before next tick if time not specified
 `shouldBeDestroyed()`               | Return's boolean teling if this Object is going to be destroyed before next tick
 `get_wTransform()`                  | Return's world Transform
 `set_wTransform(Transform)`         | Sets world Transform
 `setWorldCoordinate(double,double)` | Sets world position
 `setWorldRotation(double)`          | Sets world rotation
 `&getComponents()`                  | Return's reference to container with all Object's Components 
 
 Public Messages           			 | Description
 ------------------------------------|-----------------------------------------------------------------------------------------
 `startOverlaping(Object*)` 		 | Called when some other's Object colliders just overlaped any of this Object's colliders 
 `isOverlaping(Object*)`    		 | Called when some of other's Object colliders is still overtaping this Object's colliders
 `endOverlaping(Object*)`   		 | Called when all other's Object Colliders exited all Colliders of this Object

---

# **GameObject** :inherates from Object

                            
---

# **Actor** :inherates from GameObject

 Protected Variables                 | Description
 ------------------------------------|-----------------------------------------------------------------------------------------
                                     |
 
 Public Methods             		 | Description
 ------------------------------------|-----------------------------------------------------------------------------------------
                            		 |

---

# **Player** :inherates from Actor

 Protected Variables                 | Description
 ------------------------------------|-----------------------------------------------------------------------------------------
                                     |
 
 Public Methods              		 | Description
 ------------------------------------|-----------------------------------------------------------------------------------------
                            		 |

-------------------------------------------------------------------------------------------------------------------------------------------------------
## Funkcjonalności
### Layer
   Each Object has int variable layer. Engine can have up to 32 different layers. Each layer is a seperate integer's bit (that is why up to 32 layers).
Layers are allowing to group many different Objects. That makes easier to, for example to check if some objects can colliding with others.

Checking layer:

	Object* object;
	if(object->layer & Layer::DEFAULT) {
		// 'if' is true  if object belongs to layer DEFAULT
	}

	if(object->layer & Layer::DEFAULT) {
		// 'if' is true  if object belongs to layer DEFAULT
	}

Creating/adding new layer

    int nLayer = Layer::DEFAULT; // Has only DEFAULT layer
    // adding new layer PLAYER
    nLayer |=  Layer::PLAYER; // now has layer DEFAULT and PLAYER
