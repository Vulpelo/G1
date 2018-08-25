Game engine 
================================================
## Silnik graficzny
Wykorzystuje OpenGL który jest wbudowany w wykorzystywaną bibliotekę SFML. SFML upraszcza obsługę OpenGL'a.

Dokumentacja
===
## Klasy
* Object
* GameObject : Object
* Actor : GameObject
* Component
* Mesh : Component
* GameMap
* Vector2D
* MathFunctions
* ControlInput
* Collision
* SimpleShape
* Coordinate
* Transform
---
## **Object**
 Public Methods                     | Description
 -----------------------------------|-----------------------------------------------------------------------------------------
 `DestroyObject(float)`             | Destroys this Object in established time, or before next tick if time not specified
 `shouldBeDestroyed()`              | Return's boolean teling if this Object is going to be destroyed before next tick
 `get_wTransform()`                 | Return's world Transform
 `set_wTransform(Transform)`        | Sets world Transform
 `setWorldCoordinate(double,double)`| Sets world position
 `setWorldRotation(double)`         | Sets world rotation
 `&getComponents()`                 | Return's reference to container with all Object's Components 
 
 Public Messages            | Description
----------------------------|-----------------------------------------------------------------------------------------
 `startOverlaping(Object*)` | Called when some other's Object colliders just overlaped any of this Object's colliders 
 `isOverlaping(Object*)`    | Called when some of other's Object colliders is still overtaping this Object's colliders
 `endOverlaping(Object*)`   | Called when all other's Object Colliders exited all Colliders of this Object

## Funkcjonalności
1. Layers

        Warstwy pozwalają na zgrupowanie wielu objektów pod jedną nazwą. Ułatwia to np. czy dany obiekt może kolidować z innym.