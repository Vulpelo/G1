#include "Camera.h"

namespace G1 {

	std::vector<Camera*> Camera::activeCameras;


	void Camera::removeFromActiveCameras() {
		for (size_t i = 0; i < activeCameras.size(); i++) {
			if (activeCameras.at(i) == this) {
				activeCameras.erase(activeCameras.begin() + i);
				break;
			}
		}
	}

	sf::View Camera::getView() {
		Vector2 pos = getWorldPosition();
		//viewRect.left = pos.x;
		//viewRect.top = pos.y;

		sf::View view(viewRect);
		view.setCenter(sf::Vector2f(pos.x, pos.y));

		return view;
	}

	Camera::Camera(const Vector2& size) {
		viewRect.left = 0.f;
		viewRect.top = 0.f;
		viewRect.width = size.x;
		viewRect.height = size.y;
	}

	void Camera::setActive(bool active) {
		if (!active && this->active) {
			removeFromActiveCameras();
		}
		else if (active && !this->active) {
			activeCameras.push_back(this);
		}
		this->active = active;
	}

	Camera & Camera::operator=(const Camera & camera) {
		this->active = false;

		this->viewRect = camera.viewRect;
		this->offset = camera.offset;

		return *this;
	}

	Camera::~Camera() {
		if (this->active) {
			removeFromActiveCameras();
		}
	}

}
