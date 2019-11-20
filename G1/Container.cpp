#include "Container.h"

namespace G1 {
	namespace Layout {
		void Container::mainEventTick()
		{
			Vector2 cameraPos = camera->getWorldPosition();

			((Transformable*)(getParent()))->setPosition(cameraPos);
		}

		Vector2 Container::anchorOffset(Anchor anchor)
		{
			Vector2 anchPos;

			switch (anchor)
			{
			case G1::Layout::Anchor::UP_LEFT:
				anchPos = Vector2(-camera->getView().getSize().x / 2.0f, -camera->getView().getSize().y / 2.0f);
				break;
			case G1::Layout::Anchor::UP:
				anchPos = Vector2(0.0f, -camera->getView().getSize().y / 2.0f);
				break;
			case G1::Layout::Anchor::UP_RIGHT:
				anchPos = Vector2(camera->getView().getSize().x / 2.0f, -camera->getView().getSize().y / 2.0f);
				break;
			case G1::Layout::Anchor::MIDDLE_LEFT:
				anchPos = Vector2(-camera->getView().getSize().x / 2.0f, 0.0f);
				break;
			case G1::Layout::Anchor::MIDDLE:
				anchPos = Vector2(0.0f, 0.0f);
				break;
			case G1::Layout::Anchor::MIDDLE_RIGHT:
				anchPos = Vector2(camera->getView().getSize().x / 2.0f, 0.0f);
				break;
			case G1::Layout::Anchor::DOWN_LEFT:
				anchPos = Vector2(-camera->getView().getSize().x / 2.0f, camera->getView().getSize().y / 2.0f);
				break;
			case G1::Layout::Anchor::DOWN:
				anchPos = Vector2(0.0f, camera->getView().getSize().y / 2.0f);
				break;
			case G1::Layout::Anchor::DOWM_RIGHT:
				anchPos = Vector2(camera->getView().getSize().x / 2.0f, camera->getView().getSize().y / 2.0f);
				break;
			default:
				break;
			}

			return anchPos;
		}

	}
}
