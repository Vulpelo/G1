#pragma once

#include <SFML\Graphics\View.hpp>
#include <vector>

#include "Component.h"
#include "Vector2.h"


namespace G1 {

	class Camera : public Component, public Transformable {
		friend class RenderManager;

		// All cameras that are rendering areas
		// Last camera in Vector is rendering last 
		// (View from camera will be on top)
		static std::vector<Camera*> activeCameras;

		sf::FloatRect viewRect;
		Vector2 offset;

		bool active = false;
	
		void removeFromActiveCameras();
		sf::View getView();

	public:
		Camera(const Vector2& size);

		bool isActive() const { return active; }
		void setActive(bool active);

		static const std::vector<Camera*> getActiveCameras() { return activeCameras; }

		Camera& operator=(const Camera& camera);

		~Camera();
	};

}
