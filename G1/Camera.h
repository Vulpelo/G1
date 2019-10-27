#pragma once

#include <SFML\Graphics\View.hpp>
#include <vector>

#include "Component.h"
#include "Vector2.h"

#include "RenderProperties.h"

namespace G1 {

	class Camera : public Component, public Transformable {
		friend class RenderManager;

		// All cameras that are rendering areas
		// Last camera in Vector is rendering last 
		// (View from camera will be on top)
		static std::vector<Camera*> activeCameras;

		bool active = false;
		
		sf::View view;
		float zoom = 1.f;
		bool matchRatioWithWindow = true;

		Vector2 offset;
	
		void removeFromActiveCameras();
		sf::View& getView();

	public:
		/// <summary>
		/// Camera's view size is matched with window size
		/// </summary>
		Camera();
		/// <summary>
		/// If you want to use custom size of view.
		/// </summary>
		/// <param name="size">Initial size of camera's view</param>
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
