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

	sf::View& Camera::getView() {
		Vector2 pos = getWorldPosition();
		view.setCenter(sf::Vector2f(pos.x, pos.y));

		return view;
	}

	Camera::Camera() 
		: matchRatioWithWindow(true) {
		setSize(static_cast<float>(RenderProperties::getWindow().getSize().x),
				static_cast<float>(RenderProperties::getWindow().getSize().y));
	}

	Camera::Camera(const Vector2& size) 
		: matchRatioWithWindow(false) {
		setSize(size.x, size.y);
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

	void Camera::setZoom(float zoom)
	{
		this->zoom = zoom;
		view.zoom(this->zoom);
	}

	void Camera::setSize(float x, float y)
	{
		view.setSize(x, y);
		view.zoom(zoom);
	}

	Camera & Camera::operator=(const Camera & camera) {
		this->active = false;

		this->offset = camera.offset;

		return *this;
	}

	Camera::~Camera() {
		if (this->active) {
			removeFromActiveCameras();
		}
	}

}
