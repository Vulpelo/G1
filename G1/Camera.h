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

		bool active = false;
		
		sf::View view;
		sf::FloatRect viewRect;

		Vector2 offset;
		float zoom = 1.f;

		bool matchRatioWithWindow = true;
	
		void removeFromActiveCameras();
		sf::View& getView();

	public:
		Camera(const Vector2& size);

		bool isActive() const { return active; }
		void setActive(bool active);

		void setZoom(float zoom);
		void setSize(float x, float y);

		/// <summary>
		/// Is camera' view size matched with window
		/// By default ratio is matched
		/// </summary>
		bool getMatchSize() { return matchRatioWithWindow; };
		/// <summary>
		/// Set if camera's view size should be matched with window;
		/// By default ratio is matched
		/// </summary>
		void setMatchSize(bool matchRatio) { this->matchRatioWithWindow = matchRatio; };

		static const std::vector<Camera*> getActiveCameras() { return activeCameras; }

		Camera& operator=(const Camera& camera);

		~Camera();
	};

}
